/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 13:45:44 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 13:54:53 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	stringVAR = "HI THIS IS BRAIN";
	std::string	*stringPTR = &stringVAR;
	std::string	&stringREF = stringVAR;

	std::cout << "stringVAR memory address " << &stringVAR << std::endl;
	std::cout << "stringPTR memory address " << stringPTR << std::endl;
	std::cout << "stringREF memory address " << &stringREF << std::endl;

	std::cout << "stringVAR value " << stringVAR << std::endl;
	std::cout << "stringPTR value " << *stringPTR << std::endl;
	std::cout << "stringREF value " << stringREF << std::endl;
	return (0);
}
