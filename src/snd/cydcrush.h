#ifndef CYDCRUSH_H
#define CYDCRUSH_H

/*
Copyright (c) 2009-2010 Tero Lindeman (kometbomb)

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/

#include "SDL.h"

typedef struct
{
	int sample_rate;
#ifdef STEREOOUTPUT
	Sint32 hold_r, hold_l;
#else
	Sint32 hold;
#endif
	int counter, bit_drop, downsample;
} CydCrush;

#ifdef STEREOOUTPUT
void cydcrush_output(CydCrush *crush, Sint32 in_l, Sint32 in_r, Sint32 *out_l, Sint32 *out_r);
#else
Sint32 cydcrush_output(CydCrush *crush, Sint32 input);
#endif

void cydcrush_set(CydCrush *crush, int downsample /* 1 = original, 2 = half rate etc. */, int bit_drop);

void cydcrush_init(CydCrush *crush, int sample_rate);
void cydcrush_deinit(CydCrush *crush);

#endif