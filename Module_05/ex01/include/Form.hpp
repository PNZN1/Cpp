/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:38:47 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/04 08:29:17 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	mName;
		bool				mSigned;
		const int			mSignGrade;
		const int			mExecGrade;

	public:
		// Constructors
		Form();
		Form(const Form &copy);
		Form(const std::string name, const int signGrade, const int execGrade);
		// Destructor
		~Form();
		// Operators
		Form & operator=(const Form &assign);

		// Member functions
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		void		beSigned(const Bureaucrat &b);

		// Exceptions
		class	GradeTooHighException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

// Insertion overload
std::ostream &operator<<(std::ostream &out, const Form &f);

#endif
