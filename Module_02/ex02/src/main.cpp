/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/28 11:36:45 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/28 15:27:47 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Fixed.hpp>
#include <iostream>

int	main(void)
{
	Fixed	a;
	Fixed	const b(Fixed(5.05f) * Fixed(2));
	Fixed	c;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "b / 2 = " << b / 2 << std::endl;

	std::cout << std::endl;

	if (a > b)
		std::cout << "a is greater then b" << std::endl;
	if (a < b)
		std::cout << "a is smaller then b" << std::endl;
	else
		std::cout << "a is equal to b" << std::endl;

	if (a >= b)
		std::cout << "a is greater or equal to b" << std::endl;
	if (a <= b)
		std::cout << "a is smaller or equal to b" << std::endl;

	std::cout << std::endl;

	a = 0;
	c = 0;
	if (a == c)
		std::cout << "a is equal to c" << std::endl;

	a = 1;
	if (a != c)
		std::cout << "a is not equal to c" << std::endl;


	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;

	std::cout << std::endl;

	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << std::endl;

	std::cout << std::endl;

	std::cout << Fixed::min(a, c) << std::endl;
	std::cout << Fixed::max(a, c) << std::endl;
	return (0);
}
