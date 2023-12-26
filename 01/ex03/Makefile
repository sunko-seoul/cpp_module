CC = g++
CFLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98
NAME = weapon
SRCS = main.cpp\
	   HumanA.cpp\
	   HumanB.cpp\
	   Weapon.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = HumanA.h\
		 HumanB.h\
		 Weapon.h

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
