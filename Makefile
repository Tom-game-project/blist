CC = cc
CFLAG = -Wextra -Werror -Wall
SRC = \
src/init_node.c \
src/push.c \
src/pop.c \
src/util.c \
src/sort.c \

OBJ = $(SRC:.c=.o)

TESTFILE = test/test02.c
NAME = blist.a

all: $(NAME) 

$(NAME):$(OBJ)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean
	make

test: $(NAME)
	$(CC) $(CFLAG) -g3 $(TESTFILE) $(NAME)
	./a.out
	make fclean

#.PHONY all clean fclean re test