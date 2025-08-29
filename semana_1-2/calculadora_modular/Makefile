CC = gcc
CFLAGS = -Wall -g
OBJOP = obj/operadores.o
OBJMA = obj/main.o
OBJME = obj/menu.o
OPH = includes/operadores.h 
MEH = includes/menu.h

bin/calculadora: $(OBJMA) $(OBJOP) $(OBJME)
	$(CC) $(OBJMA) $(OBJOP) $(OBJME) -o bin/calculadora

obj/main.o: src/main.c $(OPH) $(MEH)
	$(CC) $(CFLAGS) -c src/main.c -o $(OBJMA)

obj/operadores.o: src/operadores.c $(OPH)
	$(CC) $(CFLAGS) -c src/operadores.c -o $(OBJOP)

obj/menu.o: src/menu.c $(MEH)
	$(CC) $(CFLAGS) -c src/menu.c -o $(OBJME)

clean:
	rm -fr obj/*.o bin/*
