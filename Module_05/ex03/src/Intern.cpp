/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 09:51:58 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/12 10:31:43 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "Default Construcotr called of Intern" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Copy Constructor callef of Intern" << std::endl;
	*this = copy;
}

// Destructor
Intern::~Intern()
{
	std::cout << "Destructor called of Intern" << std::endl;
}


// Operator
Intern & Intern::operator=(const Intern &assign)
{
	std::cout << "Intern Assignment operator called" << std::endl;
	(void)assign;
	return (*this);
}


// Member function
AForm	*Intern::makeForm(std::string type, std::string name) const
{
	t_form	forms[3] = {
		{"shrubbery creation form", 0},
		{"robotomy request form", 1},
		{"presidential pardon form", 2}
	};

	int i;
	for (i = 0;  i < 3; i++)
	{
		if (type == forms[i].type)
			break;
	}

	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << type << std::endl;
			return (new ShrubberyCreationForm(name));
		case 1:
			std::cout << "Intern creates " << type << std::endl;
			return (new RobotomyRequestForm(name));
		case 2:
			std::cout << "Intern creates " << type << std::endl;
			return (new PresidentialPardonForm(name));
		default:
			throw(FormNotFound());
	}
}


// Exception
const char	*Intern::FormNotFound::what() const throw()
{
	return ("Form not found.");
}
