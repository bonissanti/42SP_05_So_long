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

SRCS			= ../so_long/src
OBJS			= $(addprefix ./src/, $(SRC:.c=.o))
HEADER			= ../so_long/include

LIBFT			= ./my_libft
SO_LONG			= ./so_long

############################# Compilation ##################################

CC 				= gcc
CFLAGS 			= -Wall -Wextra -Werror

LIBFT_MAKE 		= $(MAKE) -C $(LIBFT)
LIBFT_LIB 		= $(LIBFT)/libft.a

############################# Rules ########################################

all: $(NAME)

$(NAME): $(LIBFT_LIB)
	@echo "$(BLUE)Compiling So_long...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS)/*.c -I $(HEADER) -L $(LIBFT) -lft -lmlx -framework OpenGL -framework AppKit
	@echo "$(GREEN)So_long compiled$(RESET)"

$(LIBFT_LIB):
	@echo "$(BLUE)Compiling Libft...$(RESET)"
	@$(LIBFT_MAKE)
	@echo "$(GREEN)Libft compiled$(RESET)"

############################# Norm rules ####################################

norm:
	@echo "$(YELLOW)Norminette...$(RESET)"
	@norminette $(SRCS) $(HEADER)
	@echo "$(GREEN)Norminette done$(RESET)"

############################# Valgrind rules ################################

leaks:
	@echo "$(YELLOW)Valgrind...$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) maps/map.ber
	@echo "$(GREEN)Valgrind done$(RESET)"

############################# Clean rules ###################################

clean:
	@rm -f $(OBJS)
	@echo "$(RED)So_long objects deleted$(RESET)"
	@$(LIBFT_MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)So_long deleted$(RESET)"
	@$(LIBFT_MAKE) fclean

re: fclean all

.PHONY: all clean fclean re norm leaks



