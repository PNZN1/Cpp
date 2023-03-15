/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 14:25:39 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/15 13:18:29 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <FragTrap.hpp>

int	main(void)
{
	FragTrap	bob("bob");
	FragTrap	alice("alice");

	std::cout << std::endl;
	bob.attack(alice.getName());
	alice.takeDamage(bob.getAttackDamages());

	std::cout << std::endl;
	bob.highFivesGuys();

	std::cout << std::endl;
	std::cout << bob << std::endl;
	std::cout << alice << std::endl;
	return (0);
}
