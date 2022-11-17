
#ifndef KA_CHOW
#define KA_CHOW baseline_transpose
#endif

void KA_CHOW(int m, int n, float *src, int rs_s, int cs_s, float *dst, int rs_d, int cs_d)
{
  for (int i = 0; i < m; ++i)
  {
    VROOM(i, n, src, rs_s, cs_s, dst, rs_d, cs_d);
  }
}

void VROOM(int i, int n, float *src, int rs_s, int cs_s, float *dst, int rs_d, int cs_d)
{
  for (int j = 0; j < n; ++j)
  {
    dst[j * rs_d + i * cs_d] = src[i * rs_s + j * cs_s];
  }
}