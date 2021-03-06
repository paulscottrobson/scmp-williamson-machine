// *********************************************************************************************
// *********************************************************************************************
//
//		Name:		hardware.h
//		Purpose:	Hardware Interface (header)
//		Date:		1st October 2017
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *********************************************************************************************
// *********************************************************************************************

#ifndef _HARDWARE_H
#define _HARDWARE_H
	
void  HWIReset(void);
BYTE8 HWIGetDisplayDigit(BYTE8 digit);
void  HWIEndFrame(void);

#endif
