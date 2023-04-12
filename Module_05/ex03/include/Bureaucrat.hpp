/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 08:06:06 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/04 11:27:38 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	mName;
		int					mGrade;

	public:
		// Constructors
		Bureaucrat();
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat(const std::string name, const int grade);
		// Destructor
		~Bureaucrat();
		// Operators
		Bureaucrat & operator=(const Bureaucrat &assign);

		// Member functions
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		increment(void);
		void		decrement(void);
		void		signForm(AForm &f);
		void		executeForm(AForm const & f);

		// Exceptions
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

// Insertion overload
std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif
