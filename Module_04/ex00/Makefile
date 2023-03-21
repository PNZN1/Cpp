# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pniezen <pniezen@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/28 09:55:20 by pniezen       #+#    #+#                  #
#    Updated: 2023/03/21 11:00:39 by pniezen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = poly

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


SRCD = src/
SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
SRCP = $(addprefix $(SRCD), $(SRC))

OBJD = obj/
OBJP = $(addprefix $(OBJD), $(SRC:.cpp=.o))

INCD = include/
INC = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp
INCP = $(addprefix $(INCD), $(INC))

CFLAGS += -I $(INCD)

all: $(NAME)

$(NAME): $(OBJP)
	@echo "Compiling main executable"
	@$(CC) $(CFLAGS) $(OBJP) -o $(NAME)

$(OBJD)%.o: $(SRCD)%.cpp $(INCP)
	@mkdir -p $(@D)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@rm -rf $(OBJD)
	@echo "Cleaning"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all
