List: prog3.o List.o Node.o ListTraverse.o
	gcc -g -Wall -Werror -o List prog3.o List.o Node.o ListTraverse.o

prog3.o: prog3.c
	gcc -g -Wall -Werror -c prog3.c

List.o: List.c
	gcc -g -Wall -Werror -c List.c

Node.o: Node.c
	gcc -g -Wall -Werror -c Node.c

clean:
	rm *.o List             
