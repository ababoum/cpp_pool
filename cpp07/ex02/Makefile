CXX			= @c++

CXXFLAGS	= -Wall -Werror -Wextra -g -std=c++98

NAME 		= array

SRCS		= ./main.cpp 

INCL		= ./Array.hpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCL)
			$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
			@echo "\033[1;32m\e[1m $(NAME)\e[0m\033[32m executable is compiled and ready.\e[0m"

bis:		main_bis.o $(INCL)
			$(CXX) $(CXXFLAGS) main_bis.cpp -o bis
			@echo "\033[1;32m\e[1m bis\e[0m\033[32m executable is compiled and ready.\e[0m"

clean:		
			@rm -f $(OBJS) main_bis.o
			@echo "\033[1;36m .o files successfully deleted.\e[0m"

fclean: 	clean
			@rm -f $(NAME) bis
			@echo "\033[1;36m $(NAME) executable successfully deleted.\e[0m"

re: 		fclean ${NAME} bis

.PHONY: clean fclean all re