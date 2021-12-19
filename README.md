# stb

Compilation of the stb libraries using ImportC

Directory `unmodified` holds the C files after running them through the preprocessor.
All but stb_easy_font.c compile with DMD and LDC.

Those files were created using compile.d: `rdmd compile`.

## Partial fix for stb_easy_font.c

`manual/` holds stb_easy_font.c with some manual changes.

Line 875: `* (float *) (vbuf+offset+8) = 0.f;` changed to `* (float *) (vbuf+offset+8) = 0.0f;`

Line 893: `stb_easy_font_color c = { 255,255,255,255 };` changed to `stb_easy_font_color c = { { 255,255,255,255 } };`

I commented out `stb_easy_font_print` and `stb_easy_font_width` because
DMD and LDC throw errors about not supporting C initializer lists.
There's probably an easy solution, but I'll let someone else decide what that is.

Otherwise all other functions in stb compile.
