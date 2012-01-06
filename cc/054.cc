// Project Euler Problem 054
//
// How many hands did player one win in the game of poker?

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "myutil.h"

using namespace std;

struct Card {
  int value;
  char suit;
  string name;
};

const string CARD_VALUES = "23456789TJQKA";

// Order stacks of same-valued cards by size, then by value
bool comp(vector<Card> a, vector<Card> b) {
  if (a.size() != b.size()) {
    return a.size() > b.size();
  }
  return a[0].value > b[0].value;
}

class Hand {
public:
  Hand() { };

  void Add(const string& cardStr) {
    Card card = {CARD_VALUES.find(cardStr[0]) + 2, cardStr[1], cardStr};
    // Add to counts
    counts_[card.value]++;
    counts_[1] = counts_[14];  // Aces

    // Add to suits_
    suits_.insert(card.suit);

    // Add to value_stacks_
    vector<vector<Card> >::iterator it2;
    bool inserted = false;
    for (it2=value_stacks_.begin(); it2<value_stacks_.end(); ++it2) {
      if ((*it2)[0].value == card.value) {
	it2->push_back(card);
	inserted = true;
	break;
      }
    }
    if (!inserted) {
      vector<Card> cards;
      cards.push_back(card);
      value_stacks_.push_back(cards);
    }
    sort(value_stacks_.begin(), value_stacks_.end(), comp);
  }

  float Score() {
    // Compute counts summary
    int summary = ValueSummary();
    // Compute score from counts
    float stackScore = 0.0;
    vector<vector<Card> >::const_reverse_iterator rit;
    for (rit=value_stacks_.rbegin(); rit!=value_stacks_.rend(); ++rit) {
      stackScore = (stackScore + (*rit)[0].value) / 15.0;
    }

    float score;
    // Royal Flush
    if ((score = RoyalFlush()) > 0.0) return 9.0 + score;
    // Straight Flush
    if ((score = StraightFlush()) > 0.0) return 8.0 + score;
    // Four of a kind
    if (summary == 41) return 7.0 + stackScore;
    // Full house
    if (summary == 32) return 6.0 + stackScore;
    // Flush
    if (suits_.size() == 1) return 5.0 + stackScore;
    // Straight
    if ((score = Straight()) > 0.0) return 4.0 + score;
    // Three of a kind
    if (summary == 311) return 3.0 + stackScore;
    // Two pairs
    if (summary == 221) return 2.0 + stackScore;
    // One pair
    if (summary == 2111) return 1.0 + stackScore;
    // High card
    return stackScore;
  }

private:
  int ValueSummary() {
    int summary = 0;
    vector<vector<Card> >::const_iterator it;
    for (it=value_stacks_.begin(); it!=value_stacks_.end(); ++it) {
      summary = summary * 10 + it->size();
    }
    return summary;
  }

  float RoyalFlush() {
    if (counts_[14] != 1) return 0.0;  // Ace
    if (counts_[13] != 1) return 0.0;  // King
    return StraightFlush();
  }

  float StraightFlush() {
    if (suits_.size() != 1) return 0.0;
    return Straight();
  }

  float Straight() {
    int inarow = 0;
    for (int i=1; i<=14; ++i) {
      if (counts_[i] == 1) {
	inarow++;
	if (inarow==5) {
	  return i / 15.0;
	}
      } else {
	inarow = 0;
      }
    }
    return 0.0;
  }

private:
  set<char> suits_;
  vector<vector<Card> > value_stacks_;
  map<int, int> counts_;
};

vector<pair<Hand, Hand> > read_hands(const char* filename) {
  vector<pair<Hand, Hand> > retval;
  vector<string> lines = read_lines(filename);
  vector<string>::iterator it;
  for (it=lines.begin(); it != lines.end(); ++it) {
    Hand hand1;
    Hand hand2;
    for (int i=0; i<10; ++i) {
      ((i<5) ? hand1 : hand2).Add((*it).substr(3*i, 2));
    }
    retval.push_back(pair<Hand, Hand>(hand1, hand2));
  }
  return retval;
}

int main(int argc, const char* argv[]) {
  vector<pair<Hand, Hand> > hands = read_hands("../data/p054_poker.txt");
  vector<pair<Hand, Hand> >::iterator it;
  int count = 0;
  for (it=hands.begin(); it != hands.end(); ++it) {
    if ((it->first).Score() > (it->second).Score()) {
      ++count;
    }
  }
  printf("%d\n", count);
}
