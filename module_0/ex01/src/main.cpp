/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/22 11:34:30 by pniezen       #+#    #+#                 */
/*   Updated: 2023/01/24 14:16:59 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>

int	main(void)
{
	PhoneBook	book;
	std::string	buf;

	while (1)
	{
		std::cout << "Enter one of these commands 'ADD' 'SEARCH' 'EXIT'" << std::endl;
		std::cin >> buf;
		if (!book.do_command(buf))
			break ;
	}
	return (0);
}
