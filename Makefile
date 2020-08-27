all: unit

unit: unit.c
	gcc -o unit $^

.PHONY: clean

clean:
	rm -f unit