/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/13 08:15:28 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/15 13:26:23 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors
ClapTrap::ClapTrap() : _name(""), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "Default Constructor called of ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;

	std::cout << "Copy Constructor called of ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hit_points, unsigned int energy_points, unsigned int attack_damage)
	: _name(name), _hit_points(hit_points), _energy_points(energy_points), _attack_damage(attack_damage)
{
	std::cout << "Parameter Constructor called of ClapTrap" << std::endl;
}


// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called of ClapTrap" << std::endl;
}


// Operators
ClapTrap & ClapTrap::operator=(const ClapTrap &assign)
{
	this->_name = assign._name;
	this->_hit_points = assign._hit_points;
	this->_energy_points = assign._energy_points;
	this->_attack_damage = assign._attack_damage;
	return (*this);
}

// Private functions
bool	ClapTrap::_CanTakeAction(void) const
{
	if (this->_hit_points == 0)
	{
		std::cout << this->_name << " is DEATH R.I.P." << std::endl;
		return false;
	}
	else if (this->_energy_points == 0)
	{
		std::cout << this->_name << " does not have enough energy to do any action " << std::endl;
		return false;
	}
	return true;
}

// Member functions
void	ClapTrap::attack(const std::string& target)
{
	if (!this->_CanTakeAction())
		return ;

	std::cout << "[ATTACK]" << std::endl;
	std::cout << this->_name << " attacks " << target
			<< ", causing " << this->_attack_damage << " points of damage!" << std::endl;
	this->_energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "[DAMAGE]" << std::endl;
	if (this->_hit_points == 0)
		std::cout << this->_name << " is already DEATH R.I.P." << std::endl;
	else if (amount >= this->_hit_points)
	{
		std::cout << this->_name << " died R.I.P." << std::endl;
		this->_hit_points = 0;
	}
	else
	{
		this->_hit_points -= amount;
		std::cout << this->_name << " lost [" << amount << "] damage points" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_CanTakeAction())
		return ;

	std::cout << "[REPAIRED]" << std::endl;
	std::cout << this->_name << " repaired [" << amount << "] hit points" << std::endl;
	this->_hit_points += amount;
	this->_energy_points--;
}


// Getters
std::string		ClapTrap::getName(void) const {return (this->_name);}
unsigned int	ClapTrap::getHitPoints(void) const {return (this->_hit_points);}
unsigned int	ClapTrap::getEnergyPoints(void) const {return (this->_energy_points);}
unsigned int	ClapTrap::getAttackDamages(void) const {return (this->_attack_damage);}


std::ostream &operator<<(std::ostream &out, const ClapTrap &clapTrap)
{
	out << "ClapTrap object info:" << std::endl;
	out << "---------------------" << std::endl;
	out << "Name:\t\t\t" << clapTrap.getName() << std::endl;
	out << "Current Hit points:\t" << clapTrap.getHitPoints() << std::endl;
	out << "Current Energy:\t\t" << clapTrap.getEnergyPoints() << std::endl;
	out << "Attack Damage:\t\t" << clapTrap.getAttackDamages() << std::endl;
	return out;
}
