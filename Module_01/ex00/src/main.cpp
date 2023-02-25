/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 10:29:31 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 12:24:39 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int main(void)
{
	Zombie	zombie_1("Foo");
	Zombie	*zombie_2;

	zombie_1.announce();
	randomChump("Bar");
	zombie_2 = newZombie("Foo Bar");
	zombie_2->announce();
	delete zombie_2;
	return (0);
}
