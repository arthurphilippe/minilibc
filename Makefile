##
## EPITECH PROJECT, 2018
## bs malloc
## File description:
## tests
##

CC		=	gcc

ASM		=	nasm

NAME		=	libmy_malloc.so

NAME_TEST	=	test.out

RM		=	rm -vf

SRCS		=	my_strlen.asm

SRCS_TEST	=	tests/main.c

OBJS		=	$(SRCS:.asm=.o)

OBJS_TEST	=	$(SRCS_TEST:.c=.o)

CFLAGS		=	-W -Wextra -Wall -Iinclude/ -fPIC

%.o: %.asm
	@printf "[\033[0;36mcompiling\033[0m]% 39s\r" $< | tr " " "."
	@$(ASM) -felf64 $<
	@printf "[\033[0;32mcompiled\033[0m]% 40s\n" $< | tr " " "."

all: $(NAME)

debug: fclean
debug: CFLAGS += -ggdb
debug: $(NAME) $(NAME_TEST)

$(NAME_TEST): $(OBJS_TEST)
	$(CC) $(OBJS_TEST) -o $(NAME_TEST) -L. -lmy_malloc

$(NAME): $(OBJS)
	$(CC) -shared -o $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS) $(OBJS_TEST)

fclean: clean
	@$(RM) $(NAME) $(NAME_TEST)

re: fclean all

.PHONY: all clean fclean re
