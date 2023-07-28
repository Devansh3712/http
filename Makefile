.PHONY: test docs clean

FLAGS = -lstdc++fs -std=c++17

test:
	g++ -o main test/main.cpp src/*.cpp $(FLAGS)
	./main

docs:
	g++ -o main docs/main.cpp src/*.cpp $(FLAGS)
	./main

clean:
	rm ./main
