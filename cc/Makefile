CPP = g++
OFLAG = -o
CPPFLAGS = -Wall -O3

.PHONY : clean all

all : $(basename $(wildcard ???.cc) $(wildcard *_test.cc))

clean :
	-rm -f [0-9][0-9][0-9] *~ *.o

bigmath_test : bigmath_test.cc bigmath.o
bigmath.o : bigmath.h
myutil.o : myutil.h
factored.o : factored.h primes1.h
factored_test : factored_test.cc factored.o

002 : mymath.h
003 : primes1.h
005 : primes1.h
007 : primes1.h
010 : primes1.h
012 : primes1.h
016 : bigmath.o
020 : bigmath.o
021 : primes1.h
022 : myutil.o
023 : primes1.h
025 : bigmath.o
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
048 : bigmath.o
049 : primes1.h
050 : primes1.h
051 : primes1.h
053 : primes1.h factored.o
054 : myutil.o
055 : bigmath.o
056 : bigmath.o
057 : bigmath.o
058 : primes1.h
059 : myutil.o
060 : primes1.h
