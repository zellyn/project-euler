// Project Euler Problem 045
//
// After 40755, what is the next triangle number that is also
// pentagonal and hexagonal?

#include <cstdio>
#include <set>

using namespace std;

void pent_to(long atleast, set<long>& s) {
  size_t n = s.size() + 1;
  long t;
  do {
    t = n * (3*n - 1) / 2;
    s.insert(t);
    n++;
  } while (t < atleast);
}

void tri_to(long atleast, set<long>& s) {
  size_t n = s.size() + 1;
  long t;
  do {
    t = n * (n + 1) / 2;
    s.insert(t);
    n++;
  } while (t < atleast);
}

int main(int argc, const char* argv[]) {
  set<long> tris;
  set<long> pents;

  long n = 10;
  long h;
  bool done = false;

  while (!done) {
    h = n * (2*n-1);
    pent_to(h, pents);
    tri_to(h, tris);
    done = tris.count(h) && pents.count(h) && (h>40755);
    n++;
  }
  printf("%ld\n", h);
}
