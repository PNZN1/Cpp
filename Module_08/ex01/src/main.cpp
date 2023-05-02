/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 08:46:21 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/02 14:00:08 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

int	main(void)
{
	{
		std::cout << "---- Simple Spawn ----" << std::endl;
		Span	span(5);

		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);

		std::cout << "shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "longest span: " << span.longestSpan() << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "---- CASE: Maximum Size ----" << std::endl;
		Span	span(5);

		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);
		try
		{
			span.addNumber(11);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	{
		std::cout << "---- CASE: Minimum Size ----" << std::endl;
		Span	span(1);

		span.addNumber(6);
		try
		{
			span.addNumber(11);
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	{
		std::cout << "---- CASE: No Span ----" << std::endl;
		Span	span(1);

		try
		{
			std::cout << "shortest span: " << span.shortestSpan() << std::endl;
			std::cout << "longest span: " << span.longestSpan() << std::endl;

		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	{
		std::cout << "---- CASE: Many Numbers ----" << std::endl;
		Span	span(100000);

		span.insertMany();
		std::cout << "shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "longest span: " << span.longestSpan() << std::endl;
		std::cout << "position[0]: " << span.getVector()[0] << std::endl;
		std::cout << "position[100]: " << span.getVector()[100] << std::endl;
		std::cout << "position[1000]: " << span.getVector()[1000] << std::endl;
		std::cout << "position[100000]: " << span.getVector()[100000] << std::endl;
	}
	return (0);
}
