cc = g++
flags = -Wall -Werror -ansi -pedantic

all: rshell

rshell:
		mkdir -p ./bin
		$(cc) $(flags) ./src/main.cpp -o ./bin/rshell 

clean:
		rm -rf ./bin
