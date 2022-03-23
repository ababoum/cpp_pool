CXX			= @c++

CXXFLAGS	= -Wall -Werror -Wextra -std=c++98

NAME 		= phonebook

SRCS		= ./main.cpp \
				./PhoneBook.cpp \
				./Contact.cpp

INCL		= ./PhoneBook.hpp \
				./Contact.hpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCL)
			$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
			@echo "\033[1;32m $(NAME) executable is compiled and ready.\e[0m"

clean:		
			@rm -f $(OBJS)
			@echo "\033[1;36m .o files successfully deleted.\e[0m"

fclean: 	clean
			@rm -f  ${OBJS} $(NAME)
			@echo "\033[1;36m $(NAME) executable successfully deleted.\e[0m"

re: fclean ${NAME}

.PHONY: clean fclean all re
