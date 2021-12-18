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
   char *input_stream;
   char *eof;
   char *parse_point;
   char *string_storage;
   int string_storage_len;
   char *where_firstchar;
   char *where_lastchar;
   long token;
   double real_number;
   long int_number;
   char *string;
   int string_len;
} stb_lexer;
typedef struct
{
   int line_number;
   int line_offset;
} stb_lex_location;
extern void stb_c_lexer_init(stb_lexer *lexer, const char *input_stream, const char *input_stream_end, char *string_store, int store_length);
extern int stb_c_lexer_get_token(stb_lexer *lexer);
extern void stb_c_lexer_get_location(const stb_lexer *lexer, const char *where, stb_lex_location *loc);
enum
{
   CLEX_eof = 256,
   CLEX_parse_error,
   CLEX_intlit ,
   CLEX_floatlit ,
   CLEX_id ,
   CLEX_dqstring ,
   CLEX_sqstring ,
   CLEX_charlit ,
   CLEX_eq ,
   CLEX_noteq ,
   CLEX_lesseq ,
   CLEX_greatereq ,
   CLEX_andand ,
   CLEX_oror ,
   CLEX_shl ,
   CLEX_shr ,
   CLEX_plusplus ,
   CLEX_minusminus ,
   CLEX_pluseq ,
   CLEX_minuseq ,
   CLEX_muleq ,
   CLEX_diveq ,
   CLEX_modeq ,
   CLEX_andeq ,
   CLEX_oreq ,
   CLEX_xoreq ,
   CLEX_arrow ,
   CLEX_eqarrow ,
   CLEX_shleq, CLEX_shreq,
   CLEX_first_unused_token
};
