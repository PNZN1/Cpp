/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 14:25:39 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/15 13:11:19 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ScavTrap.hpp>

int	main(void)
{
	ScavTrap	bob("bob");
	ScavTrap	alice("alice");

	std::cout << std::endl;
	bob.attack(alice.getName());
	alice.takeDamage(bob.getAttackDamages());

	std::cout << std::endl;
	bob.guardGate();

	std::cout << std::endl;
	std::cout << bob << std::endl;
	std::cout << alice << std::endl;
	return (0);
}
