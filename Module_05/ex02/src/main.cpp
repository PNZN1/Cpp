/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 08:04:45 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/04 11:48:23 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
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
	return (0);
}
