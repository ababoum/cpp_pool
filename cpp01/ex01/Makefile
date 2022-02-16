CXX			= @c++

CXXFLAGS	= -Wall -Werror -Wextra -g -std=c++98

NAME 		= zombie_horde

SRCS		= ./main.cpp \
				./Zombie.cpp \
				./ZombieHorde.cpp \

INCL		= ./Zombie.hpp 

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCL)
			$(CXX) $(CFLAGS) $(SRCS) -o $(NAME)
			@echo "\033[1;32m zombieHorde executable is compiled and ready.\e[0m"

clean:		
			@rm -f $(OBJS)
			@echo "\033[1;36m .o files successfully deleted.\e[0m"

fclean: 	clean
			@rm -f  ${OBJS} $(NAME)
			@echo "\033[1;36m zombieHorde executable successfully deleted.\e[0m"

re: fclean ${NAME}

.PHONY: clean fclean all re