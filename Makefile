# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kousuzuk <kousuzuk@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 16:39:58 by string            #+#    #+#              #
#    Updated: 2023/10/08 10:47:56 by kousuzuk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC	=	push_swap.c \
		s_system.c \
		p_system.c \
		r_system.c \
		rr_system.c \
		gen_a_stack.c \
		utils_stack.c \
		sort_seven_or_more.c \
		sort_six_or_less.c \
		utils_sort.c \
		utils_sort_seven_or_more.c \
		utils.c
OBJS = ${SRC:.c=.o}

LIBFT = libftex/libft.a
NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

%.o: %.c
	${CC} ${CFLAGS} $< ${LIBFT} -o ${<:.c=.o}

${NAME}: ${OBJS}
	make -C libftex
	${CC} ${CFLAG} -o ${NAME} ${OBJS} ${LIBFT}
	
#dummy-tergetの宣言
.PHONY:	all clean fclean re

#全てのソースコードをコンパイルする
all: ${NAME} ;

#コンパイル時に生成したオブジェクトファイルを削除
clean:
	make fclean -C libftex
	rm -rf ${OBJS}

#clean+コンパイルした時に生成された実行ファイルと静的ライブラリを削除
fclean: clean
	make fclean -C libftex
	rm -rf ${NAME}

re: fclean all ;
