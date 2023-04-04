/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 16:05:45 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/04 16:06:28 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string	mTarget;

	public:
		// Constructors
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm(std::string target);
		// Destructor
		~PresidentialPardonForm();
		// Operators
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);

		// Member functions
		std::string	getTarget(void) const;
		void	execute(Bureaucrat const & executor) const;
};

#endif
