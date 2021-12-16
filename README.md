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
