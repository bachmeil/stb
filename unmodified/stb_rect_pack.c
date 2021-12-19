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
typedef struct stbrp_context stbrp_context;
typedef struct stbrp_node stbrp_node;
typedef struct stbrp_rect stbrp_rect;
typedef int stbrp_coord;
extern int stbrp_pack_rects (stbrp_context *context, stbrp_rect *rects, int num_rects);
struct stbrp_rect
{
   int id;
   stbrp_coord w, h;
   stbrp_coord x, y;
   int was_packed;
};
extern void stbrp_init_target (stbrp_context *context, int width, int height, stbrp_node *nodes, int num_nodes);
extern void stbrp_setup_allow_out_of_mem (stbrp_context *context, int allow_out_of_mem);
extern void stbrp_setup_heuristic (stbrp_context *context, int heuristic);
enum
{
   STBRP_HEURISTIC_Skyline_default=0,
   STBRP_HEURISTIC_Skyline_BL_sortHeight = STBRP_HEURISTIC_Skyline_default,
   STBRP_HEURISTIC_Skyline_BF_sortHeight
};
struct stbrp_node
{
   stbrp_coord x,y;
   stbrp_node *next;
};
struct stbrp_context
{
   int width;
   int height;
   int align;
   int init_mode;
   int heuristic;
   int num_nodes;
   stbrp_node *active_head;
   stbrp_node *free_head;
   stbrp_node extra[2];
};
