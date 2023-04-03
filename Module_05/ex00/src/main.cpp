/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 08:04:45 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/03 09:35:41 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "========== CASE 1 ==========" << std::endl << std::endl;
	std::cout << "----- INCREMENT GRADE -----" << std::endl;

	Bureaucrat	b;

	std::cout << b << std::endl;
	for (int i = 0; i < 4; i++)
	{
		b.increment();
		std::cout << b << std::endl;
	}
	std::cout << "========== END CASE ==========" << std::endl << std::endl << std::endl;


	std::cout << "========== CASE 2 ==========" << std::endl << std::endl;
	std::cout << "----- DECREMENT GRADE -----" << std::endl;

	std::cout << b << std::endl;
	try
	{
		for (int i = 5; i > 0; i--)
		{
			b.decrement();
			std::cout << b << std::endl;
		}
		b.decrement();
	}
	catch (std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << std::endl;
	}
	std::cout << "========== END CASE ==========" << std::endl << std::endl << std::endl;


	std::cout << "========== CASE 3 ==========" << std::endl << std::endl;
	std::cout << "----- INSTANTIATE OUT OF RANGE -----" << std::endl;
	try
	{
		Bureaucrat	b2("Herman", 151);
	}
	catch (std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << std::endl;
	}
	std::cout << "========== END CASE ==========" << std::endl << std::endl << std::endl;


	std::cout << "========== CASE 4 ==========" << std::endl << std::endl;
	std::cout << "----- INSTANTIATE OUT OF RANGE -----" << std::endl;
	try
	{
		Bureaucrat	b3("Frank", 0);
	}
	catch (std::exception& e)
	{
		std::cerr << "exception caught: " << e.what() << std::endl;
	}
	std::cout << "========== END CASE ==========" << std::endl << std::endl << std::endl;


	std::cout << "========== CASE 5 ==========" << std::endl << std::endl;
	std::cout << "----- DECREMENT GRADE -----" << std::endl;

	Bureaucrat	b4("Pete", 1);

	std::cout << b4 << std::endl;
	for (int i = 0; i < 4; i++)
	{
		b4.decrement();
		std::cout << b4 << std::endl;
	}
	std::cout << "========== END CASE ==========" << std::endl << std::endl << std::endl;
	return (0);
}
