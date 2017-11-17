// *********************************************************************************************
// *********************************************************************************************
//
//		Name:		sys_processor.cpp
//		Purpose:	Processor Emulation.
//		Created:	26th October 2015
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *********************************************************************************************
// *********************************************************************************************

#include <stdio.h>
#include "sys_processor.h"
#include "hardware.h"

#define cycles_PER_SECOND 	(2000000)
#define FRAMES_PER_SECOND	(60)
#define cycles_PER_FRAME 	(cycles_PER_SECOND / FRAMES_PER_SECOND)

// *********************************************************************************************
//												CPU Memory
// *********************************************************************************************

static BYTE8 memory[4096];

#define READ() 	mbr = memory[mar & 0xFFF]
#define WRITE() memory[mar & 0xFFF] = mbr

// *********************************************************************************************
//												CPU Registers
// *********************************************************************************************

static BYTE8 ac,e,status,cyl,ov,delay4cycles,t8,mbr;
static WORD16 p0,p1,p2,p3,cycles,t16,mar	;

// *********************************************************************************************
//													CPU Reset
// *********************************************************************************************

void CPUReset(void) {
	ac = e = p0 = p1 = p2 = p3 = cyl = status = ov = 0;
	cycles = 0;delay4cycles = 0;
	HWIReset();
}

// *********************************************************************************************
//												  CPU Support Functions
// *********************************************************************************************

#define serialIn() 		(0)
#define serialOut(b) 	{}
#define setFlags(v) 	{}
#define senseA() 		(0)
#define senseB() 		(0)


static void _CPUExecuteOne(void) {
	switch(t8) {																// Do the selected opcode and phase.
		#include "__scmp_case.h"
	}
}

// *********************************************************************************************
//											Execute a single instruction phase
// *********************************************************************************************

#include <stdlib.h>
#include <stdio.h>

BYTE8 CPUExecuteInstruction(void) {

	if (delay4cycles == 0) {
		mar = p0 = (p0 + 1) & 0xFFFF;READ();t8 = mbr;
		if (t8 == 0x8F) {
			mar = (p0+1);READ();
			if (mbr % 3 == 0) {
				while (mbr > 0) {
					mbr = mbr - 3;
					// Next scan pulse
				}
			}
		}
		_CPUExecuteOne();
	}

	if (delay4cycles != 0) {														// DLY in progress
		WORD16 remcycles = cycles_PER_FRAME - cycles;								// cycles left this frame
		if (remcycles/4 < delay4cycles) {											// Not enough cycles
			delay4cycles = delay4cycles - remcycles / 4;
			cycles = 0;
			return FRAMES_PER_SECOND;
		} else {																	// enough this time.
			cycles = cycles + delay4cycles * 4;
			delay4cycles = 0;
		}
	}


	if (cycles < cycles_PER_FRAME) return 0;										// Frame in progress, return 0.
	cycles -= cycles_PER_FRAME;														// Adjust cycle counter
	HWIEndFrame();																	// Hardware stuff.
	return FRAMES_PER_SECOND;														// Return the frame rate for sync speed.
}

#ifdef INCLUDE_DEBUGGING_SUPPORT

// *********************************************************************************************
//										 Get the step over breakpoint value
// *********************************************************************************************

WORD16 CPUGetStepOverBreakpoint(void) {
	BYTE8 opcode = CPURead(p0+1);													// Read opcode.
	if ((opcode & 0xFC) == 0x3C) return ((p0+1) & 0xFFFF);							// XPPC Px
	return 0xFFFF;
}

// *********************************************************************************************
//										Run continuously till breakpoints / Halt.
// *********************************************************************************************

BYTE8 CPUExecute(WORD16 break1,WORD16 break2) {
	BYTE8 rate = 0;
	while(1) {
		rate = CPUExecuteInstruction();												// Execute one instruction phase.
		if (rate != 0) {															// If end of frame, return rate.
			return rate;													
		}
		if (p0+1 == break1 || p0+1 == break2) return 0;
	} 																				// Until hit a breakpoint or HLT.
}

// *********************************************************************************************
//												Load a binary file into RAM
// *********************************************************************************************

void CPULoadBinary(char *fileName) {
	if (fileName != NULL) {
		FILE *f = fopen(fileName,"rb");
		fread(memory,4096,1,f);
		fclose(f);
	}
}

// *********************************************************************************************
//												Gets a pointer to RAM memory
// *********************************************************************************************
	
BYTE8 CPURead(WORD16 address) {
	mar = address;READ();return mbr;
}

// *********************************************************************************************
//											Retrieve a snapshot of the processor
// *********************************************************************************************

static CPUSTATUS s;																	// Status area

CPUSTATUS *CPUGetStatus(void) {
	t8 = 0x0F;_CPUExecuteOne();
	s.a = ac;s.e = e;s.s = status;
	s.pc = p0;s.p0 = p0;s.p1 = p1;s.p2 = p2;s.p3 = p3;
	s.cycles = cycles;																// Number of cycles.
	return &s;
}
#endif
