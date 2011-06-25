// Project Euler Problem 017
//
// How many letters would be needed to write all the numbers in words
// from 1 to 1000?

#include <cstdio>

int LENGTHS_ONES[] = {
  0,  // zero doesn't count!
  3,  // one
  3,  // two
  5,  // three
  4,  // four
  4,  // five
  3,  // 6
  5,  // seven
  5,  // eight
  4,  // nine
  3,  // ten
  6,  // eleven
  6,  // twelve
  8,  // thirteen
  8,  // fourteen
  7,  // fifteen
  7,  // sixteen
  9,  // seventeen
  8,  // eighteen
  8,  // nineteen
};

int LENGTHS_TENS[] = {
  0,  // zero doesn't count
  3,  // ten
  6,  // twenty
  6,  // thirty
  5,  // forty
  5,  // fifty
  5,  // sixty
  7,  // seventy
  6,  // eighty
  6,  // ninety
};

int length(int n) {
  if (n < 20) {
    return LENGTHS_ONES[n];
  }
  if (n==1000) {
    return 11;  // "one thousand"
  }
  if (n>99) {
    int l = length(n/100) + 7;  // "hundred"
    if (n % 100) {
      l += 3 + length(n % 100);  // "and"
    }
    return l;
  }
  return LENGTHS_TENS[n/10] + LENGTHS_ONES[n%10];
}

int main(int argc, const char* argv[]) {
  int sum = 0;
  for (int i = 1; i<=1000; i++) {
    sum += length(i);
  }
  printf("%d\n", sum);
}
