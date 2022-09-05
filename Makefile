# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 14:58:30 by mbarutel          #+#    #+#              #
#    Updated: 2022/09/04 15:23:58 by mbarutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME 		= libft.a

INC_DIR		= incs/
SRC_DIR		= srcs/
OBJ_DIR		= objs/
CC			= gcc
AR			= ar rcs
INCLUDE		= -I$(INC_DIR)
CFLAGS		= -Wall -Werror -Wextra

# Colors

DEF_COLOR = \033[0;39m
RED = \033[1;91m
BLUE = \033[1;94m
MAGENTA = \033[1;95m
CYAN = \033[1;96m

# Sources

FILES = ft_memset 
FILES += ft_bzero
FILES += ft_memcpy
FILES += ft_memccpy
FILES += ft_memmove
FILES += ft_memchr
FILES += ft_memcmp
FILES += ft_strlen
FILES += ft_strdup
FILES += ft_strcpy
FILES += ft_strncpy
FILES += ft_strcat
FILES += ft_strncat
FILES += ft_strlcat
FILES += ft_strchr
FILES += ft_strrchr
FILES += ft_strstr
FILES += ft_strnstr
FILES += ft_strcmp
FILES += ft_strncmp
FILES += ft_atoi
FILES += ft_isalpha
FILES += ft_isdigit
FILES += ft_isalnum
FILES += ft_isascii
FILES += ft_isprint
FILES += ft_toupper
FILES += ft_tolower
FILES += ft_memalloc
FILES += ft_memdel
FILES += ft_strnew
FILES += ft_strdel
FILES += ft_strclr
FILES += ft_striter
FILES += ft_striteri
FILES += ft_strmap
FILES += ft_strmapi
FILES += ft_strequ
FILES += ft_strnequ
FILES += ft_strsub
FILES += ft_strjoin
FILES += ft_strtrim
FILES += ft_strsplit
FILES += ft_itoa
FILES += ft_putchar
FILES += ft_putstr
FILES += ft_putendl
FILES += ft_putnbr
FILES += ft_putchar_fd
FILES += ft_putstr_fd
FILES += ft_putendl_fd
FILES += ft_putnbr_fd
FILES += ft_lstnew
FILES += ft_lstdelone
FILES += ft_lstdel
FILES += ft_lstadd
FILES += ft_lstaddback
FILES += ft_lstiter
FILES += ft_lstmap
FILES += ft_del
FILES += ft_calloc
FILES += ft_strlcpy
FILES += ft_lstlast
FILES += ft_lstsize
FILES += ft_itoa_base
FILES += ft_ltoa_base
FILES += ft_lltoa_base
FILES += ft_ulltoa_base
FILES += ft_ftoa
FILES += ft_lftoa
FILES += ft_strjoin_head
FILES += ft_strjoin_tail
FILES += ft_arg_filter
FILES += ft_char_convert
FILES += ft_printers
FILES += ft_diouxf_convert
FILES += ft_colouring
FILES += ft_printf
FILES += ft_str_convert
FILES += ft_utils
FILES += ft_bonus_func
FILES += ft_printer_utils


SRC 		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJ 		= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

#####

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "$(BLUE)Generated Executable -> $@$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@echo "$(CYAN)Generated Object File -> $<$(DEF_COLOR)"

$(OBJ_DIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Deleted Objects Directory -> $(NAME)$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(MAGENTA)Deleted Library -> $(NAME)$(DEF_COLOR)"
	
re: fclean $(OBJ_DIR) all

.PHONY: all clean fclean re