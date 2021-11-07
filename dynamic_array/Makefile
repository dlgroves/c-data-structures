CC := gcc -std=c99 -Wall -pedantic -g
CPP := g++ -Wall -pedantic -pthread
NOOP := /bin/sh -c true

.PHONY: all
all: build

.PHONY: clean
clean:
	rm -vf dist/dynamic_array
	rm -vf tmp/dynamic_array_test
	test -d dist && rmdir dist || $(NOOP)
	test -d tmp && rmdir tmp || $(NOOP)

.PHONY: build
build:
	mkdir dist
	$(CC) src/dynamic_array.c src/dynamic_array_main.c -o dist/dynamic_array

.PHONY: test
test:
	mkdir tmp
	$(CPP) src/dynamic_array.c test/dynamic_array_test.cpp -lgtest -lgtest_main -o tmp/dynamic_array_test
	tmp/dynamic_array_test
