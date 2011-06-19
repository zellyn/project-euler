#! /usr/bin/bash

echo "Building............................."

make 00{1..9} 0{10..20}

echo "Testing.............................."

pairs="001-233168 002-4613732 003-6857 004-906609 005-232792560\
 006-25164150 007-104743 008-40824 009-31875000 010-142913828922"

for pair in $pairs
do
    testnum=${pair%-*}
    expected=${pair#*-}
    [[ -f $testnum ]] || echo "$testnum doesn't exist"
    [[ -f $testnum ]] || exit
    a=$(./$testnum) || echo "Error running $testnum"
    [ "$a" == "$expected" ] && echo "$testnum: passed" || echo "Wrong answer for $testnum: Expected $expected got $a"
    [ "$a" == "$expected" ] || exit;
done

