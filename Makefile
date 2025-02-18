TESTFLAGS = -Wall -Werror -Wpedantic -std=c89 -fsanitize=address
STATICFLAGS = -Wall -Werror -Wpedantic -std=c89
LFLAGS = -Lbin -lst0

static:
	@mkdir -p ./bin
	gcc $(STATICFLAGS) -c -o ./bin/st0.o ./src/st0_internal.c
	ar rcs ./bin/libst0.a ./bin/st0.o

test:
	@mkdir -p ./bin
	gcc $(TESTFLAGS) -o ./bin/test ./src/test.c $(LFLAGS)
