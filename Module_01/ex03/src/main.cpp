/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 13:57:48 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/25 15:17:38 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Weapon.hpp>
#include <HumanA.hpp>
#include <HumanB.hpp>

int main(void)
{
	Weapon	gun = Weapon("gun");
	Weapon	rifle = Weapon("rifle");
	HumanA	bob = HumanA("bob", gun);
	HumanB	alice = HumanB("alice");

	bob.attack();
	alice.attack();

	alice.setWeapon(rifle);
	alice.attack();
	return (0);
}
