CXX			= @c++

CXXFLAGS	= -Wall -Werror -Wextra -g -std=c++98

NAME 		= ptr_ref

SRCS		= ./main.cpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(INCL)
			$(CXX) $(CFLAGS) $(SRCS) -o $(NAME)
			@echo "\033[1;32m ptr_ref executable is compiled and ready.\e[0m"

clean:		
			@rm -f $(OBJS)
			@echo "\033[1;36m .o files successfully deleted.\e[0m"

fclean: 	clean
			@rm -f  ${OBJS} $(NAME)
			@echo "\033[1;36m ptr_ref executable successfully deleted.\e[0m"

re: fclean ${NAME}

.PHONY: clean fclean all re