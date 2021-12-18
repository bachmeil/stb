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
typedef struct stbhw_tileset stbhw_tileset;
extern const char *stbhw_get_last_error(void);
extern int stbhw_build_tileset_from_image(stbhw_tileset *ts,
                     unsigned char *pixels, int stride_in_bytes, int w, int h);
extern void stbhw_free_tileset(stbhw_tileset *ts);
extern int stbhw_generate_image(stbhw_tileset *ts, int **weighting,
                     unsigned char *pixels, int stride_in_bytes, int w, int h);
typedef struct
{
   signed char a,b,c,d,e,f;
   unsigned char pixels[1];
} stbhw_tile;
struct stbhw_tileset
{
   int is_corner;
   int num_color[6];
   int short_side_len;
   stbhw_tile **h_tiles;
   stbhw_tile **v_tiles;
   int num_h_tiles, max_h_tiles;
   int num_v_tiles, max_v_tiles;
};
typedef struct
{
   int is_corner;
   int short_side_len;
   int num_color[6];
   int num_vary_x;
   int num_vary_y;
   int corner_type_color_template[4][4];
} stbhw_config;
extern void stbhw_get_template_size(stbhw_config *c, int *w, int *h);
extern int stbhw_make_template(stbhw_config *c, unsigned char *data, int w, int h, int stride_in_bytes);
