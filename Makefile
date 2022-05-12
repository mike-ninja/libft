# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbarutel <mbarutel@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 14:58:30 by mbarutel          #+#    #+#              #
#    Updated: 2021/12/13 23:01:35 by mbarutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

GERR = gcc -c -Wall -Wextra -Werror

_SRCS = ft_memset.c 
_SRCS += ft_bzero.c
_SRCS += ft_memcpy.c
_SRCS += ft_memccpy.c
_SRCS += ft_memmove.c
_SRCS += ft_memchr.c
_SRCS += ft_memcmp.c
_SRCS += ft_strlen.c
_SRCS += ft_strdup.c
_SRCS += ft_strcpy.c
_SRCS += ft_strncpy.c
_SRCS += ft_strcat.c
_SRCS += ft_strncat.c
_SRCS += ft_strlcat.c
_SRCS += ft_strchr.c
_SRCS += ft_strrchr.c
_SRCS += ft_strstr.c
_SRCS += ft_strnstr.c
_SRCS += ft_strcmp.c
_SRCS += ft_strncmp.c
_SRCS += ft_atoi.c
_SRCS += ft_isalpha.c
_SRCS += ft_isdigit.c
_SRCS += ft_isalnum.c
_SRCS += ft_isascii.c
_SRCS += ft_isprint.c
_SRCS += ft_toupper.c
_SRCS += ft_tolower.c
_SRCS += ft_memalloc.c
_SRCS += ft_memdel.c
_SRCS += ft_strnew.c
_SRCS += ft_strdel.c
_SRCS += ft_strclr.c
_SRCS += ft_striter.c
_SRCS += ft_striteri.c
_SRCS += ft_strmap.c
_SRCS += ft_strmapi.c
_SRCS += ft_strequ.c
_SRCS += ft_strnequ.c
_SRCS += ft_strsub.c
_SRCS += ft_strjoin.c
_SRCS += ft_strtrim.c
_SRCS += ft_strsplit.c
_SRCS += ft_itoa.c
_SRCS += ft_putchar.c
_SRCS += ft_putstr.c
_SRCS += ft_putendl.c
_SRCS += ft_putnbr.c
_SRCS += ft_putchar_fd.c
_SRCS += ft_putstr_fd.c
_SRCS += ft_putendl_fd.c
_SRCS += ft_putnbr_fd.c
_SRCS += ft_lstnew.c
_SRCS += ft_lstdelone.c
_SRCS += ft_lstdel.c
_SRCS += ft_lstadd.c
_SRCS += ft_lstaddback.c
_SRCS += ft_lstiter.c
_SRCS += ft_lstmap.c
_SRCS += ft_del.c
_SRCS += ft_calloc.c
_SRCS += ft_strlcpy.c
_SRCS += ft_lstlast.c
_SRCS += ft_lstsize.c

SDIR = srcs

SRCS = $(patsubst %,$(SDIR)/%,$(_SRCS))

OBJS = $(_SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@$(GERR) $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@echo 'libft.a complete'
	
clean:
	@rm -f $(OBJS)
	@echo 'obj files cleaned'

fclean: clean
	@rm -f $(NAME)
	@echo 'libft.a & obj files cleaned'
	
re: fclean all