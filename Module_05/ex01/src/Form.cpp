/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:58:28 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/04 08:54:56 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructors
Form::Form() :
	mName("Form"),
	mSigned(false),
	mSignGrade(150),
	mExecGrade(150)
{
	std::cout << "Default Constructor called of Form " << this->mName << std::endl;
}

Form::Form(const Form &copy):
	mName(copy.getName()),
	mSigned(copy.getSigned()),
	mSignGrade(copy.getSignGrade()),
	mExecGrade(copy.getExecGrade())
{
	std::cout << "Copy Constructor called Form " << this->mName << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade) :
	mName(name),
	mSignGrade(signGrade),
	mExecGrade(execGrade)
{
	std::cout << "Parameter Constructor called of Form " << this->mName << std::endl;

	if (this->mSignGrade < 1 || this->mExecGrade < 1)
		throw(GradeTooHighException());
	if (this->mSignGrade > 150 || this->mExecGrade > 150)
		throw(GradeTooLowException());
}

// Destructor
Form::~Form()
{
	std::cout << "Destructor called of Form " << this->mName << std::endl;
}


// Operators
Form & Form::operator=(const Form &assign)
{
	this->mSigned = assign.getSigned();
	return (*this);
}


// Member functions
std::string	Form::getName(void) const
{
	return (this->mName);
}

bool	Form::getSigned(void) const
{
	return (this->mSigned);
}

int	Form::getSignGrade(void) const
{
	return (this->mSignGrade);
}

int	Form::getExecGrade(void) const
{
	return (this->mExecGrade);
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->mSignGrade)
		throw(GradeTooLowException());

	this->mSigned = true;
}



// Exceptions
const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade to high.");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade to low.");
}


// Insertion overload
std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "-       Form: " << f.getName() << std::endl;
	out << "- Sign Grade: " << f.getSignGrade() << std::endl;
	out << "- Exec Grade: " << f.getExecGrade() << std::endl;
	out << "-     Signed: " << f.getSigned() << std::endl;
	return (out);
}
