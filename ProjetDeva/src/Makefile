BIN = Jeux.exe
OBJECTS = JeuxDuo.o JeuxModeNormal.o JeuxModeFacile.o main.o
CC = gcc 
CFLAGS = -Wall -Wextra -O2

all: $(OBJECTS)
	$(CC) -o $(BIN) $(OBJECTS) $(CFLAGS)


JeuxDuo.o: JeuxDuo.c 
		$(CC) -c JeuxDuo.c  $(CFLAGS)
		
JeuxModeFacile.o: JeuxModeFacile.c
		$(CC) -c JeuxModeFacile.c $(CFLAGS)

JeuxModeNormal.o: JeuxModeNormal.c
		$(CC) -c JeuxModeNormal.c $(CFLAGS)

main.o: main.c 
		$(CC) -c main.c  $(CFLAGS)
clear:
	del *.o *.exe