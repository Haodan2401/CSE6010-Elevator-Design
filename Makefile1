
output: main.o elevator.o
	g++ main.o elevator.o -o output

main.o: main.c
	g++ -c main.c
	
elevator.o: elevator.c elevator.h
	g++ -c elevator.c

clean:
	rm *.o output
