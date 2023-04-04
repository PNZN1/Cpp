/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 08:04:45 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/04 16:15:11 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	{
		std::cout << "========== CASE 1 ==========" << std::endl << std::endl;
		std::cout << "----- CREATING BUREAUCRAT GRADE 1 -----" << std::endl;

		Bureaucrat	president("President", 1);
		std::cout << president << std::endl;

		std::cout << std::endl;
		std::cout << "----- CREATING SHRUBBERY CREATION FORM -----" << std::endl;

		ShrubberyCreationForm	shrub;
		std::cout << shrub << std::endl;

		std::cout << std::endl;
		std::cout << "----- SIGN SHRUBBERY CREATION FORM -----" << std::endl;

		shrub.execute(president);
		president.signForm(shrub);
		president.executeForm(shrub);
		shrub.execute(president);

		std::cout << std::endl;
		std::cout << shrub << std::endl;
		std::cout << "========== END CASE ==========" << std::endl << std::endl << std::endl;
	}

	{
		std::cout << "========== CASE 2 ==========" << std::endl << std::endl;
		std::cout << "----- CREATING BUREAUCRAT GRADE 1 -----" << std::endl;

		Bureaucrat	president("President", 1);
		std::cout << president << std::endl;

		std::cout << std::endl;
		std::cout << "----- CREATING ROBOTOMY REQUEST FORM -----" << std::endl;

		RobotomyRequestForm	robotomy("Robot");
		std::cout << robotomy << std::endl;

		std::cout << std::endl;
		std::cout << "----- SIGN ROBOTOMY REQUEST FORM -----" << std::endl;

		robotomy.execute(president);
		president.signForm(robotomy);
		president.executeForm(robotomy);
		robotomy.execute(president);

		std::cout << std::endl;
		std::cout << robotomy << std::endl;

		std::cout << "========== END CASE ==========" << std::endl << std::endl << std::endl;
	}

	{
		std::cout << "========== CASE 3 ==========" << std::endl << std::endl;
		std::cout << "----- CREATING BUREAUCRAT GRADE 1 -----" << std::endl;

		Bureaucrat	president("President", 1);
		std::cout << president << std::endl;

		std::cout << std::endl;
		std::cout << "----- CREATING PRESIDENTIAL PARDON FORM -----" << std::endl;

		PresidentialPardonForm	pardon("Pardon");
		std::cout << pardon << std::endl;

		std::cout << std::endl;
		std::cout << "----- SIGN PARDON REQUEST FORM -----" << std::endl;

		pardon.execute(president);
		president.signForm(pardon);
		president.executeForm(pardon);
		pardon.execute(president);

		std::cout << std::endl;
		std::cout << pardon << std::endl;

		std::cout << "========== END CASE ==========" << std::endl << std::endl << std::endl;
	}
	return (0);
}
