#include <pthread.h>
#include <stdlib.h>

#ifndef KA_CHOW
#define KA_CHOW baseline_transpose
#endif

// Struct for bundling argument
typedef struct
{
  int i;
  int n;
  float *src;
  int rs_s;
  int cs_s;
  float *dst;
  int rs_d;
  int cs_d;
} args;

void VROOM(void *deez_args)
{
  args *args = deez_args; // Isn't C neat?

  // Transpose the row
  for (int j = 0; j < args->n; ++j)
  {
    args->dst[j * args->rs_d + args->i * args->cs_d] = args->src[args->i * args->rs_s + j * args->cs_s];
  }
}

void KA_CHOW(int m, int n, float *src, int rs_s, int cs_s, float *dst, int rs_d, int cs_d)
{
  // Create an array to keep track of thread ids
  pthread_t *tids = malloc(sizeof(pthread_t) * m);

  // Bundle arguments
  args args;
  args.n = n;
  args.src = src;
  args.rs_s = rs_s;
  args.cs_s = cs_s;
  args.dst = dst;
  args.rs_d = rs_d;
  args.cs_d = cs_d;

  // Create threads and pass them the proper arguments
  for (int i = 0; i < m; ++i)
  {
    args.i = i;
    pthread_create(&tids[i], NULL, VROOM, (void *)args);
  }

  // Join threads
  for (int i = 0; i < m; ++i)
  {
    pthread_join(tids[m], NULL);
  }
}