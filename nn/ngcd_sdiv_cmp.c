#include "ccas.h"
#include "nn.h"

int nn_ngcd_sdiv_cmp(nn_src_t a, int_t m, nn_src_t b, int_t n, int_t s)
{
   CCAS_ASSERT(m >= n);
   CCAS_ASSERT(s > 0);
   CCAS_ASSERT(n >= s);

   TMP_INIT;

   if (m > n + 1)
      return 1;

   if (m > n && a[m - 1] > 1)
      return 1;

   TMP_START;

   nn_t t = (nn_t) TMP_ALLOC(m*sizeof(uint_t));
      
   nn_sub(t, a, m, b, n);
   n = nn_normalise(t, m);

   return n > s ? 1 : n == s ? 0 : -1;
   
   TMP_END;
}

