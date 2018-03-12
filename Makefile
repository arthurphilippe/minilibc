##
## EPITECH PROJECT, 2018
## bs malloc
## File description:
## tests
##

CC		=	gcc

ASM		=	nasm

NAME		=	libasm.so

NAME_TEST	=	test.out

RM		=	rm -vf

SRCS		=	src/strlen.asm	\
			src/memset.asm	\
			src/strchr.asm	\
			src/memcpy.asm	\
			src/rindex.asm	\
			src/strcmp.asm	\
			src/strncmp.asm	\
			src/memmove.asm	\
			src/strcasecmp.asm	\
			src/strstr.asm	\
			src/strcspn.asm

SRCS_TEST	=	tests/main.c

OBJS		=	$(SRCS:.asm=.o)

OBJS_TEST	=	$(SRCS_TEST:.c=.o)

ASFLAGS		=	-felf64

CFLAGS		=	-Iinclude/ -fno-builtin-strlen

%.o: %.asm
	@printf "[\033[0;36mcompiling\033[0m]% 39s\r" $< | tr " " "."
	@$(ASM) $(ASFLAGS) $<
	@printf "[\033[0;32mcompiled\033[0m]% 40s\n" $< | tr " " "."

%.o: %.c
	@printf "[\033[0;36mcompiling\033[0m]% 39s\r" $< | tr " " "."
	@$(CC) -c -o $@ $< $(CFLAGS)
	@printf "[\033[0;32mcompiled\033[0m]% 40s\n" $< | tr " " "."

all: $(NAME)

debug: fclean
debug: CFLAGS += -ggdb
debug: $(NAME) $(NAME_TEST)

$(NAME_TEST): $(NAME) $(OBJS_TEST)
	@printf "[\033[0;36mlinking\033[0m]% 41s\r" $(NAME_TEST) | tr " " "."
	@$(CC) $(OBJS_TEST) -o $(NAME_TEST) -L. -lasm  -fno-builtin-strlen
	@printf "[\033[0;36mlinked\033[0m]% 42s\n" $(NAME_TEST) | tr " " "."


$(NAME): $(OBJS)
	@printf "[\033[0;36mlinking\033[0m]% 41s\r" $(NAME) | tr " " "."
	@$(CC) -nostdlib -shared -o $(NAME) $(OBJS)
	@printf "[\033[0;36mlinked\033[0m]% 42s\n" $(NAME) | tr " " "."

clean:
	@printf "[\033[0;31mdeletion\033[0m][objects]% 31s\n" `$(RM) $(OBJS) $(OBJS_TEST) | wc -l | tr -d '\n'` | tr " " "."

fclean: clean
	@$(RM) $(NAME) $(TEST) > /dev/null
	@printf "[\033[0;31mdeletion\033[0m][binary]% 32s\n" $(NAME) | tr " " "."

re: fclean all

.PHONY: all clean fclean re debug
