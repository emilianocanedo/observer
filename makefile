.PHONY: all clean

all:
	g++ example.cpp -o example -std=c++11

clean:
	rm -r example