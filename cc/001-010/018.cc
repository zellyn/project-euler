// Project Euler Problem 018
//
// Find the maximum sum travelling from the top of the triangle to the
// base.

#include <cstdio>

const int SIZE = 15;
const int TRIANGLE[] = {
  75,
  95, 64,
  17, 47, 82,
  18, 35, 87, 10,
  20,  4, 82, 47, 65,
  19,  1, 23, 75,  3, 34,
  88,  2, 77, 73,  7, 63, 67,
  99, 65,  4, 28,  6, 16, 70, 92,
  41, 41, 26, 56, 83, 40, 80, 70, 33,
  41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
  53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
  70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
  91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
  63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
  04, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23,
};

int tri(int row, int col) {
  return TRIANGLE[row * (row+1) / 2 + col];
}

int max(int a, int b) {
  return (a>b) ? a : b;
}

int main(char argv[]) {
  int maxes[SIZE+1] = { 0 };
  for (int row=SIZE-1; row>=0; row--) {
    for (int col=0; col <= row; col++) {
      maxes[col] = max(maxes[col], maxes[col+1]) + tri(row, col);
    }
  }
  printf("%d\n", maxes[0]);
}
