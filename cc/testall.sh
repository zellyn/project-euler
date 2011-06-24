#! /usr/bin/bash

tests='bigmath_test'
echo "Building............................."

make $tests 00{1..9} 0{10..30} > /dev/null
[[ "$?" != "0" ]] && exit

echo "Testing.............................."

for atest in $tests
do
    echo -n "$atest:"
    ./$atest
    a=$?
    [[ "$a" == "0" ]] && echo 'passed.' || echo 'failed.'
    [[ "$a" == "0" ]] || exit
done

pairs="001-233168 002-4613732 003-6857 004-906609 005-232792560\
 006-25164150 007-104743 008-40824 009-31875000 010-142913828922\
 011-70600674 012-76576500 013-5537376230 014-837799 015-137846528820\
 016-1366 017-21124 018-1074 019-171 020-648\
 021-31626 022-871198282 023-4179871 024-2783915460 025-4782\
 026-983 027--59231 028-669171001 029-9183\
 030-443839 031-73682 032-45228 033-100 034-40730\
 035-55 036-872187 037-748317 038-932718654 039-840\
 040-210 041-7652413 042-162 043-16695334890 044-5482660\
 045-1533776805 046-5777 047-134043 048-9110846700 049-296962999629\
 050-997651 051-121313 052-142857 053-4075 054-376\
 055-249 056-972 057-153 058-26241 059-107359\
 060-26033 061-28684 062-127035954683 063-49 064-1322\
 065-272 066-661 067-7273 068-6531031914842725 069-510510\
 070-8319823 071-428570 072-303963552391 073-5066251 074-402\
 075-214954 076-190569291 077-71 078-55374 079-73162890\
 080-40886 081-427337 082-260324 083-425185 084-101524
 085-2772 086-1818 087-1097343 088-7587457 089-743 090-1217"

for pair in $pairs
do
    testnum=${pair%%-*}
    expected=${pair#*-}
    echo -n "$testnum: "
    [[ -f $testnum ]] || echo "doesn't exist"
    [[ -f $testnum ]] || exit
    a=$(./$testnum) || echo "Error running"
    [ "$a" == "$expected" ] && echo "passed" || echo "Wrong answer: Expected $expected, got $a."
    [ "$a" == "$expected" ] || exit;
done

