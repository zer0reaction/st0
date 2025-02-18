CFLAGS = -Wall -Werror -Wpedantic -std=c89 -fsanitize=address
LFLAGS = -Lbin -lst0

static:
	@mkdir -p ./bin
	gcc -Wall -Werror -Wpedantic -std=c89 -c -o ./bin/st0.o ./src/st0_internal.c
	ar rcs ./bin/libst0.a ./bin/st0.o

test:
	@mkdir -p ./bin
	gcc $(CFLAGS) -o ./bin/test ./src/test.c $(LFLAGS)
