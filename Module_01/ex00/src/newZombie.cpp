/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 11:10:26 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 12:38:43 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>
#include <iostream>
#include <exception>

Zombie	*newZombie(std::string name)
{
	Zombie	*zombie;

	try
	{
		zombie = new Zombie(name);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
	}
	return (zombie);
}
