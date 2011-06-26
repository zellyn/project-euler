// Project Euler Problem 039
//
// If p is the perimeter of a right angle triangle, {a, b, c}, which
// value, for p ≤ 1000, has the most solutions?

#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

int main(int argc, const char* argv[]) {
  map<int, int> counts;
  int maxlen = 0;
  int max = 0;
  for (int i=1; i<=333; i++) {
    for (int j=i; j<=(1000-i)/2; j++) {
      double k = sqrt(i*i+j*j);
      int ijk = i+j+(int)k;
      if (floor(k) == k && ijk <= 1000) {
        counts[ijk] += 1;
        if (counts[ijk] > max) {
          max = counts[ijk];
          maxlen = ijk;
        }
      }
    }
  }
  printf("%d\n", maxlen);
}
