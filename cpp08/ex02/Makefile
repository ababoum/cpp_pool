CXX			= @c++

CXXFLAGS	= -Wall -Werror -Wextra -g -std=c++98

NAME 		= mutant_stack

SRCS		= ./main.cpp \
				./MutantStack.cpp

INCL		= ./MutantStack.hpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCL)
			$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
			@echo "\e[1;32m $(NAME)\e[0m\033[32m executable is compiled and ready.\e[0m"

clean:		
			@rm -f $(OBJS)
			@echo "\e[1;36m .o files successfully deleted.\e[0m"

fclean: 	clean
			@rm -f $(NAME)
			@echo "\e[1;36m $(NAME) executable successfully deleted.\e[0m"

re: 		fclean ${NAME}

.PHONY: clean fclean all re