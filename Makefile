CC = cc
CFLAG = -Wextra -Werror -Wall -fsanitize=address
SRC = \
src/init_node.c \
src/push.c \
src/pop.c \
src/util.c \
src/sort.c \
src/len.c \
src/del.c

OBJ = $(SRC:.c=.o)

TESTFILE = \
test/test00.c \
test/test01.c \
test/test02.c \

EXECUTABLES = $(TESTFILE:.c=)

NAME = blist.a

all: $(NAME) 

$(NAME):$(OBJ)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME) $(EXECUTABLES)

re: fclean
	make

$(EXECUTABLES): %: %.c
	$(CC) $(CFLAG) -o $@ $< $(NAME)

test: $(NAME) $(EXECUTABLES)
	./test/test00
	./test/test01
	./test/test02
	make fclean

unit: $(NAME)
	$(CC) $(CFLAG) test/test03.c $(NAME)

#.PHONY all clean fclean re test