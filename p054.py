#!/usr/bin/env python

# Project Euler
# Problem 54
#
# How many hands did player one win in the game of poker?

HIGH_CARD, ONE_PAIR, TWO_PAIRS, THREE_OF_A_KIND, STRAIGHT, FLUSH, \
FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH, ROYAL_FLUSH = \
1,2,3,4,5,6,7,8,9,10

NAMES = ('',
    'High card',
    'One pair',
    'Two pairs',
    'Three of a kind',
    'Straight',
    'Flush',
    'Full house',
    'Four of a kind',
    'Straight flush',
    'Royal flush',
)

CARDS = "23456789TJQKA"

def value(card):
    return card[0]

def suit(card):
    return card[1]

def pos(card):
    return CARDS.find(value(card)) + 2

def ordered(cards):
    """Highest to lowest"""
    return sorted(cards, cmp=lambda x,y: cmp(pos(x), pos(y)), reverse=True)

def straight(cards):
    """Assumes ordered"""
    poses = map(pos, cards)
    normed = map(lambda x: x-poses[-1], poses)
    if normed == [4, 3, 2, 1, 0]:
        return True
    if normed == [pos("A*")-pos("2*"), 3, 2, 1, 0]:
        return True
    return False

def highest_card_winner(p1cards, p2cards):
    """Assumes ordered"""
    return (map(pos, p1cards) > map(pos, p2cards)) and 1 or 2

def flush(cards):
    s = suit(cards[0])
    for c in cards[1:]:
        if s != suit(c):
            return False
    return True

def kinds(cards):
    def my_cmp(a,b):
        a_tup = (len(a), pos(a[0]))
        b_tup = (len(b), pos(b[0]))
        return cmp(a_tup,b_tup)

    counts = {}
    for card in cards:
        counts.setdefault(value(card),[]).append(card)
    return sorted(counts.values(), reverse=True, cmp=my_cmp)
    

def make_score(main_score, card1=None, card2=None):
    score = main_score
    if card1:
        score += pos(card1) / 100.0
    if card2:
        score += pos(card2) / 10000.0
    return (score, NAMES[main_score])

def score(cards):
    """Assumes ordered"""
    flushed = flush(cards)
    strt = straight(cards)

    if strt and flushed:
        if value(cards[0])=="A":
            return make_score(ROYAL_FLUSH)
        else:
            return make_score(STRAIGHT_FLUSH)

    knds = kinds(cards)

    if len(knds[0])==4:
        return make_score(FOUR_OF_A_KIND, knds[0][0])

    if len(knds)==2:
        return make_score(FULL_HOUSE, knds[0][0])

    if flushed:
        return make_score(FLUSH)

    if strt:
        return make_score(STRAIGHT)

    if len(knds[0])==3:
        return make_score(THREE_OF_A_KIND, knds[0][0])

    if len(knds[0])==2:
        if len(knds[1])==2:
            return make_score(TWO_PAIRS, knds[0][0], knds[1][0])
        else:
            return make_score(ONE_PAIR, knds[0][0])

    return make_score(HIGH_CARD)

def winner(hand1, hand2):
    hand1 = ordered(hand1)
    hand2 = ordered(hand2)
    p1score = score(hand1)
    p2score = score(hand2)
    
    if p1score > p2score:
        return 1
    if p2score > p1score:
        return 2
    return highest_card_winner(hand1, hand2)

def line_2_hands(line):
    cards = line.strip().split()
    return (cards[0:5], cards[5:10])

def read_hands(filename):
    return (line_2_hands(line) for line in open(filename, "r"))

def p054():
    winners = (winner(*hands) for hands in read_hands("p054_poker.txt"))
    return sum((winner for winner in winners if winner == 1))



if __name__=='__main__':
    print p054()
