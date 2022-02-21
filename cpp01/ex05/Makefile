CXX			= @c++

CXXFLAGS	= -Wall -Werror -Wextra -g -std=c++98

NAME 		= karen

SRCS		= ./main.cpp \
				./Karen.cpp 

INCL		= ./Karen.hpp 

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCL)
			$(CXX) $(CFLAGS) $(SRCS) -o $(NAME)
			@echo "\033[1;32m karen executable is compiled and ready.\e[0m"

clean:		
			@rm -f $(OBJS)
			@echo "\033[1;36m .o files successfully deleted.\e[0m"

fclean: 	clean
			@rm -f  ${OBJS} $(NAME)
			@echo "\033[1;36m karen executable successfully deleted.\e[0m"

re: fclean ${NAME}

.PHONY: clean fclean all re