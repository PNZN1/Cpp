/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/01 14:25:39 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/13 13:32:31 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ClapTrap.hpp>

int	main(void)
{
	ClapTrap	bob("bob");
	ClapTrap	alice("alice");
	ClapTrap	duke;

	duke = ClapTrap("duke");

	// check if the copied correctly
	std::cout << std::endl;
	std::cout << "bob: " << bob << std::endl;
	std::cout << "alice: " << alice << std::endl;
	std::cout << "duke: " << duke << std::endl;

	// attacking
	std::cout << std::endl;
	bob.attack(alice.getName());
	alice.takeDamage(5);
	bob.attack(alice.getName());
	alice.takeDamage(5);
	alice.beRepaired(100);

	// out of energy
	std::cout << std::endl;
	bob.attack(alice.getName());
	bob.attack(alice.getName());
	bob.attack(alice.getName());
	bob.attack(alice.getName());
	bob.attack(alice.getName());
	bob.attack(alice.getName());
	bob.attack(alice.getName());
	bob.attack(alice.getName());
	bob.attack(alice.getName());


	// end check
	std::cout << std::endl;
	std::cout << "bob: " << bob << std::endl;
	std::cout << "alice: " << alice << std::endl;
	std::cout << "duke: " << duke << std::endl;
	return (0);
}
