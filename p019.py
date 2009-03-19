#!/usr/bin/env python

# Project Euler
# Problem 19
#
# How many Sundays fell on the first of the month during the twentieth century?

# Cheating is okay on boring problems
from datetime import datetime

def p019():
    total = 0
    for year in range(1901,2000+1):
        for month in range(1,12+1):
            d = datetime(year=year, month=month, day=1)
            if d.weekday()==6:
                total += 1
    return total

if __name__=='__main__':
    print p019()
