#include <cassert>
#include <vector>

#include "factored.h"
#include "primes1.h"

Factored::Factored(int i) {
  assert(i >= 1);
  Primes1<int> primes;
  while (i != 1) {
    int prime = primes.next();
    int count = 0;
    while (i % prime == 0) {
      ++count;
      i /= prime;
    }
    factors.push_back(count);
  }
}

Factored::Factored(vector<int>& from_factors) : factors(from_factors) { }

void Factored::print() const {
  printf("[");
  bool first = true;
  for (size_t i = 0; i < factors.size(); ++i) {
    if (first) {
      first = false;
    } else {
      printf(",");
    }
    printf("%d", factors[i]);
  }
  printf("]\n");
}

const Factored operator*(const Factored& left,
                         const Factored& right) {
  const vector<int> *longer = &left.factors;
  const vector<int>* shorter = &right.factors;
  if (longer->size() < shorter->size()) {
    const vector<int>* temp = longer;
    longer = shorter;
    shorter = temp;
  }
  vector<int> factors(*longer);
  for (int i = shorter->size() - 1; i >= 0; --i) {
    factors[i] += (*shorter)[i];
  }

  return Factored(factors);
}

const Factored operator/(const Factored& left,
                         const Factored& right) {
  const vector<int> *f1 = &left.factors;
  const vector<int> *f2 = &right.factors;
  assert(f1->size() >= f2->size());
  vector<int> factors;
  for (size_t i = 0; i < f1->size(); ++i) {
    int diff = (*f1)[i];
    if (i < f2->size()) {
      diff -= (*f2)[i];
    }
    assert(diff >= 0);
    factors.push_back(diff);
  }

  while (!factors[factors.size() - 1]) {
    factors.pop_back();
  }

  return Factored(factors);
}

bool operator==(const Factored& left,
               const Factored& right) {
  return (left.factors == right.factors);
}

bool operator>(const Factored& left,
              const int right) {
  Primes1<int> primes;
  int total = 1;
  vector<int>::const_iterator i;
  for (i = left.factors.begin(); i != left.factors.end(); ++i) {
    int prime = primes.next();
    for (int j = 0; j < *i; ++j) {
      total *= prime;
      if (total > right) {
        return true;
      }
    }
  }
  return false;
}
