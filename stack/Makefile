CC := gcc -std=c99 -Wall -pedantic -g
CPP := g++ -Wall -pedantic -pthread
NOOP := /bin/sh -c true
APP := stack

.PHONY: all
all: build

.PHONY: clean
clean:
	rm -vf dist/$(APP)
	rm -vf tmp/$(APP)_test
	test -d dist && rmdir dist || $(NOOP)
	test -d tmp && rmdir tmp || $(NOOP)

.PHONY: build
build:
	mkdir dist
	$(CC) src/stack.c src/$(APP)_main.c -o dist/$(APP)

.PHONY: test
test:
	mkdir tmp
	$(CPP) src/stack.c test/stack_test.cpp -lgtest -lgtest_main -o tmp/$(APP)_test
	tmp/$(APP)_test
