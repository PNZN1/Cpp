/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 13:59:47 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/01 14:40:34 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	{
		std::cout << "---- Int Array ----" << std::endl;
		Array<int>	intArray(10);
		std::cout << "Size: " << intArray.size() << std::endl;
		for(int i = 0; i < static_cast<int>(intArray.size()); i++)
		{
			intArray.setArray(i, i);
			std::cout << "Value: " << intArray[i] << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "---- String Array ----" << std::endl;
		Array<std::string>	strArray(7);
		std::cout << "Size: " << strArray.size() << std::endl;
		std::string	weekDays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		for(int i = 0; i < static_cast<int>(strArray.size()); i++)
		{
			strArray.setArray(i, weekDays[i]);
			std::cout << "Value: " << strArray[i] << std::endl;
		}
		std::cout << std::endl;
	}

	{
		std::cout << "---- Float Array ----" << std::endl;
		Array<float>	floatArray(6);
		std::cout << "Size: " << floatArray.size() << std::endl;
		float	randomFloats[] = {0.1, 0.2, 0.3, 0.4, 1.5, 6.0};
		for(int i = 0; i < static_cast<int>(floatArray.size()); i++)
		{
			floatArray.setArray(i, randomFloats[i]);
			std::cout << "Value: " << floatArray[i] << std::endl;
		}
		std::cout << std::endl;
	}
	return (0);
}
