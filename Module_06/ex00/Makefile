# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pniezen <pniezen@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/03 08:04:19 by pniezen       #+#    #+#                  #
#    Updated: 2023/04/24 10:27:22 by pniezen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = convert

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


SRCD = src/
SRC = main.cpp ScalarConverter.cpp
SRCP = $(addprefix $(SRCD), $(SRC))

OBJD = obj/
OBJP = $(addprefix $(OBJD), $(SRC:.cpp=.o))

INCD = include/
INC = ScalarConverter.hpp
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
