all: output.png

output.png: data.dat load.py
	python3 load.py

data.dat: a.out
	./a.out

a.out: save.cpp
	g++ save.cpp

.PHONY: clean

clean:
	rm -f a.out data.dat output.png

	