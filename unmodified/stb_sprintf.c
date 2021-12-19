typedef struct
{
  unsigned long long low;
  long long high;
} __int128_t;
typedef struct
{
    unsigned gp_offset;
    unsigned fp_offset;
    void *overflow_arg_area;
    void *reg_save_area;
} __va_list_tag;
typedef __va_list_tag __builtin_va_list[1];
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
typedef long int ptrdiff_t;
typedef long unsigned int size_t;
typedef int wchar_t;
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;
typedef char *STBSP_SPRINTFCB(const char *buf, void *user, int len);
extern int stbsp_vsprintf(char *buf, char const *fmt, va_list va);
extern int stbsp_vsnprintf(char *buf, int count, char const *fmt, va_list va);
extern int stbsp_sprintf(char *buf, char const *fmt, ...) __attribute__((format(printf,2,3)));
extern int stbsp_snprintf(char *buf, int count, char const *fmt, ...) __attribute__((format(printf,3,4)));
extern int stbsp_vsprintfcb(STBSP_SPRINTFCB *callback, void *user, char *buf, char const *fmt, va_list va);
extern void stbsp_set_separators(char comma, char period);
