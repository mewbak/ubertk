/*
ubertk is a flexible GUI toolkit targetted towards graphics applications.
Copyright (C) 2007 - 2018 John Tsiombikas <nuclear@member.fsf.org>,
                          Michael Georgoulopoulos <mgeorgoulopoulos@gmail.com>,
				          Kostas Michalopoulos <badsector@slashstone.com>

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
3. The name of the author may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
OF SUCH DAMAGE.
*/
#ifndef UTK_GFX_H_
#define UTK_GFX_H_

#include <utk_config.h>
#include <utk_types.h>

namespace utk {

	enum ArrowOrientation {
		ARROW_LEFT,
		ARROW_UP,
		ARROW_RIGHT,
		ARROW_DOWN
	};

	namespace gfx {
		typedef void (*ColorFunc)(int r, int g, int b, int a);
		typedef void (*ClipFunc)(int x1, int y1, int x2, int y2);
		typedef void (*ImageFunc)(int x, int y, const void *pix, int xsz, int ysz);
		typedef void (*RectFunc)(int x1, int y1, int x2, int y2);
		typedef void (*LineFunc)(int x1, int y1, int x2, int y2, int width);
		typedef void (*TextFunc)(int x, int y, const char *txt, int sz);
		typedef int (*TextSpacingFunc)();
		typedef int (*TextWidthFunc)(const char *txt, int sz);

		// graphics state
		extern UTK_API ColorFunc color;
		extern UTK_API ClipFunc clip;
		extern UTK_API ImageFunc image;

		// drawing calls
		extern UTK_API RectFunc rect;
		extern UTK_API LineFunc line;

		// text
		extern UTK_API TextFunc text;
		extern UTK_API TextSpacingFunc text_spacing;
		extern UTK_API TextWidthFunc text_width;

		// ---- high level drawing functions ----
		UTK_API void circle(int x1, int y1, int x2, int y2, bool outline);

		UTK_API void push_clip();
		UTK_API void pop_clip();
		UTK_API void set_clip(int x1, int y1, int x2, int y2);
		UTK_API void mult_clip(int x1, int y1, int x2, int y2);

		UTK_API void color_clamp(int r, int g, int b, int a);

		UTK_API void frame(int x1, int y1, int x2, int y2, int thickness = 1);

		enum {BEVEL_INSET = 1, BEVEL_FILLBG = 2};
		UTK_API void bevel(int x1, int y1, int x2, int y2, unsigned int flags = 0, int thickness = 1);

		UTK_API void arrow(int x, int y, ArrowOrientation orientation);
	}
}

#endif	// UTK_GFX_H_
