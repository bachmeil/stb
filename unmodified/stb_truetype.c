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
   unsigned char *data;
   int cursor;
   int size;
} stbtt__buf;
typedef struct
{
   unsigned short x0,y0,x1,y1;
   float xoff,yoff,xadvance;
} stbtt_bakedchar;
extern int stbtt_BakeFontBitmap(const unsigned char *data, int offset,
                                float pixel_height,
                                unsigned char *pixels, int pw, int ph,
                                int first_char, int num_chars,
                                stbtt_bakedchar *chardata);
typedef struct
{
   float x0,y0,s0,t0;
   float x1,y1,s1,t1;
} stbtt_aligned_quad;
extern void stbtt_GetBakedQuad(const stbtt_bakedchar *chardata, int pw, int ph,
                               int char_index,
                               float *xpos, float *ypos,
                               stbtt_aligned_quad *q,
                               int opengl_fillrule);
extern void stbtt_GetScaledFontVMetrics(const unsigned char *fontdata, int index, float size, float *ascent, float *descent, float *lineGap);
typedef struct
{
   unsigned short x0,y0,x1,y1;
   float xoff,yoff,xadvance;
   float xoff2,yoff2;
} stbtt_packedchar;
typedef struct stbtt_pack_context stbtt_pack_context;
typedef struct stbtt_fontinfo stbtt_fontinfo;
typedef struct stbrp_rect stbrp_rect;
extern int stbtt_PackBegin(stbtt_pack_context *spc, unsigned char *pixels, int width, int height, int stride_in_bytes, int padding, void *alloc_context);
extern void stbtt_PackEnd (stbtt_pack_context *spc);
extern int stbtt_PackFontRange(stbtt_pack_context *spc, const unsigned char *fontdata, int font_index, float font_size,
                                int first_unicode_char_in_range, int num_chars_in_range, stbtt_packedchar *chardata_for_range);
typedef struct
{
   float font_size;
   int first_unicode_codepoint_in_range;
   int *array_of_unicode_codepoints;
   int num_chars;
   stbtt_packedchar *chardata_for_range;
   unsigned char h_oversample, v_oversample;
} stbtt_pack_range;
extern int stbtt_PackFontRanges(stbtt_pack_context *spc, const unsigned char *fontdata, int font_index, stbtt_pack_range *ranges, int num_ranges);
extern void stbtt_PackSetOversampling(stbtt_pack_context *spc, unsigned int h_oversample, unsigned int v_oversample);
extern void stbtt_PackSetSkipMissingCodepoints(stbtt_pack_context *spc, int skip);
extern void stbtt_GetPackedQuad(const stbtt_packedchar *chardata, int pw, int ph,
                               int char_index,
                               float *xpos, float *ypos,
                               stbtt_aligned_quad *q,
                               int align_to_integer);
extern int stbtt_PackFontRangesGatherRects(stbtt_pack_context *spc, const stbtt_fontinfo *info, stbtt_pack_range *ranges, int num_ranges, stbrp_rect *rects);
extern void stbtt_PackFontRangesPackRects(stbtt_pack_context *spc, stbrp_rect *rects, int num_rects);
extern int stbtt_PackFontRangesRenderIntoRects(stbtt_pack_context *spc, const stbtt_fontinfo *info, stbtt_pack_range *ranges, int num_ranges, stbrp_rect *rects);
struct stbtt_pack_context {
   void *user_allocator_context;
   void *pack_info;
   int width;
   int height;
   int stride_in_bytes;
   int padding;
   int skip_missing;
   unsigned int h_oversample, v_oversample;
   unsigned char *pixels;
   void *nodes;
};
extern int stbtt_GetNumberOfFonts(const unsigned char *data);
extern int stbtt_GetFontOffsetForIndex(const unsigned char *data, int index);
struct stbtt_fontinfo
{
   void * userdata;
   unsigned char * data;
   int fontstart;
   int numGlyphs;
   int loca,head,glyf,hhea,hmtx,kern,gpos,svg;
   int index_map;
   int indexToLocFormat;
   stbtt__buf cff;
   stbtt__buf charstrings;
   stbtt__buf gsubrs;
   stbtt__buf subrs;
   stbtt__buf fontdicts;
   stbtt__buf fdselect;
};
extern int stbtt_InitFont(stbtt_fontinfo *info, const unsigned char *data, int offset);
extern int stbtt_FindGlyphIndex(const stbtt_fontinfo *info, int unicode_codepoint);
extern float stbtt_ScaleForPixelHeight(const stbtt_fontinfo *info, float pixels);
extern float stbtt_ScaleForMappingEmToPixels(const stbtt_fontinfo *info, float pixels);
extern void stbtt_GetFontVMetrics(const stbtt_fontinfo *info, int *ascent, int *descent, int *lineGap);
extern int stbtt_GetFontVMetricsOS2(const stbtt_fontinfo *info, int *typoAscent, int *typoDescent, int *typoLineGap);
extern void stbtt_GetFontBoundingBox(const stbtt_fontinfo *info, int *x0, int *y0, int *x1, int *y1);
extern void stbtt_GetCodepointHMetrics(const stbtt_fontinfo *info, int codepoint, int *advanceWidth, int *leftSideBearing);
extern int stbtt_GetCodepointKernAdvance(const stbtt_fontinfo *info, int ch1, int ch2);
extern int stbtt_GetCodepointBox(const stbtt_fontinfo *info, int codepoint, int *x0, int *y0, int *x1, int *y1);
extern void stbtt_GetGlyphHMetrics(const stbtt_fontinfo *info, int glyph_index, int *advanceWidth, int *leftSideBearing);
extern int stbtt_GetGlyphKernAdvance(const stbtt_fontinfo *info, int glyph1, int glyph2);
extern int stbtt_GetGlyphBox(const stbtt_fontinfo *info, int glyph_index, int *x0, int *y0, int *x1, int *y1);
typedef struct stbtt_kerningentry
{
   int glyph1;
   int glyph2;
   int advance;
} stbtt_kerningentry;
extern int stbtt_GetKerningTableLength(const stbtt_fontinfo *info);
extern int stbtt_GetKerningTable(const stbtt_fontinfo *info, stbtt_kerningentry* table, int table_length);
   enum {
      STBTT_vmove=1,
      STBTT_vline,
      STBTT_vcurve,
      STBTT_vcubic
   };
   typedef struct
   {
      short x,y,cx,cy,cx1,cy1;
      unsigned char type,padding;
   } stbtt_vertex;
extern int stbtt_IsGlyphEmpty(const stbtt_fontinfo *info, int glyph_index);
extern int stbtt_GetCodepointShape(const stbtt_fontinfo *info, int unicode_codepoint, stbtt_vertex **vertices);
extern int stbtt_GetGlyphShape(const stbtt_fontinfo *info, int glyph_index, stbtt_vertex **vertices);
extern void stbtt_FreeShape(const stbtt_fontinfo *info, stbtt_vertex *vertices);
extern unsigned char *stbtt_FindSVGDoc(const stbtt_fontinfo *info, int gl);
extern int stbtt_GetCodepointSVG(const stbtt_fontinfo *info, int unicode_codepoint, const char **svg);
extern int stbtt_GetGlyphSVG(const stbtt_fontinfo *info, int gl, const char **svg);
extern void stbtt_FreeBitmap(unsigned char *bitmap, void *userdata);
extern unsigned char *stbtt_GetCodepointBitmap(const stbtt_fontinfo *info, float scale_x, float scale_y, int codepoint, int *width, int *height, int *xoff, int *yoff);
extern unsigned char *stbtt_GetCodepointBitmapSubpixel(const stbtt_fontinfo *info, float scale_x, float scale_y, float shift_x, float shift_y, int codepoint, int *width, int *height, int *xoff, int *yoff);
extern void stbtt_MakeCodepointBitmap(const stbtt_fontinfo *info, unsigned char *output, int out_w, int out_h, int out_stride, float scale_x, float scale_y, int codepoint);
extern void stbtt_MakeCodepointBitmapSubpixel(const stbtt_fontinfo *info, unsigned char *output, int out_w, int out_h, int out_stride, float scale_x, float scale_y, float shift_x, float shift_y, int codepoint);
extern void stbtt_MakeCodepointBitmapSubpixelPrefilter(const stbtt_fontinfo *info, unsigned char *output, int out_w, int out_h, int out_stride, float scale_x, float scale_y, float shift_x, float shift_y, int oversample_x, int oversample_y, float *sub_x, float *sub_y, int codepoint);
extern void stbtt_GetCodepointBitmapBox(const stbtt_fontinfo *font, int codepoint, float scale_x, float scale_y, int *ix0, int *iy0, int *ix1, int *iy1);
extern void stbtt_GetCodepointBitmapBoxSubpixel(const stbtt_fontinfo *font, int codepoint, float scale_x, float scale_y, float shift_x, float shift_y, int *ix0, int *iy0, int *ix1, int *iy1);
extern unsigned char *stbtt_GetGlyphBitmap(const stbtt_fontinfo *info, float scale_x, float scale_y, int glyph, int *width, int *height, int *xoff, int *yoff);
extern unsigned char *stbtt_GetGlyphBitmapSubpixel(const stbtt_fontinfo *info, float scale_x, float scale_y, float shift_x, float shift_y, int glyph, int *width, int *height, int *xoff, int *yoff);
extern void stbtt_MakeGlyphBitmap(const stbtt_fontinfo *info, unsigned char *output, int out_w, int out_h, int out_stride, float scale_x, float scale_y, int glyph);
extern void stbtt_MakeGlyphBitmapSubpixel(const stbtt_fontinfo *info, unsigned char *output, int out_w, int out_h, int out_stride, float scale_x, float scale_y, float shift_x, float shift_y, int glyph);
extern void stbtt_MakeGlyphBitmapSubpixelPrefilter(const stbtt_fontinfo *info, unsigned char *output, int out_w, int out_h, int out_stride, float scale_x, float scale_y, float shift_x, float shift_y, int oversample_x, int oversample_y, float *sub_x, float *sub_y, int glyph);
extern void stbtt_GetGlyphBitmapBox(const stbtt_fontinfo *font, int glyph, float scale_x, float scale_y, int *ix0, int *iy0, int *ix1, int *iy1);
extern void stbtt_GetGlyphBitmapBoxSubpixel(const stbtt_fontinfo *font, int glyph, float scale_x, float scale_y,float shift_x, float shift_y, int *ix0, int *iy0, int *ix1, int *iy1);
typedef struct
{
   int w,h,stride;
   unsigned char *pixels;
} stbtt__bitmap;
extern void stbtt_Rasterize(stbtt__bitmap *result,
                               float flatness_in_pixels,
                               stbtt_vertex *vertices,
                               int num_verts,
                               float scale_x, float scale_y,
                               float shift_x, float shift_y,
                               int x_off, int y_off,
                               int invert,
                               void *userdata);
extern void stbtt_FreeSDF(unsigned char *bitmap, void *userdata);
extern unsigned char * stbtt_GetGlyphSDF(const stbtt_fontinfo *info, float scale, int glyph, int padding, unsigned char onedge_value, float pixel_dist_scale, int *width, int *height, int *xoff, int *yoff);
extern unsigned char * stbtt_GetCodepointSDF(const stbtt_fontinfo *info, float scale, int codepoint, int padding, unsigned char onedge_value, float pixel_dist_scale, int *width, int *height, int *xoff, int *yoff);
extern int stbtt_FindMatchingFont(const unsigned char *fontdata, const char *name, int flags);
extern int stbtt_CompareUTF8toUTF16_bigendian(const char *s1, int len1, const char *s2, int len2);
extern const char *stbtt_GetFontNameString(const stbtt_fontinfo *font, int *length, int platformID, int encodingID, int languageID, int nameID);
enum {
   STBTT_PLATFORM_ID_UNICODE =0,
   STBTT_PLATFORM_ID_MAC =1,
   STBTT_PLATFORM_ID_ISO =2,
   STBTT_PLATFORM_ID_MICROSOFT =3
};
enum {
   STBTT_UNICODE_EID_UNICODE_1_0 =0,
   STBTT_UNICODE_EID_UNICODE_1_1 =1,
   STBTT_UNICODE_EID_ISO_10646 =2,
   STBTT_UNICODE_EID_UNICODE_2_0_BMP=3,
   STBTT_UNICODE_EID_UNICODE_2_0_FULL=4
};
enum {
   STBTT_MS_EID_SYMBOL =0,
   STBTT_MS_EID_UNICODE_BMP =1,
   STBTT_MS_EID_SHIFTJIS =2,
   STBTT_MS_EID_UNICODE_FULL =10
};
enum {
   STBTT_MAC_EID_ROMAN =0, STBTT_MAC_EID_ARABIC =4,
   STBTT_MAC_EID_JAPANESE =1, STBTT_MAC_EID_HEBREW =5,
   STBTT_MAC_EID_CHINESE_TRAD =2, STBTT_MAC_EID_GREEK =6,
   STBTT_MAC_EID_KOREAN =3, STBTT_MAC_EID_RUSSIAN =7
};
enum {
   STBTT_MS_LANG_ENGLISH =0x0409, STBTT_MS_LANG_ITALIAN =0x0410,
   STBTT_MS_LANG_CHINESE =0x0804, STBTT_MS_LANG_JAPANESE =0x0411,
   STBTT_MS_LANG_DUTCH =0x0413, STBTT_MS_LANG_KOREAN =0x0412,
   STBTT_MS_LANG_FRENCH =0x040c, STBTT_MS_LANG_RUSSIAN =0x0419,
   STBTT_MS_LANG_GERMAN =0x0407, STBTT_MS_LANG_SPANISH =0x0409,
   STBTT_MS_LANG_HEBREW =0x040d, STBTT_MS_LANG_SWEDISH =0x041D
};
enum {
   STBTT_MAC_LANG_ENGLISH =0 , STBTT_MAC_LANG_JAPANESE =11,
   STBTT_MAC_LANG_ARABIC =12, STBTT_MAC_LANG_KOREAN =23,
   STBTT_MAC_LANG_DUTCH =4 , STBTT_MAC_LANG_RUSSIAN =32,
   STBTT_MAC_LANG_FRENCH =1 , STBTT_MAC_LANG_SPANISH =6 ,
   STBTT_MAC_LANG_GERMAN =2 , STBTT_MAC_LANG_SWEDISH =5 ,
   STBTT_MAC_LANG_HEBREW =10, STBTT_MAC_LANG_CHINESE_SIMPLIFIED =33,
   STBTT_MAC_LANG_ITALIAN =3 , STBTT_MAC_LANG_CHINESE_TRAD =19
};
