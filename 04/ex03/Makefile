CC = c++
CFLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98
NAME = a.out
SRCS = main.cpp \
	   AMateria.cpp \
	   Character.cpp \
	   Cure.cpp \
	   Ice.cpp \
	   MateriaSource.cpp \
	   SmartPointer.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = AMateria.h \
		 Character.h \
		 Cure.h \
		 Ice.h \
		 ICharacter.h \
		 IMateriaSource.h \
		 MateriaSource.h \
		 SmartPointer.h

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
