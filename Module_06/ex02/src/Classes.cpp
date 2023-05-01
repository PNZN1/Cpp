/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Classes.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 11:24:32 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/01 12:10:09 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"
#include <iostream>

Base::~Base() {};

Base	*generate(void)
{
	int	i;

	srand(time(NULL));
	i = rand() % 3;
	switch (i)
	{
		case 0:
			return (reinterpret_cast<Base *>(new A));
		case 1:
			return (reinterpret_cast<Base *>(new B));
		case 2:
			return (reinterpret_cast<Base *>(new C));
	}
	return (reinterpret_cast<Base *>(new A));
}

void	identify(Base* p)
{
	A	*a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << "Object points to A" << std::endl;
		return ;
	}

	B	*b = dynamic_cast<B *>(p);
	if (b)
	{
		std::cout << "Object points to B" << std::endl;
		return ;
	}

	C	*c = dynamic_cast<C *>(p);
	if (c)
	{
		std::cout << "Object points to C" << std::endl;
		return ;
	}

	std::cout << "No object found that points to either A, B or C" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A	&a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "Object is reference of A" << std::endl;
	}
	catch(const std::bad_cast& e) {}
	try
	{
		B	&b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "Object is reference of B" << std::endl;
	}
	catch(const std::bad_cast& e) {}
	try
	{
		C	&c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "Object is reference of C" << std::endl;
	}
	catch(const std::bad_cast& e) {}
}
