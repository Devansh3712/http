.PHONY: test docs clean

test:
	g++ -o main test/main.cpp src/*.cpp 
	./main

docs:
	g++ -o main docs/main.cpp src/*.cpp
	./main

clean:
	rm ./main
