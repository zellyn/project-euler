// Project Euler Problem 043
//
// Find the sum of all pandigital numbers with an unusual sub-string
// divisibility property.

#include <cstdio>
#include "mymath.h"

// Ugly as sin, but it works! :-)
int main(int argc, const char* argv[]) {
  long sum = 0;
  for (long d890 = 0; d890<1000; d890 += 17) {
    long dig890 = digits(d890, 3);
    if (dig890<0) continue;
    for (long d7=0; d7<=9; d7++) {
      long dig7 = 1<<d7;
      if (dig7&dig890) continue;
      long d789 = d7*100 + d890/10;
      if (d789 % 13) continue;
      long dig7890 = dig890 | dig7;
      for (long d6=0; d6<=9; d6+=5) {
        long dig6 = 1<<d6;
        if (dig6&dig7890) continue;
        long d678 = d6*100 + d789/10;
        if (d678 % 11) continue;
        long dig67890 = dig6 | dig7890;
        for (long d5=0; d5<=9; d5++) {
          long dig5 = 1<<d5;
          if (dig5 & dig67890) continue;
          long d567 = d5*100 + d678/10;
          if (d567%7) continue;
          long dig567890 = dig5 | dig67890;
          for (long d4=0; d4<=9; d4+=2) {
            long dig4 = 1<<d4;
            if (dig4&dig567890) continue;
            long d456 = d4*100 + d567/10;
            long dig4567890 = dig4 | dig567890;
            for (long d123=102; d123<=987; d123++) {
              long dig123 = digits(d123, 3);
              if (dig123<0) continue;
              if (dig123&dig4567890) continue;
              if (((d123%10) * 100 + d456/10) % 3) continue;
              sum = sum + ((d123 * 1000 + d456) * 10 + d7) * 1000 + d890;
            }
          }
        }
      }
    }
  }
  printf("%ld\n", sum);
}
