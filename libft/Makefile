# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: se <se@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/17 16:48:06 by vali              #+#    #+#              #
#    Updated: 2024/08/04 23:54:48 by se               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ft_isalpha.c \
       ft_isdigit.c \
       ft_isalnum.c \
       ft_isascii.c \
       ft_isprint.c \
       ft_close_fd.c \
       ft_free.c \
       ft_free_split.c \
       ft_atoi.c \
       ft_itoa.c \
       ft_calloc.c \
       ft_memcpy.c \
       ft_memset.c \
       ft_bzero.c \
       ft_memmove.c \
       ft_strlen.c \
       ft_strlcpy.c \
       ft_strlcat.c \
       ft_strdup.c \
       ft_tolower.c \
       ft_toupper.c \
       ft_strcmp.c \
       ft_strncmp.c \
       ft_strchr.c \
       ft_strrchr.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_strnstr.c \
       ft_substr.c \
       ft_strjoin.c \
       ft_strtrim.c \
       ft_split.c \
       ft_strmapi.c \
       ft_striteri.c \
       ft_putchar_fd.c \
       ft_putstr_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \

SRCSBONUS = ft_lstnew_bonus.c \
            ft_lstadd_front_bonus.c \
            ft_lstlast_bonus.c \
            ft_lstsize_bonus.c \
            ft_lstadd_back_bonus.c \
            ft_lstadd_front_bonus.c \
            ft_lstdelone_bonus.c \
            ft_lstclear_bonus.c \
            ft_lstiter_bonus.c \
            ft_lstmap_bonus.c 

CFLAGS = -Werror -Wall -Wextra
OBJS = $(SRCS:%.c=%.o)
OBJSBONUS = $(SRCSBONUS:%.c=%.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $?

bonus: $(OBJS) $(OBJSBONUS)
	ar rcs $(NAME) $?

%.o: %.c
	cc -c $(CFLAGS) $?

clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re bonus
