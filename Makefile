# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmontes- <lmontes-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/06 06:53:59 by lmontes-          #+#    #+#              #
#    Updated: 2022/12/06 07:16:17 by lmontes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_tolower.c ft_toupper.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcat.c \
	ft_strlcpy.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJS = ${SRCS:.c=.o}

BONUS_SRC = ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_front.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJ = ${BONUS_SRC:.c=.o}

CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

all: ${NAME}

${NAME}:	
	${CC} -c ${CFLAGS} ${SRCS} ${BONUS_SRC}
	ar -rcs ${NAME} ${OBJS} ${BONUS_OBJ}
	ranlib ${NAME}

clean:
	${RM} ${OBJS} ${BONUS_OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re