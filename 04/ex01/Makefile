CC = c++
CFLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98
NAME = a.out
SRCS = main.cpp \
	   Animal.cpp \
	   Cat.cpp \
	   Dog.cpp \
	   WrongAnimal.cpp \
	   WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = Animal.h Cat.h Dog.h WrongAnimal.h WrongCat.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(VERSION) -o $@ $^

$(OBJS): %.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) $(VERSION) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
