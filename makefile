

all: my_graph my_Knapsack

my_graph: my_graph.o libmy_mat.a
	gcc -Wall -g -o my_graph my_graph.o libmy_mat.a

my_Knapsack: my_Knapsack.o
	gcc -Wall -g -o my_Knapsack my_Knapsack.o

my_graph.o: my_graph.c my_mat.h
	gcc -Wall -g -c my_graph.c

my_Knapsack.o: my_Knapsack.c
	gcc -Wall -g -c my_Knapsack.c

libmy_mat.a: my_mat.o
	ar -rcs libmy_mat.a my_mat.o

my_mat.o: my_mat.c my_mat.h
	gcc -Wall -g -c my_mat.c

clean:
	rm -f my_graph my_Knapsack *.o libmy_mat.a
