NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lft -L$(LIBFT_DIR)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ../libft/
LIBFT_HEADERS = $(LIBFT_DIR)includes/

HEADERS_LIST = libbuf.h libftprintf.h
HEADERS_DIRECTORY = includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_LIST = ft_printf.c parse.c parse_utils.c \
               			 	print.c print_num.c print_txt.c \
               				print_base.c print_float.c \
               				print_utils.c colors.c libbuf.c
SOURCES_DIRECTORY = srcs/
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

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

all: $(NAME)

$(NAME): $(OBJECTS_DIRECTORY) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "$(NAME): $(GREEN)object files were created$(RESET)" & echo
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo $(BNW) "$(GREEN)▋$(RESET)$(BNM)"

clean:
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
