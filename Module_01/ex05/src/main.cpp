/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 09:27:09 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/27 11:51:54 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Harl.hpp>

int	main(void)
{
	Harl	logger = Harl();

	logger.complain("DEBUG");
	logger.complain("INFO");
	logger.complain("WARNING");
	logger.complain("ERROR");

	logger.complain("EXCEPTION");
	return (0);
}
