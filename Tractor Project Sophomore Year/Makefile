main: main.o Game.o
	g++ -o main main.o Game.o

main.o: main.cpp Game.h
	g++ -c main.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp

clean:
	rm main.o Game.o