/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 13:38:47 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/04 09:15:14 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	mName;
		bool				mSigned;
		const int			mSignGrade;
		const int			mExecGrade;

	public:
		// Constructors
		AForm();
		AForm(const AForm &copy);
		AForm(const std::string name, const int signGrade, const int execGrade);
		// Destructor
		virtual ~AForm();
		// Operators
		AForm & operator=(const AForm &assign);

		// Member functions
		std::string	getName(void) const;
		bool		getSigned(void) const;
		int			getSignGrade(void) const;
		int			getExecGrade(void) const;
		void		beSigned(const Bureaucrat &b);
		virtual void		execute(Bureaucrat const & executor) const = 0;

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
std::ostream &operator<<(std::ostream &out, const AForm &f);

#endif
