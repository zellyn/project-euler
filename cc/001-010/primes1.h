#ifndef PRIMES1_H
#define PRIMES1_H

#include <vector>
#include <math.h>

template <class T>
class Primes1 {
 public:
   Primes1() : last(1) {
     primes.push_back(2);
     primes.push_back(3);
   };
   T next() {
     if (last < 3) {
       ++last;
       return last;
     }
     while (true) {
       last += 2;
       int pos = 0;
       T limit = sqrt(last);
       while (true) {
         T p = primes[pos++];
         if (last % p == 0) {
           break;
         }
         if (p > limit) {
           primes.push_back(last);
           return last;
         }
       }
     }
     primes.push_back(3);
     return primes[0];
   }
 private:
   T last;
   std::vector<T> primes;
};

#endif  // PRIMES1_H
