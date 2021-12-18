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
extern int stb_div_trunc(int value_to_be_divided, int value_to_divide_by);
extern int stb_div_floor(int value_to_be_divided, int value_to_divide_by);
extern int stb_div_eucl (int value_to_be_divided, int value_to_divide_by);
extern int stb_mod_trunc(int value_to_be_divided, int value_to_divide_by);
extern int stb_mod_floor(int value_to_be_divided, int value_to_divide_by);
extern int stb_mod_eucl (int value_to_be_divided, int value_to_divide_by);
