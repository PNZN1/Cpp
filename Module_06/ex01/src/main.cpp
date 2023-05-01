/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 10:01:19 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/01 10:32:22 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		data;
	Data		*data2;

	data.num = 10;
	data.str = "Text";

	data2 = Serializer::deserialize(Serializer::serialize(&data));

	std::cout << "---- Before serializer ----" << std::endl;
	std::cout << "address data: " << &data << std::endl;
	std::cout << "num: " << data.num << std::endl;
	std::cout << "str: " << data.str << std::endl << std::endl;

	std::cout << "---- After serializer ----" << std::endl;
	std::cout << "address data2: " << data2 << std::endl;
	std::cout << "num: " << data2->num << std::endl;
	std::cout << "str: " << data2->str << std::endl;
	return (0);
}
