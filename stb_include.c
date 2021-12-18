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
char *stb_include_string(char *str, char *inject, char *path_to_includes, char *filename_for_line_directive, char error[256]);
char *stb_include_strings(char **strs, int count, char *inject, char *path_to_includes, char *filename_for_line_directive, char error[256]);
char *stb_include_file(char *filename, char *inject, char *path_to_includes, char error[256]);
