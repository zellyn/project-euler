// Project Euler Problem 059
//
// Using a brute force attack, can you decrypt the cipher using XOR
// encryption?

#include <cstdio>
#include <map>
#include "myutil.h"

using namespace std;

// http://www.math.cornell.edu/~mec/2003-2004/cryptography/subs/digraphs.html
static const char* BIGRAMS[] = {
  "th", "he", "in", "er", "an", "re", "nd", "at", "on", "nt", "ha", "es", "st",
  "en", "ed", "to", "it", "ou", "ea", "hi", "is", "or", "ti", "as", "te", "et",
  "ng", "of", "al", "de", "se", "le", "sa", "si", "ar", "ve", "ra", "ld", "ur"
};
static const float FREQS[] = {
  1.52, 1.28, 0.94, 0.94, 0.82, 0.68, 0.63, 0.59, 0.57, 0.56, 0.56, 0.56, 0.55,
  0.55, 0.53, 0.52, 0.50, 0.50, 0.47, 0.46, 0.46, 0.43, 0.34, 0.33, 0.27, 0.19,
  0.18, 0.16, 0.09, 0.09, 0.08, 0.08, 0.06, 0.05, 0.04, 0.04, 0.04, 0.02, 0.02
};

float Score(vector<int> decrypted, map<string, float> bigrams_baseline) {
  map<string, float> bigrams;
  int count = decrypted.size() - 1;
  for (int i=0; i < count; i++) {
    string key;
    key.push_back((char)decrypted[i]);
    key.push_back((char)decrypted[i+1]);
    bigrams[key] += 1.0/count;
  }
  float score = 0;
  for (map<string, float>::iterator it=bigrams_baseline.begin(); it!=bigrams_baseline.end(); ++it) {
    float expected = (*it).second;
    float actual = bigrams[(*it).first];
    score += (expected-actual) * (expected-actual);
  }
  return score;
}

vector<int> Decrypt(vector<int>input, int* key) {
  vector<int> result = input;
  int i=0;
  for (vector<int>::iterator it = result.begin(); it!=result.end(); ++it) {
    *it ^= key[i++ % 3];
    if (((*it) < 32) || ((*it) > 127)) {
      result.clear();
      return result;
    }
  }
  return result;
}

int main(int argc, const char* argv[]) {
  vector<int> input = get_csv_ints("../data/p059_cipher1.txt");
  map<string, float> bigrams_baseline;
  for (size_t i=0; i<(sizeof(FREQS) / sizeof(FREQS[0])); i++) {
    bigrams_baseline[string(BIGRAMS[i])] = FREQS[i];
  }
  float min_score = 1e99;
  int sum = 0;
  int key[3];
  for (key[0] = 'a'; key[0]<='z'; key[0]++) {
    for (key[1] = 'a'; key[1]<'z'; key[1]++) {
      for (key[2] = 'a'; key[2]<'z'; key[2]++) {
	vector<int> decrypted = Decrypt(input, key);
	if (!decrypted.size()) continue;
	float score = Score(decrypted, bigrams_baseline);
	if (score < min_score) {
	  min_score = score;
	  sum = 0;
	  for (vector<int>::iterator it = decrypted.begin(); it!=decrypted.end(); ++it) {
	    sum += *it;
	  }
	}
      }
    }
  }
  printf("%d\n", sum);
}
