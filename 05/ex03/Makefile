CC = c++
CFLAGS = -Wall -Wextra -Werror
VERSION = -std=c++98
NAME = a.out
SRCS = main.cpp \
	   BureauCrat.cpp \
	   AForm.cpp \
	   ShrubberyCreationForm.cpp \
	   RobotomyRequestForm.cpp \
	   PresidentialPardonForm.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = BureauCrat.h \
		 AForm.h \
		 ShrubberyCreationForm.h \
		 RobotomyRequestForm.h \
		 PresidentialPardonForm.h

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
