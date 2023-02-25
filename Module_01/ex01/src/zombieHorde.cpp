/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 12:31:53 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 13:38:38 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>
#include <iostream>

Zombie*	zombieHorde(int N, std::string name)
{
	if (N < 1)
	{
		std::cout << "N must be > 0 of course!" << std::endl;
		exit(1);
	}
	Zombie	*zombie;
	zombie = new (std::nothrow) Zombie [N];
	if (!zombie)
	{
		std::cout << "Error: memory could not be allocated." << std::endl;
		exit(1);
	}
	for (int i = 0; i < N; i++)
		zombie[i].setName(name);
	return (zombie);
}
