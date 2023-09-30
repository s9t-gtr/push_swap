# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/02 13:12:57 by kousuzuk          #+#    #+#              #
#    Updated: 2023/07/02 13:13:15 by kousuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_strlen.c \
			  ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_strncmp.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strdup.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_atoi.c \
			  ft_strnstr.c \
			  ft_strmapi.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_itoa.c \
			  ft_utoa.c \
			  ft_striteri.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_split.c \
			  ft_calloc.c \

LST			= ft_lstnew.c \
			  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstdelone.c \
			  ft_lstiter.c \
			  ft_lstadd_back.c \
			  ft_lstclear.c \
			  ft_lstmap.c \

OBJS		= ${SRCS:.c=.o}
BONUS_OBJS	= ${LST:.c=.o}
ifdef WITH_BONUS
	SRCS += ${LST}
	OBJS += ${BONUS_OBJS}
endif
NAME		= libft.a
RM			= rm -f
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
%c%.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}
bonus:	
	make WITH_BONUS=1 ${NAME}
all:		${NAME}
clean:	
			${RM} ${OBJS} ${BONUS_OBJS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all

.PHONY: all bonus clean fclean re
