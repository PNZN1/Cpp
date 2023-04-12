/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/04 12:51:19 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/04 13:38:20 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string	mTarget;

	public:
		// Constructors
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm(std::string target);
		// Destructor
		~RobotomyRequestForm();
		// Operators
		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);

		// Member functions
		std::string	getTarget(void) const;
		void	execute(Bureaucrat const & executor) const;
};

#endif
