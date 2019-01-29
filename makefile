program: main.o Lapum.o
	gcc -o program main.o Lapum.o

main.o: main.c project2.h
	gcc -c main.c
	
Lapum.o: Lapum.c project2.h
	gcc -c Lapum.c
	
clean:
	rm -f *.o program