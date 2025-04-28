all: compile hakan

compile:
	g++ -I ./include/ -o ./lib/doublylinkedlist.o -c ./src/doublylinkedlist.cpp
	g++ -I ./include/ -o ./lib/ChromosomeList.o -c ./src/ChromosomeList.cpp
	g++ -I ./include/ -o ./lib/DNA.o -c ./src/DNA.cpp 
	g++ -I ./include/ -o ./bin/program ./lib/ChromosomeList.o ./lib/doublylinkedlist.o ./lib/DNA.o ./src/main.cpp
	

hakan:
	cls
	./bin/program
