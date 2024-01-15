CC = c++
CFLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98
NAME = btc
SRCS = main.cpp \
	   BitcoinExchange.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = BitcoinExchange.hpp

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
