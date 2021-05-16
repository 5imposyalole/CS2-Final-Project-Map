spatialdb: main_menu.o database.o page.o
	cc -lm -o spatialdb main_menu.o database.o page.o

main_menu.o: main_menu.c database.h page.h item.h
	cc -c main_menu.c

page.o: page.c page.h item.h
	cc -c page.c

database.o: database.c database.h item.h
	cc -c database.c

clean:
	rm *.o
