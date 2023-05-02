/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 15:39:52 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/01 17:46:39 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main(void)
{
	std::cout << "---- easyfind intArray ----" << std::endl;
	int	intArray[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int>	intVector(intArray, intArray + sizeof(intArray) / sizeof(int));

	try
	{
		std::cout << "found: " << *easyfind(intVector, 9) << std::endl;
		std::cout << "found: " << *easyfind(intVector, 30) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
