#------------------------- Makefile for So_long ---------------------------#
################################ Colors ####################################

RED 			= \033[1;31m
GREEN 			= \033[1;32m
YELLOW 			= \033[1;33m
BLUE 			= \033[1;34m
RESET 			= \033[0m

############################# Project files ################################

NAME 			= so_long
# NAME_BONUS 		= so_long_bonus

# VPATH			= ./so_long_files/src/base ./so_long_files/src/draw
SRCS			= $(addprefix ./so_long_files/src/base/, color.c keycode.c main.c render.c) \
				 $(addprefix ./so_long_files/src/draw/, background.c)

OBJS			= $(SRCS:.%.c=.%.o)
HEADER			= ./so_long/include/

LIBFT			= ./my_libft
SO_LONG			= ./so_long_files

############################# Compilation ##################################

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror

LIBFT_MAKE 		= $(MAKE) -C $(LIBFT)
LIBFT_LIB 		= $(LIBFT)/libft.a

############################# Rules ########################################

all: $(NAME)

$(NAME): $(LIBFT_LIB)
	@echo "$(BLUE)Compiling So_long...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS) -I $(HEADER) -L $(LIBFT) -lX11 -lXext -lmlx
	@echo "$(GREEN)So_long compiled$(RESET)"

$(LIBFT_LIB):
	@echo "$(BLUE)Compiling Libft...$(RESET)"
	@$(LIBFT_MAKE)
	@echo "$(GREEN)Libft compiled$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

############################# Norm rules ####################################

norm:
	@echo "$(YELLOW)Norminette...$(RESET)"
	@norminette $(SRCS) $(HEADER)
	@echo "$(GREEN)Norminette done$(RESET)"

############################# Valgrind rules ################################

leaks:
	@echo "$(YELLOW)Valgrind...$(RESET)"
	@valgrind --leak-check=full --show-reachable=no --show-leak-kinds=all --track-origins=yes ./$(NAME)
	@echo "$(GREEN)Valgrind done$(RESET)"

############################# Clean rules ###################################

clean:
	@rm -f $(OBJS)
	@echo "$(RED)So_long objects deleted$(RESET)"
	@$(LIBFT_MAKE) clean


fclean:
	@rm -f $(LIBFT_LIB)
	@echo "$(RED)So_long deleted$(RESET)"
	@$(LIBFT_MAKE) fclean


re: fclean all

.PHONY: all clean fclean re norm leaks



