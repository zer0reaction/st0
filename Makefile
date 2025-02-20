CFLAGS = -Wall -Werror -std=c89 -fsanitize=address
LFLAGS = -Lbin -lst0

test:
	@mkdir -p ./bin
	gcc $(TESTFLAGS) -o ./bin/test ./src/test.c $(LFLAGS)
