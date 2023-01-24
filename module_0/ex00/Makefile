# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pniezen <pniezen@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/17 12:41:57 by pniezen       #+#    #+#                  #
#    Updated: 2023/01/22 12:19:13 by pniezen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_NAME = megaphone.cpp

OBJ_PATH = ./obj/
OBJ = $(addprefix $(OBJ_PATH), $(SRC_NAME:.cpp=.o))

GREEN = \033[32;1m
RED	= \033[31;1m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(LIB) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@echo "$(GREEN)Compiling$(RESET)"
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -o $@ -c $<

clean: 
	@echo "$(RED)Cleaning$(RESET)"
	@rm -f $(OBJ)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -fv $(NAME)

re: fclean all

.PHONY: clean fclean re all
