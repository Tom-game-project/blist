CC = cc
CFLAG = -Wextra -Werror -Wall
SRC = \
src/init_node.c \
src/push.c
OBJ = $(SRC:.c=.o)

NAME = blist.a

all: $(NAME) 

$(NAME):$(OBJ)
	ar -rcs $@ $^

%.o: %.c
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(BSCSRC:.c=.o) $(BNSSRC:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean
	make
