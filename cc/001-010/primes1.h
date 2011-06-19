#ifndef PRIMES1_H
#define PRIMES1_H

#include <utility>
#include <vector>
#include <math.h>

template <class T>
class Primes1 {
 public:
  Primes1() : last(5), size(3), counter(0) {
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
  };

  T next() {
    return get(counter++);
  }

  T get(size_t index) {
    while (size-1 <= index) {
      add();
    }
    return primes[index];
  }

  std::vector<std::pair<T, int> > factor(T product) {
    std::vector<std::pair<T, int> > vec;
    T limit = sqrt(product);
    size_t index = 0;
    while (product > 1) {
      T prime = get(index++);
      if (prime > limit) {
        vec.push_back(std::make_pair(product, 1));
        return vec;
      }
      if (product % prime == 0) {
        int count = 0;
        while (product % prime == 0) {
          count++;
          product = product / prime;
        }
        vec.push_back(std::make_pair(prime, count));
      }
    }
    return vec;
  }

 private:
  T add() {
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
           size++;
           return last;
         }
       }
     }
   }

 private:
  T last;
   size_t size;
   size_t counter;
   std::vector<T> primes;
};

#endif  // PRIMES1_H
