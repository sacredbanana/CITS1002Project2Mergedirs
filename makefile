# A Makefile to build the 'mergedirs' project

PROJECT = mergedirs
HEADERS = $(PROJECT).h
OBJ     = mergedirs.o globals.o readdirs.o copyfile.o filecheck.o filesummary.o

C99     = gcc -std=c99
CFLAGS  = -Wall -Werror -pedantic

$(PROJECT) : $(OBJ)
	$(C99) $(CFLAGS) -o $(PROJECT) $(OBJ)

mergedirs.o : mergedirs.c $(HEADERS)
	$(C99) $(CFLAGS) -c mergedirs.c

globals.o : globals.c $(HEADERS)
	$(C99) $(CFLAGS) -c globals.c

readdirs.o : readdirs.c $(HEADERS)
	$(C99) $(CFLAGS) -c readdirs.c

copyfile.o : copyfile.c $(HEADERS)
	$(C99) $(CFLAGS) -c copyfile.c

filecheck.o : filecheck.c $(HEADERS)
	$(C99) $(CFLAGS) -c filecheck.c

filesummary.o : filesummary.c $(HEADERS)
	$(C99) $(CFLAGS) -c filesummary.c
clean:
	rm -f $(PROJECT) $(OBJ) 
