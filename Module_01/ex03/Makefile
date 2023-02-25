# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pniezen <pniezen@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/17 12:41:57 by pniezen       #+#    #+#                  #
#    Updated: 2023/02/25 15:05:05 by pniezen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ex03

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


SRCD = src/
SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
SRCP = $(addprefix $(SRCD), $(SRC))

OBJD = obj/
OBJP = $(addprefix $(OBJD), $(SRC:.cpp=.o))

INCD = include/
INC = Weapon.hpp HumanA.hpp HumanB.hpp
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
