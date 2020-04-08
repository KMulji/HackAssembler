
#To run, put this file together with lexer.h, and lexer.c
#in the same directory. Run "make". Then the executable
#is "schemer," which just takes a line of input and
#breaks it up into tokens.

assembler: main.o  parser.o coder.o map.o 
	gcc -o assembler main.o parser.o coder.o map.o

main.o: main.c
	gcc -c main.c

parser.o: parser.c
	gcc -c parser.c

coder.o: coder.c
	gcc -c coder.c

map.o: map.c
	gcc -c map.c

clean:
	rm -f *~ *.o *.a

#^^^^^^This space must be a TAB!!.

