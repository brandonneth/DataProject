CC=../../offload/install/bin/gcc
LIBFLAGS=-L../../offload/install/lib
OMPFLAGS=-fopenmp -flto




test1.o: test1.cpp
	$(CC) $(OMPFLAGS) $(LIBFLAGS) $^ -c

test1.exe: test1.o
	$(CC) $(OMPFLAGS) $(LIBFLAGS) $^ -o $@

test1.static.exe: test1.o
	$(CC) $(OMPFLAGS) $(LIBFLAGS) $^ -o $@ -static

clean:
	rm -f test1.o test1.exe
