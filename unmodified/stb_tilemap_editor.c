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
typedef struct stbte_tilemap stbte_tilemap;
enum
{
   STBTE_drawmode_deemphasize = -1,
   STBTE_drawmode_normal = 0,
   STBTE_drawmode_emphasize = 1,
};
extern stbte_tilemap *stbte_create_map(int map_x, int map_y, int map_layers, int spacing_x, int spacing_y, int max_tiles);
extern void stbte_define_tile(stbte_tilemap *tm, unsigned short id, unsigned int layermask, const char * category);
extern void stbte_set_display(int x0, int y0, int x1, int y1);
extern void stbte_draw(stbte_tilemap *tm);
extern void stbte_tick(stbte_tilemap *tm, float time_in_seconds_since_last_frame);
extern void stbte_mouse_sdl(stbte_tilemap *tm, const void *sdl_event, float xscale, float yscale, int xoffset, int yoffset);
extern void stbte_mouse_move(stbte_tilemap *tm, int x, int y, int shifted, int scrollkey);
extern void stbte_mouse_button(stbte_tilemap *tm, int x, int y, int right, int down, int shifted, int scrollkey);
extern void stbte_mouse_wheel(stbte_tilemap *tm, int x, int y, int vscroll);
enum stbte_action
{
   STBTE_tool_select,
   STBTE_tool_brush,
   STBTE_tool_erase,
   STBTE_tool_rectangle,
   STBTE_tool_eyedropper,
   STBTE_tool_link,
   STBTE_act_toggle_grid,
   STBTE_act_toggle_links,
   STBTE_act_undo,
   STBTE_act_redo,
   STBTE_act_cut,
   STBTE_act_copy,
   STBTE_act_paste,
   STBTE_scroll_left,
   STBTE_scroll_right,
   STBTE_scroll_up,
   STBTE_scroll_down,
};
extern void stbte_action(stbte_tilemap *tm, enum stbte_action act);
extern void stbte_get_dimensions(stbte_tilemap *tm, int *max_x, int *max_y);
extern short* stbte_get_tile(stbte_tilemap *tm, int x, int y);
extern float *stbte_get_properties(stbte_tilemap *tm, int x, int y);
extern void stbte_get_link(stbte_tilemap *tm, int x, int y, int *destx, int *desty);
extern void stbte_set_dimensions(stbte_tilemap *tm, int max_x, int max_y);
extern void stbte_clear_map(stbte_tilemap *tm);
extern void stbte_set_tile(stbte_tilemap *tm, int x, int y, int layer, signed short tile);
extern void stbte_set_property(stbte_tilemap *tm, int x, int y, int n, float val);
extern void stbte_set_link(stbte_tilemap *tm, int x, int y, int destx, int desty);
extern void stbte_set_background_tile(stbte_tilemap *tm, short id);
extern void stbte_set_sidewidths(int left, int right);
extern void stbte_set_spacing(stbte_tilemap *tm, int spacing_x, int spacing_y, int palette_spacing_x, int palette_spacing_y);
extern void stbte_set_layername(stbte_tilemap *tm, int layer, const char *layername);
