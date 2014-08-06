CC = clang	 
CFLAGS  = -c -Wall   
objects = main.o first_tree.o second_tree.o third_tree.o solution_level.o \
        final_prune.o running_gaussian_elimination.o solution_check_functions.o \
        solution_check.o linalg_row_operations.o brute_force_check.o \
        tree_functions.o output_linked_list.o
tree : $(objects)
	$(CC) -o tree $(objects)
main.o : main.c   
	$(CC) $(CFLAGS)  main.c
first_tree.o : first_tree.c tree_functions.h solution_level.h \
               output_linked_list.h brute_force_check.h second_tree.h
	$(CC) $(CFLAGS) first_tree.c
second_tree.o : second_tree.c tree_functions.h solution_level.h \
                output_linked_list.h solution_check.h third_tree.h
	$(CC) $(CFLAGS) second_tree.c
third_tree.o : third_tree.c tree_functions.h solution_level.h \
               output_linked_list.h brute_force_check.h solution_check.h
	$(CC) $(CFLAGS) third_tree.c
final_prune.o :	final_prune.c linalg_row_operations.h output_linked_list.h \
                solution_level.h
	$(CC) $(CFLAGS) final_prune.c
running_gaussian_elimination.o : running_gaussian_elimination.c \
                                 linalg_row_operations.h
	$(CC) $(CFLAGS) running_gaussian_elimination.c
solution_level.o : solution_level.c 
	$(CC) $(CFLAGS) solution_level.c
solution_check_functions.o : solution_check_functions.c solution_level.h \
                             linalg_row_operations.h
	$(CC) $(CFLAGS) solution_check_functions.c
solution_check : solution_check.c solution_check_functions.h solution_level.h
	$(CC) $(CFLAGS) solution_check.c
linalg_row_operations.o : linalg_row_operations.c
	$(CC) $(CFLAGS)  linalg_row_operations.c
tree_functions.o : tree_functions.c linalg_row_operations.h \
                   running_gaussian_elimination.h
	$(CC) $(CFLAGS) tree_functions.c
output_linked_list.o : output_linked_list.c 
	$(CC) $(CFLAGS) output_linked_list.c
brute_force_check.o : brute_force_check.c linalg_row_operations.h
	$(CC) $(CFLAGS) brute_force_check.c
clean: 
	-rm tree $(objects)
