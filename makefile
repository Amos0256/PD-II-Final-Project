all: main.c basic.h database.h myALGO.h myDS.h myDS.c myALGO.c database.c
	gcc -c main.c
	gcc -c myDS.c
	gcc -c myALGO.c
	gcc -c database.c
	gcc main.o database.o myALGO.o myDS.o -o HospitalSystem
clean:
	rm main.o
	rm myDS.o
	rm myALGO.o
	rm database.o
	rm HospitalSystem
