/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 09:19:04 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/04 11:09:59 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	mTarget;

	public:
		// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm(std::string target);
		// Destructor
		~ShrubberyCreationForm();
		// Operators
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);

		// Member functions
		std::string	getTarget(void) const;
		void	execute(Bureaucrat const & executor) const;

		// Exceptions
		class	ShrubberyCreationFormNotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	FileCreationError : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
