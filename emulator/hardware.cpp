// *********************************************************************************************
// *********************************************************************************************
//
//		Name:		hardware.cpp
//		Purpose:	Hardware Interface
//		Date:		1st October 2017
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *********************************************************************************************
// *********************************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include "sys_processor.h"
#include "hardware.h"
#include "gfx.h"																


// *********************************************************************************************
//											Hardware Reset
// *********************************************************************************************

void HWIReset(void) {
}

// *********************************************************************************************
//											End of frame code.
// *********************************************************************************************

void HWIEndFrame() {
}


BYTE8 HWIGetDisplayDigit(BYTE8 digit) {
	return digit + ((digit & 1) ? 16 : 0);
}

