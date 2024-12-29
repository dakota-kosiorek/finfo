finfo: src/finfo.c
	gcc -o build/finfo src/finfo.c -Iinclude

.PHONY: clean

clean:
	rm -f build/finfo