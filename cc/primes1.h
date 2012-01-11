#ifndef PRIMES1_H
#define PRIMES1_H

#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

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

  vector<pair<T, int> > prime_factors(T product) {
    vector<pair<T, int> > vec;
    T limit = sqrt(product);
    size_t index = 0;
    while (product > 1) {
      T prime = get(index++);
      if (prime > limit) {
        vec.push_back(make_pair(product, 1));
        return vec;
      }
      if (product % prime == 0) {
        int count = 0;
        while (product % prime == 0) {
          count++;
          product = product / prime;
        }
        vec.push_back(make_pair(prime, count));
      }
    }
    return vec;
  }

  int num_divisors(T product) {
    vector<pair<T, int> > v = prime_factors(product);
    int num = 1;
    typename vector<pair<T, int> >::iterator it;
    for(it = v.begin(); it != v.end(); ++it) {
      int count = it->second;
      num *= (count+1);
    }
    return num;
  }

  vector<T> divisors(T product) {
    vector<T> vec;
    vec.push_back(1);
    vector<pair<T, int> > primes = prime_factors(product);

    typename vector<pair<T, int> >::iterator it;
    for(it = primes.begin(); it != primes.end(); ++it) {
      T prime = it->first;
      int count = it->second;
      T mult = 1;
      size_t l = vec.size();
      for (int i=0; i<count; i++) {
        mult *= prime;
        for (size_t j=0; j<l; j++) {
          vec.push_back(vec[j] * mult);
        }
      }
    }
    vec.pop_back();
    return vec;
  }

  int sum_divisors(T i) {
    vector<T> d = divisors(i);
    T sum = 0;
    for (vector<int>::iterator it = d.begin(); it != d.end(); it++) {
      sum += *it;
    }
    return sum;
  }

  bool is_prime(T candidate) {
    while (last < candidate) {
      add();
    }
    if (last==candidate) {
      return true;
    }
    return binary_search(primes.begin(), primes.end(), candidate);
  }

  bool lazy_is_prime(T candidate) {
    if (last >= candidate) return is_prime(candidate);
    T s = sqrt(candidate);
    while (last < s+2) {
      add();
    }
    typename vector<T>::iterator it;
    for (it = primes.begin(); it != primes.end(); ++it) {
      if (*it > s) return true;
      if (candidate % *it == 0) return false;
    }
    return false;
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
   vector<T> primes;
};

#endif  // PRIMES1_H
