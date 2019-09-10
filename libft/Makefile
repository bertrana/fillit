# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialleen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 10:26:24 by ialleen           #+#    #+#              #
#    Updated: 2019/09/08 12:48:17 by ialleen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
SRCSFILES = ft_atoi.c		ft_bzero.c		ft_calloc.c		ft_isalnum.c	ft_isalpha.c\
			ft_isascii.c	ft_lstdel.c		ft_isdigit.c	ft_isprint.c	ft_itoa.c\
			ft_lstadd.c		ft_lstdelone.c	ft_lstiter.c	ft_lstmap.c		ft_lstnew.c\
			ft_memalloc.c	ft_memccpy.c	ft_memchr.c		ft_memcmp.c		ft_memcpy.c\
			ft_memdel.c		ft_memmove.c	ft_memset.c		ft_putchar.c	ft_putchar_fd.c\
			ft_putendl.c	ft_putendl_fd.c	ft_putnbr.c		ft_putnbr_fd.c	ft_putstr.c\
			ft_putstr_fd.c	ft_realloc.c	ft_strcat.c		ft_strchr.c		ft_strclr.c\
			ft_strcmp.c		ft_strcpy.c		ft_strcspn.c	ft_strdel.c		ft_strdup.c\
			ft_strequ.c		ft_striter.c	ft_striteri.c	ft_strjoin.c	ft_strlcat.c\
			ft_strlen.c		ft_strmap.c		ft_strmapi.c	ft_strncat.c	ft_strncmp.c\
			ft_strncpy.c	ft_strnequ.c	ft_strnew.c		ft_strnstr.c	ft_strrchr.c\
			ft_strsplit.c	ft_strspn.c		ft_strstr.c		ft_strsub.c		ft_strtok.c\
			ft_strtrim.c	ft_tolower.c	ft_toupper.c	ft_strlcmp.c	ft_strlcpy.c\
			ft_strpbrk.c	ft_isblank.c	ft_iscntrl.c	ft_isgraph.c	ft_islower.c\
			ft_ispunct.c	ft_isspace.c	ft_isupper.c	ft_isxdigit.c	ft_strndup.c\
			get_next_line.c

SRCSDIR = ./
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
OBJS = $(SRCS:.c=.o)
	HEADERS = libft.h
	HEADERFLAGS = $(addprefix -I, $(dir $(HEADERS)))

SRCTEST = main_.c 
OBJTEST = $(SRCTEST:.c=.o)


all: $(NAME)
		
$(NAME): $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@echo "----------------\nar rc $(NAME)"
		@ranlib $(NAME)
		@echo "----------------\nranlib $(NAME)"

%.o: %.c $(HEADERS)
		@$(CC) $(CFLAGS) -I $(HEADERFLAGS) -c -o $@ $<
		@echo "gcc $<"
clean:
		@/bin/rm -f $(OBJS)
		@/bin/rm -rf a.out.dSYM
		@echo "----------------\nobjects delete"

fclean: clean
		@/bin/rm -f $(NAME)
		@echo "----------------\n$(NAME) delete"

re: fclean all

.PHONY: all clean fclean re
