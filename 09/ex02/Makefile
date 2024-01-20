CC = c++
CFLAGS = -Wall -Wextra -Werror -g
VERSION = -std=c++98
NAME = PmergeMe
SRCS = main.cpp \
	   PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = PmergeMe.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(VERSION) -o $@ $^

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) $(VERSION) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
