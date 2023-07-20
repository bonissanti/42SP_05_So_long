#----------------------- Makefile for minunit tests -----------------------#
################################ Colors ####################################

GREEN 			= \033[1;32m
YELLOW 			= \033[1;33m
RED 			= \033[1;31m
RESET 			= \033[0m


############################# Project files ################################
SO_LONG 			= ../so_long/		----------------------------------------------> #Put here the source files

HEADER_PROJECT 	= ../so_long/example.h -------------------------------------------> #Change this to your header file

############################# Test files ###################################
TESTS 			= 		------------------------------------------------------> #Put here the test files
PROGRAM_TEST 	= $(patsubst %.c, %, $(TESTS))
HEADER_MINUNIT 	= ../minunit.h

############################## Compiler ####################################

$(TEST):	$(SO_LONG) $(TEST).c
			@cc $(SO_LONG) $(TEST).c -o $(TEST)
			@./$(PROGRAM_TEST)
			@echo "$(YELLOW) Testing $(TEST)done!$(RESET)"
			@rm -f $(TEST)
			@echo "$(YELLOW)Cleaning done!$(RESET)"


$(PROGRAM_TEST): $(OBJS)
			@cc $(SO_LONG) $@.c -o $@


leak:	test
			@valgrind --track-origins=yes --error-exitcode=42 --leak-check=full ./${PROGRAM_TEST}

clean:		
			@rm -f ${PROGRAM_TEST} 
			@echo "$(YELLOW)Cleaning done!$(RESET)"

fclean:		clean

re:			fclean

.PHONY: 	


