main.bin: main.o orkut.o
	gcc main.o orkut.o -o main.bin
main o: main.c
	gcc -c main.c
orkut.o: orkut.c orkut.h
	gcc -c orkut.c
clean:
	rm *.o