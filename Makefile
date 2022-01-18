all: unit

unit: unit.c
	gcc -o unit $^

install:
	mv -f unit /usr/bin
	cp -rf scripts /

uninstall:
	rm -f /usr/bin/unit
	rm -rf /scripts

.PHONY: clean

clean:
	rm -f unit
