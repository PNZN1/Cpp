/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 14:09:51 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/15 15:11:44 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);

try
	{
		RPN	numbers;
		for (int i = 0; argv[1][i]; i++)
		{
			if (std::isdigit(argv[1][i]))
				numbers.pushNumber(argv[1][i] - 48);
			else if (argv[1][i] == '+')
				numbers.operation('+');
			else if (argv[1][i] == '-')
				numbers.operation('-');
			else if (argv[1][i] == '*')
				numbers.operation('*');
			else if (argv[1][i] == '/')
				numbers.operation('/');
			else if (argv[1][i] != ' ')
				throw(std::invalid_argument("Error"));
		}
		std::cout << numbers << std::endl;
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
