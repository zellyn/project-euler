// Project Euler Problem 054
//
// How many hands did player one win in the game of poker?

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <sstream>
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
const size_t CARD_COUNTS_LEN = 15;

bool comp(vector<Card> a, vector<Card> b) {
  if (a.size() != b.size()) {
    return a.size() > b.size();
  }
  return a[0].value > b[0].value;
}

class Hand {
public:
  Hand() {
    for (size_t i = 0; i < CARD_COUNTS_LEN; ++i) {
      counts_[i] = 0;
    }
  };

  void Add(const Card& card) {
    // Add to counts
    counts_[card.value]++;
    counts_[1] = counts_[14];  // Aces

    // Add to cards_
    InsertDescending(cards_, card);

    // Add to suits_
    suits_.insert(card.suit);

    // Add to by_value_
    vector<vector<Card> >::iterator it2;
    bool inserted = false;
    for (it2=by_value_.begin(); it2<by_value_.end(); ++it2) {
      if ((*it2)[0].value == card.value) {
	it2->push_back(card);
	inserted = true;
	break;
      }
    }
    if (!inserted) {
      vector<Card> cards;
      cards.push_back(card);
      by_value_.push_back(cards);
    }
    sort(by_value_.begin(), by_value_.end(), comp);
  }

  void Add(const string& card_str) {
    Card card = {CARD_VALUES.find(card_str[0]) + 2, card_str[1], card_str};
    Add(card);
  }

  float Score() {
    int summary = ValueSummary();
    float score;
    // Royal Flush
    score = RoyalFlush();
    if (score > 0.0) return 9.0 + score;
    // Straight Flush
    score = StraightFlush();
    if (score > 0.0) return 8.0 + score;
    // Four of a kind
    if (summary == 41) {
      return 7.0 + ScoreFrom(by_value_);
    }
    // Full house
    if (summary == 32) {
      return 6.0 + ScoreFrom(by_value_);
    }
    // Flush
    score = Flush();
    if (score > 0.0) return 5.0 + score;
    // Straight
    score = Straight();
    if (score > 0.0) return 4.0 + score;
    // Three of a kind
    if (summary == 311) {
      return 3.0 + ScoreFrom(by_value_);
    }
    // Two pairs
    if (summary == 221) {
      return 2.0 + ScoreFrom(by_value_);
    }
    // One pair
    if (summary == 2111) {
      return 1.0 + ScoreFrom(by_value_);
    }
    // High card
    return ScoreFrom(by_value_);
  }

  string String() {
    stringstream ss(stringstream::in | stringstream::out);
    for (vector<Card>::iterator it=cards_.begin(); it!=cards_.end(); ++it) {
      ss << it->name << ' ';
    }
    ss << "- " << Score();
    return ss.str(); 
  }

private:
  int ValueSummary() {
    int summary = 0;
    vector<vector<Card> >::const_iterator it;
    for (it=by_value_.begin(); it!=by_value_.end(); ++it) {
      summary = summary * 10 + it->size();
    }
    return summary;
  }

  void InsertDescending(vector<Card>& cards, const Card& card) {
    // Insert into cards
    vector<Card>::iterator it1;
    for (it1=cards.begin(); it1<cards.end(); ++it1) {
      if (it1->value <= card.value)
	break;
    }
    cards.insert(it1, card);
  }

  float ScoreFrom(const vector<vector<Card > >& stacks) {
    float score = 0.0;
    vector<vector<Card> >::const_reverse_iterator rit;
    for (rit=stacks.rbegin(); rit!=stacks.rend(); ++rit) {
      score = (score + (*rit)[0].value) / 15.0;
    }
    return score;
  }

  bool IsFlush() {
    return suits_.size() == 1;
  }

  float RoyalFlush() {
    if (counts_[14] != 1) return 0.0;  // Ace
    if (counts_[13] != 1) return 0.0;  // King
    return StraightFlush();
  }

  float StraightFlush() {
    if (!IsFlush()) return 0.0;
    return Straight();
  }

  float Flush() {
    if (suits_.size() > 1) {
      return 0.0;
    }
    return ScoreFrom(by_value_);
  }

  float Straight() {
    int inarow = 0;
    for (size_t i=0; i<CARD_COUNTS_LEN; ++i) {
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
  vector<Card> cards_;
  set<char> suits_;
  vector<vector<Card> > by_value_;
  int counts_[CARD_COUNTS_LEN];
};

bool compare_values(const Card& card1, const Card& card2) {
  return card1.value > card2.value;
}

bool compare_suits(const Card& card1, const Card& card2) {
  return card1.suit < card2.suit;
}

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
