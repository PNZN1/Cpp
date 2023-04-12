/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 16:06:39 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/12 10:24:09 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Presidential Pardon Form", 25, 5),
	mTarget("Default")
{
	std::cout << "Default Constructor callef of PresidentialPardonForm " << this->mTarget << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) :
	AForm(copy.getTarget(), 25, 5),
	mTarget(copy.getTarget())
{
	std::cout << "Copy Constuctor called of PresidentialPardonForm " << this->mTarget << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("Presidential Pardon Form", 25, 5),
	mTarget(target)
{
	std::cout << "Parameter Constructor called of PresidentialPardonForm " << this->mTarget << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor called of PresidentialPardonForm " << this->mTarget << std::endl;
}


// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	this->mTarget = assign.getTarget();
	return (*this);
}


// Member functions
std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->mTarget);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > this->getExecGrade())
			throw(GradeTooLowException());
		if (!this->getSigned())
			throw(FormNotSigned());

		std::cout << this->mTarget << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
	catch(const GradeTooLowException& e)
	{
		std::cerr << this->getName() << " couldn’t execute " << executor.getName() << " because " << e.what() << std::endl;
	}
	catch(const FormNotSigned& e)
	{
		std::cerr << this->getName() << " couldn’t execute " << executor.getName() << " because " << e.what() << std::endl;
	}
}
