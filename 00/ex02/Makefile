CC = c++
CFLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98
NAME = tester
SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Account.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(VERSION) -o $@ $^

$(OBJS): %.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) $(VERSION) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
