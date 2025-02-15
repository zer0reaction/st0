CFLAGS = -Wall -Werror -Wpedantic -std=c89 -fsanitize=address

all:
	@mkdir -p ./bin
	gcc $(CFLAGS) -o ./bin/test ./src/test.c ./src/st0_internal.c
