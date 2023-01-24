# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pniezen <pniezen@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2023/01/17 12:41:57 by pniezen       #+#    #+#                  #
#    Updated: 2023/01/22 14:10:57 by pniezen       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ex_01

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98


SRCD = src/
SRC = main.cpp Contact.cpp PhoneBook.cpp
SRCP = $(addprefix $(SRCD), $(SRC))

OBJD = obj/
OBJP = $(addprefix $(OBJD), $(SRC:.cpp=.o))

INCD = include/
INC = Contact.hpp PhoneBook.hpp
INCP = $(addprefix $(INCD), $(INC))

CFLAGS += -I $(INCD)

all: $(NAME)

$(OBJD)%.o: $(SRCD)%.cpp $(INCP)
	@mkdir -p $(@D)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJP)
	@echo "Compiling main executable"
	@$(CC) $(CFLAGS) $(OBJP) -o $(NAME)

clean:
	@rm -rf $(OBJD)
	@echo "Cleaning"

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all
