// Project Euler Problem 044
//
// Find the smallest pair of pentagonal numbers whose sum and
// difference is pentagonal.

#include <cstdio>
#include <vector>
#include <set>

using namespace std;

void generate_to(long limit, size_t length, vector<long>& v, set<long>& s) {
  size_t n = v.size() + 1;
  long p;
  do {
    p = n * (3*n-1) / 2;
    v.push_back(p);
    s.insert(p);
    n++;
  } while (p < limit || n <= length);
}

int main(int argc, const char* argv[]) {
  vector<long> v;
  set<long> s;
  generate_to(100, 10, v, s);
  long n2 = 1;
  while (true) {
    n2++;
    generate_to(1, n2, v, s);
    long p2 = v[n2];
    for (long n1=0; n1<n2; n1++) {
      long p1 = v[n1];
      long diff = p2-p1;
      if (!s.count(diff)) continue;
      long sum = p2+p1;
      generate_to(sum, 1, v, s);
      if (s.count(sum)) {
        printf("%ld\n", diff);
        exit(0);
      }
    }
  }
}
