CC = c++
CFLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98
NAME = harlFilter
SRCS = main.cpp\
	   Harl.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = Harl.h

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
