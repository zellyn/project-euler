#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Project Euler
# Problem 84
#
# In the game, Monopoly, find the three most popular squares when
# using two 4-sided dice.

import random

SQUARES = [
"GO", "A1", "CC1", "A2", "T1", "R1", "B1", "CH1", "B2", "B3", "JAIL",
"C1", "U1", "C2", "C3", "R2", "D1", "CC2", "D2", "D3", "FP",
"E1", "CH2", "E2", "E3", "R3", "F1", "F2", "U2", "F3", "G2J",
"G1", "G2", "CC3", "G3", "R4", "CH3", "H1", "T2", "H2"]
BOARD_LEN = len(SQUARES)
JAIL_POS = SQUARES.index("JAIL")

COMMUNITY_CHEST = ["GO", "JAIL"] + [""] * 14
CHANCE = ["GO", "JAIL", "C1", "E3", "H2", "R1", "*R", "*R", "*U", "-3"] + [""] * 6

def roll(sides):
    r1 = random.randint(1, sides)
    r2 = random.randint(1, sides)
    return (r1+r2, r1==r2)

def find_next(position, prefix):
    while True:
        position = (position + 1) % BOARD_LEN
        if SQUARES[position].startswith(prefix):
            return position

def chance(position):
    card = random.choice(CHANCE)
    if card == "-3":
        return move(position, -3)
    if card.startswith("*"):
        return find_next(position, card[1])
    if card in SQUARES:
        return SQUARES.index(card)
    return position

def community_chest(position):
    card = random.choice(COMMUNITY_CHEST)
    if card == "GO":
        return 0
    if card == "JAIL":
        return JAIL_POS
    return position

def move(position, throw):
    position = (position + throw + BOARD_LEN) % BOARD_LEN
    square = SQUARES[position]
    if square=="G2J":
        return JAIL_POS
    if square.startswith("CH"):
        return chance(position)
    if square.startswith("CC"):
        return community_chest(position)
    return position

def p084():
    LOOPS = 1000000
    sides = 4
    position = 0
    double_count = 0
    positions = [0] * BOARD_LEN
    for i in xrange(LOOPS):
        throw, double = roll(sides)
        if double:
            double_count += 1
        else:
            double_count = 0
        if double_count == 3:
            double_count = 0
            position = JAIL_POS
        else:
            position = move(position, throw)
        positions[position] += 1

    assert sum(positions) == LOOPS
    tops = sorted([(score, pos) for pos, score in enumerate(positions)], reverse=True)
    return int(''.join("%02d" % pos for score, pos in tops[:3]))

if __name__=='__main__':
    print p084()
