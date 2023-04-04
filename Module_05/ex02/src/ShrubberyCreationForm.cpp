/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 09:29:25 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/04 11:51:24 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shrubbery Creation Form", 145, 137),
	mTarget("Default")
{
	std::cout << "Default Constructor callef of ShrubberyCreationForm " << this->mTarget << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) :
	AForm(copy.getTarget(), 145, 137),
	mTarget(copy.getTarget())
{
	std::cout << "Copy Constuctor called of ShrubberyCreationForm " << this->mTarget << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("Shrubbery Creation Form", 145, 137),
	mTarget(target)
{
	std::cout << "Parameter Constructor called of ShrubberyCreationForm " << this->mTarget << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor called of ShrubberyCreationForm " << this->mTarget << std::endl;
}


// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	this->mTarget = assign.getTarget();
	return (*this);
}


// Member functions
std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->mTarget);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (executor.getGrade() > this->getExecGrade())
			throw(GradeTooLowException());
		if (!this->getSigned())
			throw(ShrubberyCreationFormNotSigned());
		std::cout << this->getName() << " executed " << executor.getName() << std::endl;

		std::ofstream	file(this->mTarget + "_shrubbery");

		if (!file)
			throw(FileCreationError());

		file << "|     .-." << std::endl;
		file << "|    /   \\         .-." << std::endl;
		file << "|   /     \\       /   \\       .-.     .-.     _   _" << std::endl;
		file << "+--/-------\\-----/-----\\-----/---\\---/---\\---/-\\-/-\\/\\/---" << std::endl;
		file << "| /         \\   /       \\   /     '-'     '-'" << std::endl;
		file << "|/           '-'         '-'" << std::endl;

		file.close();
	}
	catch(const GradeTooLowException& e)
	{
		std::cout << this->getName() << " couldn’t execute " << executor.getName() << " because " << e.what() << std::endl;
	}
	catch(const ShrubberyCreationFormNotSigned& e)
	{
		std::cout << this->getName() << " couldn’t execute " << executor.getName() << " because " << e.what() << std::endl;
	}
	catch(const FileCreationError& e)
	{
		std::cout << this->getName() << " couldn’t execute " << executor.getName() << " because " << e.what() << std::endl;
	}
}


// Exceptions
const char	*ShrubberyCreationForm::ShrubberyCreationFormNotSigned::what() const throw()
{
	return ("Shrubbery Creation Form not signed.");
}

const char	*ShrubberyCreationForm::FileCreationError::what() const throw()
{
	return ("Could not sign form due to some uncommon error.");
}
