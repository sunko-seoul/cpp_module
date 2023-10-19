CC = g++
CFLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98
NAME = zombie
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

%.o: %.cpp %.h
	$(CC) $(CFLAGS) $(VERSION) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean:
	rm -rf $(OBJS) $(NAME)

re: fclean all

.PHONY: all clean fclean re
