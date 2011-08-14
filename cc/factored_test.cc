#include <cassert>
#include <vector>

#include "factored.h"
#include "primes1.h"

using namespace std;

void test_multiply() {
  Factored a(17);
  Factored b(3);
  Factored c(3*17);
  Factored d = a * b;
  assert(c == d);
  assert(c > 50);
  assert(d > 50);
  assert(c > 40);
  assert(c > 2);
  assert(!(a==b));
  assert(!(c > 51));
  assert(!(d > 51));
}

void test_divide() {
  Factored a(16);
  Factored b(8);
  Factored c(2);

  assert(a/b == c);
  assert(a/c == b);

  vector<int> v1;
  v1.push_back(8);
  v1.push_back(4);
  v1.push_back(2);
  v1.push_back(1);
  vector<int> v2(v1);
  v1.push_back(1);
  Factored d(11);
  Factored e(v1);
  Factored f(v2);
  Factored g = e/f;
  assert(g==d);
}

int main(int argc, const char* argv[]) {
  test_multiply();
  test_divide();
}
