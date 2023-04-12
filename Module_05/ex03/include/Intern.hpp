/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/12 09:39:53 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/12 09:51:39 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Intern
{
	private:
		typedef struct s_form
		{
			std::string	type;
			u_int8_t	id;
		}	t_form;

	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		// Destructor
		~Intern();
		// Operators
		Intern & operator=(const Intern &assign);

		// Member Function
		AForm	*makeForm(std::string form, std::string name) const;

		// Exceptions
		class FormNotFound : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
