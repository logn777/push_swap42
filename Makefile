# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmaple <rmaple@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/20 14:53:53 by torange           #+#    #+#              #
#    Updated: 2020/07/14 18:18:37 by rmaple           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = checker
NAME_P = push_swap

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBRARIES = -lft -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR)
INCLUDES = -I $(HEADERS_DIR) -I $(LIBFT_HEADERS) -I $(FT_PRINTF_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = libft/
LIBFT_HEADERS = $(LIBFT_DIR)includes/

FT_PRINTF = $(FT_PRINTF_DIR)libftprintf.a
FT_PRINTF_DIR = ft_printf/
FT_PRINTF_HEADERS = $(FT_PRINTF_DIR)includes/

HEADERS_LIST = push_swap.h
HEADERS_DIR = includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SOURCES_LIST_C = main_cheker.c \
                stack_ops.c \
                utilits.c \
                checker.c \
                operations.c \
                operations2.c \
				init.c \
				clear.c

SOURCES_DIR_C = srcs/
SOURCES_C = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

SOURCES_LIST_P = checker.c \
				main_push_swap.c \
                operations.c \
                operations2.c \
                stack_ops.c \
                utilits.c \
				solve2.c \
                push_swap.c \
				init.c \
				clear.c

SOURCES_DIR_P = srcs/
SOURCES_P = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))


OBJECTS_LIST_C = $(patsubst %.c, %.o, $(SOURCES_LIST_C))
OBJECTS_DIR_C = objects_c/
OBJECTS_C = $(addprefix $(OBJECTS_DIR_C), $(OBJECTS_LIST_C))

OBJECTS_LIST_P = $(patsubst %.c, %.o, $(SOURCES_LIST_P))
OBJECTS_DIR_P = objects_p/
OBJECTS_P = $(addprefix $(OBJECTS_DIR_P), $(OBJECTS_LIST_P))


# COLORS

ifdef COMSPEC
  GREEN =
  RED =
  RESET =
  BNW = -n
  BNM =
else
  GREEN = \033[0;32m
  RED =  \033[0;31m
  RESET = \033[0m
  BNW =
  BNM = \c
endif

all: $(LIBFT) $(FT_PRINTF) $(NAME_C) $(NAME_P)

$(NAME_C): $(OBJECTS_DIR_C) $(OBJECTS_C)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS_C) $(FT_PRINTF) $(LIBRARIES) -o $(NAME_C)
	@echo "$(NAME_C): $(GREEN)$(NAME_C) was created$(RESET)" & echo

$(NAME_P): $(OBJECTS_DIR_P) $(OBJECTS_P)
	@$(CC) $(FLAGS) $(INCLUDES) $(OBJECTS_P) $(FT_PRINTF) $(LIBRARIES) -o $(NAME_P)
	@echo "$(NAME_P): $(GREEN)$(NAME_P) was created$(RESET)" & echo

$(OBJECTS_DIR_C):
	@mkdir -p $(OBJECTS_DIR_C)

$(OBJECTS_DIR_P):
	@mkdir -p $(OBJECTS_DIR_P)

$(OBJECTS_DIR_C)%.o : $(SOURCES_DIR_C)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo $(BNW) "$(GREEN)▋$(RESET)$(BNM)"

$(OBJECTS_DIR_P)%.o : $(SOURCES_DIR_P)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo  $(BNW) "$(GREEN)▋$(RESET)$(BNM)"

$(FT_PRINTF):
	@echo "$(FT_PRINTF): $(GREEN)Creating $(FT_PRINTF)...$(RESET)"
	@$(MAKE) -sC $(FT_PRINTF_DIR)

$(LIBFT):
	@echo "$(LIBFT): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(FT_PRINTF_DIR) clean
	@rm -rf $(OBJECTS_DIR_C)
	@echo "$(NAME_C): $(RED)object files were deleted$(RESET)"
	@rm -rf $(OBJECTS_DIR_P)
	@echo "$(NAME_P): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "libft.a: $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(FT_PRINTF)
	@echo "libftprintf.a: $(RED)$(FT_PRINTF) was deleted$(RESET)"
	@rm -f $(NAME_C)
	@echo "$(NAME_C): $(RED)$(NAME_C) was deleted$(RESET)"
	@rm -f $(NAME_P)
	@echo "$(NAME_P): $(RED)$(NAME_P) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
