.PHONY: clean

run:
	g++ -o main test/main.cpp src/*.cpp 
	./main

clean:
	rm ./main
