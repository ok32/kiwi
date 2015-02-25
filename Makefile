make:
	mkdir -p build
	g++ -O2 -Wall -shared -fPIC -o build/libkiwi.so src/kiwi.cpp -I./

static:
	mkdir -p build
	g++ -c src/kiwi.cpp -o build/kiwi_s.o -I./ -Wall
	ar crus build/libkiwi.a build/kiwi_s.o
