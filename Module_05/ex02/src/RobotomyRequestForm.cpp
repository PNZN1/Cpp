/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 12:55:09 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/12 10:57:51 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <time.h>

// Constructors
RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy Request Form", 72, 45),
	mTarget("Default")
{
	std::cout << "Default Constructor callef of RobotomyRequestForm " << this->mTarget << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) :
	AForm(copy.getTarget(), 72, 45),
	mTarget(copy.getTarget())
{
	std::cout << "Copy Constuctor called of RobotomyRequestForm " << this->mTarget << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm(target, 72, 45),
	mTarget(target)
{
	std::cout << "Parameter Constructor called of RobotomyRequestForm " << this->mTarget << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor called of RobotomyRequestForm " << this->mTarget << std::endl;
}


// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	this->mTarget = assign.getTarget();
	return (*this);
}


// Member functions
std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->mTarget);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > this->getExecGrade())
			throw(GradeTooLowException());
		if (!this->getSigned())
			throw(FormNotSigned());

		std::cout << "DRILLING NOISE!!!!" << std::endl;

		srand(time(NULL));
		int	random = rand();
		if (random %2 == 0)
			std::cout << this->mTarget << " has been robotomized" << std::endl;
		else
			std::cout << "robotomy failed" << std::endl;
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
