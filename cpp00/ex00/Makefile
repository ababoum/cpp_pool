CC			= @c++

CFLAGS		= -Wall -Werror -Wextra -std=c++98

NAME 		= megaphone

SRCS		= ./megaphone.cpp

OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
			@echo "\033[1;32m Executable is compiled and ready.\e[0m"

clean:		
			@rm -f $(OBJS)
			@echo "\033[1;36m .o files successfully deleted.\e[0m"

fclean: 	clean
			@rm -f  ${OBJS} $(NAME)
			@echo "\033[1;36m Executable successfully deleted.\e[0m"

re: fclean ${NAME}

.PHONY: clean fclean all re
