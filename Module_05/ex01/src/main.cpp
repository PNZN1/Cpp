/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 08:04:45 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/04 09:02:00 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "========== CASE 1 ==========" << std::endl << std::endl;
	std::cout << "----- CREATING BUREAUCRAT GRADE 1 -----" << std::endl;

	Bureaucrat	president("President", 1);
	std::cout << president << std::endl;

	std::cout << std::endl;
	std::cout << "----- CREATING FORM GRADE 50 -----" << std::endl;

	Form	printMoney("money machine", 50, 50);
	std::cout << printMoney << std::endl;

	std::cout << std::endl;
	std::cout << "----- SIGN MONEY PRINTING FORM -----" << std::endl;

	president.signForm(printMoney);

	std::cout << std::endl;
	std::cout << printMoney << std::endl;

	std::cout << "========== END CASE ==========" << std::endl << std::endl << std::endl;



	std::cout << "========== CASE 2 ==========" << std::endl << std::endl;
	std::cout << "----- CREATING BUREAUCRAT GRADE 150 -----" << std::endl;

	Bureaucrat	thor;
	std::cout << thor << std::endl;

	std::cout << std::endl;
	std::cout << "----- CREATING FORM GRADE 50 -----" << std::endl;

	Form	printMoney2("money machine", 50, 50);
	std::cout << printMoney2 << std::endl;

	std::cout << std::endl;
	std::cout << "----- SIGN MONEY PRINTING FORM -----" << std::endl;

	thor.signForm(printMoney2);

	std::cout << std::endl;
	std::cout << printMoney2 << std::endl;

	std::cout << "========== END CASE ==========" << std::endl << std::endl << std::endl;

	return (0);
}
