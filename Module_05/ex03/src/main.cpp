/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/03 08:04:45 by pniezen       #+#    #+#                 */
/*   Updated: 2023/04/12 10:32:25 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	{
		std::cout << "==== CASE 1 ====" << std::endl << std::endl;
		std::cout << "-- INTERN CREATES SHRUBBERY CREATION FORM --" << std::endl << std::endl;
		try
		{
			std::cout << "---- CREATING INTERN ----" << std::endl;
			Intern	someRandomIntern;

			AForm	*someForm = someRandomIntern.makeForm("shrubbery creation form", "Some Shrubbery Form");

			std::cout << std::endl << "---- DESTRUCTOR ----" << std::endl;
			delete someForm;
		}
		catch(const std::exception& e)
		{
			std::cout << std::endl << "---- EXCEPTION ----" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << std::endl;
		std::cout << "==== CASE 2 ====" << std::endl << std::endl;
		std::cout << "-- INTERN CREATES ROBOTOMY REQUEST FORM --" << std::endl << std::endl;
		try
		{
			std::cout << "---- CREATING INTERN ----" << std::endl;
			Intern	someRandomIntern;

			AForm	*someForm = someRandomIntern.makeForm("robotomy request form", "Some Request Form");

			std::cout << std::endl << "---- DESTRUCTOR ----" << std::endl;
			delete someForm;
		}
		catch(const std::exception& e)
		{
			std::cout << std::endl << "---- EXCEPTION ----" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << std::endl;
		std::cout << "==== CASE 3 ====" << std::endl << std::endl;
		std::cout << "-- INTERN CREATES PRESIDENTIAL PARDON FORM --" << std::endl << std::endl;
		try
		{
			std::cout << "---- CREATING INTERN ----" << std::endl;
			Intern	someRandomIntern;

			AForm	*someForm = someRandomIntern.makeForm("presidential pardon form", "Some Pardon Form");

			std::cout << std::endl << "---- DESTRUCTOR ----" << std::endl;
			delete someForm;
		}
		catch(const std::exception& e)
		{
			std::cout << std::endl << "---- EXCEPTION ----" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl << std::endl;
		std::cout << "==== CASE 4 ====" << std::endl << std::endl;
		std::cout << "-- INTERN CREATES WRONG FORM --" << std::endl << std::endl;
		try
		{
			std::cout << "---- CREATING INTERN ----" << std::endl;
			Intern	someRandomIntern;

			AForm	*someForm = someRandomIntern.makeForm("wrong form", "Some Wrong Form");

			std::cout << std::endl << "---- DESTRUCTOR ----" << std::endl;
			delete someForm;
		}
		catch(const std::exception& e)
		{
			std::cout << std::endl << "---- EXCEPTION ----" << std::endl;
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	system("leaks -q intern");
	return (0);
}
