CXX			= @c++

CXXFLAGS	= -Wall -Werror -Wextra -g -std=c++98

NAME 		= attacks

SRCS		= ./main.cpp \
				./HumanA.cpp \
				./HumanB.cpp \
				./Weapon.cpp \

INCL		= ./HumanA.hpp \
				./HumanB.hpp \
				./Weapon.hpp 

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCL)
			$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)
			@echo "\033[1;32m attacks executable is compiled and ready.\e[0m"

clean:		
			@rm -f $(OBJS)
			@echo "\033[1;36m .o files successfully deleted.\e[0m"

fclean: 	clean
			@rm -f  ${OBJS} $(NAME)
			@echo "\033[1;36m attacks executable successfully deleted.\e[0m"

re: fclean ${NAME}

.PHONY: clean fclean all re