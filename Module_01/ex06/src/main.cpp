/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 09:27:09 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/27 14:53:59 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>
#include <iostream>

int	main(int argc, char **argv)
{
	Harl	logger = Harl();

	if (argc == 1)
	{
		logger.complain("blabla");
		exit(1);
	}

	logger.complain(argv[1]);
	return (0);
}
