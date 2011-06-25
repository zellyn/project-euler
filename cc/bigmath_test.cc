#include "bigmath.h"
#include "limits.h"

void test_add_int() {
  BigUnsigned a(1);
  BigUnsigned b(10);
  a += 9;
  assert(a == b);
}

void test_add() {
  BigUnsigned a(1);
  BigUnsigned b(9);
  BigUnsigned c(10);
  a += b;
  assert(a == c);

  BigUnsigned d(UINT_MAX);
  assert(d[0] == UINT_MAX);
  BigUnsigned e(1);
  d += e;
  assert(d[0] == 0);
  assert(d[1] == 1);
}

void test_cmp() {
  BigUnsigned a(1);
  BigUnsigned b(9);
  BigUnsigned c(10);
  assert(a<b);
  assert(a<c);
  assert(b<c);
  assert(a<=b);
  assert(a<=c);
  assert(b<=c);
  assert(b>a);
  assert(c>a);
  assert(c>b);
  assert(b>=a);
  assert(c>=a);
  assert(c>=b);
  assert(!(a==b));
  assert(!(a==c));
  assert(!(b==c));
  a += b;
  assert(a == c);
  assert(a <= c);
  assert(a >= c);
  assert(c <= a);
  assert(c >= a);
  assert(! (a < c));
  assert(! (a > c));
  assert(! (c < a));
  assert(! (c > a));

  BigUnsigned d(UINT_MAX);
  BigUnsigned e(UINT_MAX);
  assert(d[0] == UINT_MAX);
  BigUnsigned f(1);
  BigUnsigned g(2);
  d += f;
  e += g;
  assert(d < e);
  assert(d <= e);
  assert(e > d);
  assert(e >= d);
  assert(d > BigUnsigned(42));
  d += f;
  assert(d == e);
}

void test_mul() {
  BigUnsigned a(1);
  BigUnsigned b(9);
  BigUnsigned c(10);
  a *= 9;
  assert(a == b);
  a *= 10;
  c *= 9;
  assert (a == c);

  BigUnsigned d(100);
  BigUnsigned e(100);
  e += 1;
  d *= 3;
  e *= 3;
  d += 3;
  assert (d==e);

  BigUnsigned f(UINT_MAX);
  BigUnsigned g(UINT_MAX);
  g += 1;
  f *= 3;
  g *= 3;
  f += 3;
  assert (f==g);

  BigUnsigned h(UINT_MAX);
  BigUnsigned i(UINT_MAX);
  i += 1;
  h *= UINT_MAX;
  i *= UINT_MAX;
  h += UINT_MAX;
  assert (h==i);
}

int main(int argc, const char* argv[]) {
  test_add_int();
  test_add();
  test_cmp();
  test_mul();
}
