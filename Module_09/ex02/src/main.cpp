/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 12:28:30 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/17 16:39:46 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);

	PmergeMe	sortMe(argv);

	sortMe.printBefore();
	sortMe.sortDeque(0, sortMe.getDequeSize() - 1);

	sortMe.printAfter();
	return (0);
}
