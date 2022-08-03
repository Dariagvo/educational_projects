CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: build


build: main


main: s21_string.o
	$(CC) $(CFLAGS) s21_string.o -o build/Quest_1


strlen_tests: 
	$(CC) $(CFLAGS) -DQUEST1 src/s21_string.c src/s21_string_test.c -o build/Quest_1


strcmp_tests:
	$(CC) $(CFLAGS) -DQUEST2 src/s21_string.c src/s21_string_test.c -o build/Quest_2


strcpy_tests:
	$(CC) $(CFLAGS) -DQUEST3 src/s21_string.c src/s21_string_test.c -o build/Quest_3


strcat_tests:
	$(CC) $(CFLAGS) -DQUEST4 src/s21_string.c src/s21_string_test.c -o build/Quest_4


strchr_tests:
	$(CC) $(CFLAGS) -DQUEST5 src/s21_string.c src/s21_string_test.c -o build/Quest_5


clean:
	rm build/Quest*


rebuild: 
	clean
	build
