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
typedef struct HexWave HexWave;
extern void hexwave_init(int width, int oversample, float *user_buffer);
extern void hexwave_shutdown(float *user_buffer);
extern void hexwave_create(HexWave *hex, int reflect, float peak_time, float half_height, float zero_wait);
extern void hexwave_change(HexWave *hex, int reflect, float peak_time, float half_height, float zero_wait);
extern void hexwave_generate_samples(float *output, int num_samples, HexWave *hex, float freq);
typedef struct
{
   int reflect;
   float peak_time;
   float zero_wait;
   float half_height;
} HexWaveParameters;
struct HexWave
{
   float t, prev_dt;
   HexWaveParameters current, pending;
   int have_pending;
   float buffer[64];
};
