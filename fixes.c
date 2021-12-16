/* Use the preprocessor to translate alternate keywords
   into more standard conventions.  */
#define __FUNCTION__ __func__
#define __alignof   _Alignof
#define __alighof__ _Alignof
#define __asm       asm
#define __asm__     asm
#define __attribute __attribute__
#define __auto_type auto
#define __complex   _Complex
#define __complex__ _Complex
#define __const     const
#define __const__   const
#define __extension__ /* nothing */
#define __inline    inline
#define __inline__  inline
#define __restrict  restrict
#define __restrict__ restrict
#define __signed    signed
#define __signed__  signed
#define __thread    _Thread_local
#define __volatile  volatile
#define __volatile__ volatile
/* ISO/IEC TS 18661-3:2015 definitions.  */
#ifdef __FLT_MANT_DIG__
#define _Float32    float
#endif
#ifdef __FLT64_MANT_DIG__
#define _Float64    double
#endif
#ifdef __FLT128_MANT_DIG__
/* This isn't strictly correct, but on x86 all that differs between
   80-bit vs. 128-bit is padding.  */
#define _Float128   long double
#endif
#ifdef __FLT32X_MANT_DIG__
#define _Float32x   double
#endif
#ifdef __FLT64X_MANT_DIG__
#define _Float64x   long double
#endif
#ifdef __FLT128X_MANT_DIG__
#error "unsupported"
#endif
/* C11 J.5.6 __int128 type.  */
typedef struct
{
  unsigned long long low;
  long long high;
} __int128_t;
/* Replace GCC built-ins with the corresponding type or expression.  */
#define __builtin_bswap16(x) \
    ((u_int16_t) ((((x) >> 8) & 0xff) | (((x) & 0xff) << 8)))
#define __builtin_bswap32(x) \
    ((((x) & 0xff000000u) >> 24) | (((x) & 0x00ff0000u) >> 8) \
     | (((x) & 0x0000ff00u) << 8) | (((x) & 0x000000ffu) << 24))
#define __builtin_bswap64(x) \
    ((((x) & 0xff00000000000000ull) >> 56) \
     | (((x) & 0x00ff000000000000ull) >> 40) \
     | (((x) & 0x0000ff0000000000ull) >> 24) \
     | (((x) & 0x000000ff00000000ull) >> 8) \
     | (((x) & 0x00000000ff000000ull) << 8) \
     | (((x) & 0x0000000000ff0000ull) << 24) \
     | (((x) & 0x000000000000ff00ull) << 40) \
     | (((x) & 0x00000000000000ffull) << 56))
/* Provide user declarations of the built-in va_list type.  */
#if defined(__i386__)
typedef char* __builtin_va_list;
#elif defined(__x86_64__)
typedef struct
{
    unsigned gp_offset;
    unsigned fp_offset;
    void *overflow_arg_area;
    void *reg_save_area;
} __va_list_tag;
typedef __va_list_tag __builtin_va_list[1];
#else
#error "unsupported"
#endif
