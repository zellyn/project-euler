// Project Euler Problem 061
//
// Find the sum of the only set of six 4-digit figurate numbers with a
// cyclic property.

// 3-8

#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int Pgonal(int p, int n) {
  return n * ((p-2)*n + 4-p) / 2;
}

void Fill(int p, map<int, vector<pair<int, int> > >& m) {
  int n = 1;
  int pg;
  while ( (pg=Pgonal(p, n)) < 10000) {
    n++;
    if (pg >= 1000) {
      m[pg/100].push_back(pair<int, int>(p-3, pg));
    }
  }
}

int Sum(int sum, int finalEnding, int start, int unused, map<int, vector<pair<int, int> > >& pgonals, int level) {
  if (!unused) {
    if (finalEnding==start) return sum;
    else return 0;
  }
  vector<pair<int, int> > v = pgonals[start];
  vector<pair<int, int> >::const_iterator it;
  for (it=v.begin(); it!=v.end(); ++it) {
    int bit = 1 << it->first;
    if (unused & bit) {
      int p = it->second;
      int newSum = Sum(sum+p, finalEnding, p%100, unused ^ bit, pgonals, level + 1);
      if (newSum) return newSum;
    }
  }
  return 0;
}


int main(int argc, const char* argv[]) {
  map<int, vector<pair<int, int> > > pgonals;
  for (int p=3; p<8; p++) {
    Fill(p, pgonals);
  }
  int sum = 0;
  int n = 1;
  int pg;
  while ( (pg=Pgonal(8, n)) < 10000) {
    n++;
    if (pg >= 1000) {
      sum = Sum(pg, pg/100, pg%100, 31, pgonals, 1);
      if (sum) break;
    }
  }
  printf("%d\n", sum);
}
