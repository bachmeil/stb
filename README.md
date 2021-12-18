# stb

Compilation of the stb libraries using ImportC

All but one of the files compiles with LDC. stb_easy_font returns

```
stb_easy_font.c(874): Error: `f` is not a member of `int`
stb_easy_font.c(892): Error: 3 extra initializer(s) for `struct __tag21`
```

Just because they compile doesn't mean they're correct. (ImportC is new,
so there's a higher chance of bugs than using gcc or clang.)

The file compile.d will do the preprocessing and compilation for you: `rdmd compile`.

## Partial fix for stb_easy_font.c

Line 874:

```
* (float *) (vbuf+offset+8) = 0.f;
```

becomes

```
* (float *) (vbuf+offset+8) = 0.0f;
```

Line 892

```
stb_easy_font_color c = { 255,255,255,255 };
```

becomes

```
stb_easy_font_color c;
c.c[0] = 255;
c.c[1] = 255;
c.c[2] = 255;
c.c[3] = 255;
```

There's a further problem due to ImportC not yet supporting C initializer lists.
Therefore I don't think this file is going to work with ImportC.
