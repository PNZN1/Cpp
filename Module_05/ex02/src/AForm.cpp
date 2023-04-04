/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:58:28 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/04 08:54:56 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructors
AForm::AForm() :
	mName("blanc"),
	mSigned(false),
	mSignGrade(150),
	mExecGrade(150)
{
	std::cout << "Default Constructor called of AForm " << this->mName << std::endl;
}

AForm::AForm(const AForm &copy):
	mName(copy.getName()),
	mSigned(copy.getSigned()),
	mSignGrade(copy.getSignGrade()),
	mExecGrade(copy.getExecGrade())
{
	std::cout << "Copy Constructor called AForm " << this->mName << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) :
	mName(name),
	mSigned(false),
	mSignGrade(signGrade),
	mExecGrade(execGrade)
{
	std::cout << "Parameter Constructor called of AForm " << this->mName << std::endl;

	if (this->mSignGrade < 1 || this->mExecGrade < 1)
		throw(GradeTooHighException());
	if (this->mSignGrade > 150 || this->mExecGrade > 150)
		throw(GradeTooLowException());
}

// Destructor
AForm::~AForm()
{
	std::cout << "Destructor called of AForm " << this->mName << std::endl;
}


// Operators
AForm & AForm::operator=(const AForm &assign)
{
	this->mSigned = assign.getSigned();
	return (*this);
}


// Member functions
std::string	AForm::getName(void) const
{
	return (this->mName);
}

bool	AForm::getSigned(void) const
{
	return (this->mSigned);
}

int	AForm::getSignGrade(void) const
{
	return (this->mSignGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->mExecGrade);
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->mSignGrade)
		throw(GradeTooLowException());

	this->mSigned = true;
}



// Exceptions
const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade to high.");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade to low.");
}


// Insertion overload
std::ostream &operator<<(std::ostream &out, const AForm &f)
{
	out << "-       Form: " << f.getName() << std::endl;
	out << "- Sign Grade: " << f.getSignGrade() << std::endl;
	out << "- Exec Grade: " << f.getExecGrade() << std::endl;
	out << "-     Signed: " << f.getSigned() << std::endl;
	return (out);
}
