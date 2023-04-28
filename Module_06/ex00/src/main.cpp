/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 10:22:45 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/28 14:42:38 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		std::cout << "Invalid argument" << std::endl;
	else
		ScalarConverter::convert(static_cast<std::string>(argv[1]));
	return (0);
}
