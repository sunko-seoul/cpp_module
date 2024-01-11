CC = c++
CFLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98
NAME = a.out
SRCS = main.cpp
TEMPLATE_SRCS = Array.tpp
OBJS = $(SRCS:.cpp=.o)
HEADER = Array.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(VERSION) -o $@ $^

%.o: %.cpp $(HEADER) $(TEMPLATE_SRCS)
	$(CC) $(CFLAGS) $(VERSION) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
