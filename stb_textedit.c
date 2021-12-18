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
typedef struct
{
   int where;
   int insert_length;
   int delete_length;
   int char_storage;
} StbUndoRecord;
typedef struct
{
   StbUndoRecord undo_rec [99];
   int undo_char[999];
   short undo_point, redo_point;
   int undo_char_point, redo_char_point;
} StbUndoState;
typedef struct
{
   int cursor;
   int select_start;
   int select_end;
   unsigned char insert_mode;
   int row_count_per_page;
   unsigned char cursor_at_end_of_line;
   unsigned char initialized;
   unsigned char has_preferred_x;
   unsigned char single_line;
   unsigned char padding1, padding2, padding3;
   float preferred_x;
   StbUndoState undostate;
} STB_TexteditState;
typedef struct
{
   float x0,x1;
   float baseline_y_delta;
   float ymin,ymax;
   int num_chars;
} StbTexteditRow;
