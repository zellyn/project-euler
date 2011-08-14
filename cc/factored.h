#ifndef FACTORED_H
#define FACTORED_H

#include <vector>

using namespace std;

class Factored {
 public:
  explicit Factored(int i);
  explicit Factored(vector<int>& from_factors);

  friend const Factored
    operator*(const Factored& left,
              const Factored& right);

  friend const Factored
    operator/(const Factored& left,
              const Factored& right);

  friend bool
    operator==(const Factored& left,
               const Factored& right);

  friend bool
    operator>(const Factored& left,
              const int right);

  void print() const;

 private:
  vector<int> factors;
};

#endif  // FACTORED_H
