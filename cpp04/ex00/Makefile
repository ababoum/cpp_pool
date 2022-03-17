CXX			= @c++

CXXFLAGS	= -Wall -Werror -Wextra -g -std=c++98

NAME 		= animals
W_NAME		= wronganimal

SRCS		= ./main.cpp \
				./Animal.cpp \
				./Cat.cpp \
				./Dog.cpp

INCL		= ./Animal.hpp \
				./Cat.hpp \
				./Dog.hpp

W_SRCS		= ./wrongmain.cpp \
				./WrongAnimal.cpp \
				./WrongCat.cpp

W_INCL		= ./WrongAnimal.hpp \
				./WrongCat.hpp \

OBJS		= $(SRCS:.cpp=.o)
W_OBJS		= $(W_SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCL)
			$(CXX) $(CFLAGS) $(SRCS) -o $(NAME)
			@echo "\033[1;32m\e[1m $(NAME)\e[0m\033[32m executable is compiled and ready.\e[0m"

wrong:		$(W_OBJS) $(W_INCL)
			$(CXX) $(CFLAGS) $(W_SRCS) -o $(W_NAME)
			@echo "\033[1;32m\e[1m $(W_NAME)\e[0m\033[32m executable is compiled and ready.\e[0m"

clean:		
			@rm -f $(OBJS) $(W_OBJS)
			@echo "\033[1;36m .o files successfully deleted.\e[0m"

fclean: 	clean
			@rm -f $(NAME) $(W_NAME)
			@echo "\033[1;36m $(NAME) and/or $(W_NAME) executables successfully deleted.\e[0m"

re: 		fclean ${NAME}

.PHONY: clean fclean all re