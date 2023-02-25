/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 11:54:15 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 12:21:33 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

void	randomChump(std::string name)
{
	Zombie	zombie(name);
	zombie.announce();
}
