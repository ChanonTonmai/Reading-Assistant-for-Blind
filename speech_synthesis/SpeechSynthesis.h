/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#ifndef _SpeechSynthesis_H_INCLUDED
#define _SpeechSynthesis_H_INCLUDED

#include <stdio.h>
#include <Arduino.h>
#include <avr/pgmspace.h>



class SpeechSynthesisClass {
public:
 
  static void mvm(char sr[],byte cmd,char a[]);
  static void king(byte a,byte b,char c[]);
  static void at(byte x[],byte n);
  static void att(byte xx[],byte n);
  static void Speaking(byte cmda ,byte cmdb,byte cmdc,byte c[]);
  static void mking(byte a,byte b,byte c[]);
  static void Chinese_english(byte ax[],byte bm[],int n,byte cmd,char c[]);
  static void buf_init(byte ay[]);
  static void Espeaking(byte cmda ,byte cmdb,byte cmdc,byte c[]);
  static void kxing(byte a,byte b,byte c[]);
  static void Em_init(char ay[]);
  static void English(byte ax[],byte cmd,char c[]);
};

extern SpeechSynthesisClass SpeechSynthesis;

#endif
