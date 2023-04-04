/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 08:13:19 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/04 11:50:14 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() :
	mName("Thor"),
	mGrade(150)
{
	std::cout << "Default Constructor called of Bureaucrat " << this->getName() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) :
	mName(copy.getName()), mGrade(copy.getGrade())
{
	std::cout << "Copy Constructor called Bureaucrat " << this->getName() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, const int grade) :
	mName(name),
	mGrade(grade)
{
	std::cout << "Parameter Constructor called of Bureaucrat " << this->getName() << std::endl;

	if (this->mGrade < 1)
		throw(GradeTooHighException());
	if (this->mGrade > 150)
		throw(GradeTooLowException());
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called of Bureaucrat " << this->getName() << std::endl;
}


// Operators
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	this->mGrade = assign.getGrade();
	return (*this);
}


// Member functions
std::string	Bureaucrat::getName(void) const
{
	return (this->mName);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->mGrade);
}

void	Bureaucrat::increment(void)
{
	if (this->mGrade == 1)
		throw(GradeTooHighException());
	this->mGrade--;
}

void	Bureaucrat::decrement(void)
{
	if (this->mGrade == 150)
		throw(GradeTooLowException());
	this->mGrade++;
}

void	Bureaucrat::signForm(AForm &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->mName << " signed " << f.getName() << std::endl;
	}
	catch(const GradeTooHighException& e)
	{
		std::cout << this->mName << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl;
	}
	catch(const GradeTooLowException& e)
	{
		std::cout << this->mName << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & f)
{
	return (f.execute(*this));
}


// Exceptions
const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade to high.");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade to low.");
}


// Insertion overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b)
{
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return (out);
}
