CC ?= gcc
CFLAGS ?= -Wall -std=gnu99 -g -O0

EXEC = time_test_recursion time_test_harley time_test_iteration \
	time_test_binary_search time_test_byte_shift benchmark_clz\

START = 10000000
PLUS = 100
END = 30000000

default: compute_clz.o
	$(CC) $(CFLAGS) compute_clz.o time_test.c -DREC -o time_test_recursion
	$(CC) $(CFLAGS) compute_clz.o time_test.c -DHAR -o time_test_harley
	$(CC) $(CFLAGS) compute_clz.o time_test.c -DITE -o time_test_iteration
	$(CC) $(CFLAGS) compute_clz.o time_test.c -DBIN -o time_test_binary_search
	$(CC) $(CFLAGS) compute_clz.o time_test.c -DBYT -o time_test_byte_shift
	$(CC) $(CFLAGS) compute_clz.o benchmark_clz.c -o benchmark_clz 
	
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

run: default
	./benchmark_clz $(START) $(PLUS) $(END) > result_clz

recusion: default
	./time_test_recursion $(START) $(PLUS) $(END) > result_clz
harley: default
	./time_test_harley $(START) $(PLUS) $(END) > result_clz
iteration: default
	./time_test_iteration $(START) $(PLUS) $(END) > result_clz
binary_search: default
	./time_test_binary_search $(START) $(PLUS) $(END) > result_clz
byte_shift: default
	./time_test_byte_shift $(START) $(PLUS) $(END) > result_clz

plot: run
	gnuplot runtime.gp

.PHONY: clean
clean:
	rm -f $(EXEC) *.o *.s result_clz runtime.png
