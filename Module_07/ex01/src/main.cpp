/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 13:16:53 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/01 13:30:36 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>
#include <iostream>

template<typename T>
void	test(T &value)
{
	std::cout << value << " " << std::endl;
}

int	main(void)
{
	std::string	weekDays[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int			dayOfWeek[] = {0, 1, 2, 3, 4, 5, 6};

	iter(weekDays, 7, test<std::string>);
	iter(dayOfWeek, 7, test<int>);
	return (0);
}
