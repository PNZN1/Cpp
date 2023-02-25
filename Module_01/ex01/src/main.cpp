/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 12:30:20 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 13:36:00 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

int	main(void)
{
	int		n;
	Zombie	*zombies;

	n = 3;
	zombies = zombieHorde(n, "Foo");
	for (int i = 0; i < n; i++)
		zombies->announce();
	delete [] zombies;
	return (0);
}
