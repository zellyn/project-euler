CPP = g++
OFLAG = -o
CPPFLAGS = -Wall -O3

.PHONY : clean all

all : 001 002 003 004 005 006 007 008 009 010 \
      011 012 013 014 015 016 017 018 019 020 \
      021 022 023 024 025 026 027 028 029 030 \
      031 032 033 034 035 036 037 038 039 040 \
      041 042 043 044 045 046 047 048 049 050 \
      051 052 053 054 055 056 057 058 059 060 \
      061 062 063 064 065 066 067 068 069 070 \
      071 072 073 074 075 076 077 078 079 080 \
      081 082 083 084 085 086 087 088 089 090 \
      bigmath_test factored_test

clean :
	-rm [0-9][0-9][0-9] *~ *.o

bigmath_test : bigmath_test.cc bigmath.h
myutil.o : myutil.h
factored.o : factored.h primes1.h
factored_test : factored_test.cc factored.o

002 : mymath.h
003 : primes1.h
005 : primes1.h
007 : primes1.h
010 : primes1.h
016 : bigmath.h
020 : bigmath.h
021 : primes1.h
022 : myutil.o
023 : primes1.h
025 : bigmath.h
027 : primes1.h
029 : primes1.h
032 : mymath.h
033 : mymath.h
035 : primes1.h
037 : primes1.h
041 : mymath.h primes1.h
042 : myutil.o
046 : primes1.h
047 : primes1.h
048 : bigmath.h
049 : primes1.h
050 : primes1.h
051 : primes1.h
053 : primes1.h factored.o
