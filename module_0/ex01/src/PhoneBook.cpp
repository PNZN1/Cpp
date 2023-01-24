/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/22 13:12:28 by pniezen       #+#    #+#                 */
/*   Updated: 2023/01/24 14:01:06 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>
#include <iomanip>
#include <string>

PhoneBook::PhoneBook(void)
{
	this->_contact_saved = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

std::string	PhoneBook::_format_str(std::string str) const
{
	unsigned	sz;

	if (str.empty())
		return (str);
	if (str.length() < 9)
		return (str);
	sz = str.size();
	str.resize(9);
	str.push_back('.');
	return (str);
}

void	PhoneBook::_print_selected_contact(int index)
{
	std::cout << "first name: " << this->_contact[index].get_firstname() << std::endl;
	std::cout << "first name: " << this->_contact[index].get_lastname() << std::endl;
	std::cout << "first name: " << this->_contact[index].get_nickname() << std::endl;
	std::cout << "first name: " << this->_contact[index].get_phonenumber() << std::endl;
	std::cout << "first name: " << this->_contact[index].get_darkestsecret() << std::endl;
}

std::string	PhoneBook::_get_input(std::string buf, std::string promt, bool first)
{
	if (!first)
		std::cout << promt;
	while (buf.empty())
	{
		getline(std::cin, buf);
		if (buf.empty())
		{
			std::cout << promt;
			continue ;
		}
		break ;
	}
	return (buf);
}

bool	PhoneBook::do_command(std::string command)
{
	if (command == "ADD")
		this->_add();
	else if (command == "SEARCH")
		this->_search();
	else if (command == "EXIT")
		return (false);
	return (true);
}

void	PhoneBook::_add(void)
{
	int			i;
	std::string	buf;

	i = this->_contact_saved % 8;

	this->_contact[i].set_firstname(this->_get_input(buf, "Please enter FIRST NAME: ", true));
	this->_contact[i].set_lastname(this->_get_input(buf, "Please enter LAST NAME: ", false));
	this->_contact[i].set_nickname(this->_get_input(buf, "Please enter NICKNAME: ", false));
	while (!this->_contact[i].set_phonenumber(this->_get_input(buf, "Please enter PHONE NUMBER: ", false)))
		;
	this->_contact[i].set_darkestsecret(this->_get_input(buf, "Please enter DARKEST SECRETS: ", false));

	this->_contact_saved++;
}

void	PhoneBook::_search(void)
{
	std::string	buf;
	int			index;
	bool		is_num;

	std::cout << std::endl;
	std::cout << "|" << std::setw(10) << "index";
	std::cout << "|" << std::setw(10) << "first name";
	std::cout << "|" << std::setw(10) << "last name";
	std::cout << "|" << std::setw(10) << "nickname";
	std::cout << "|" << std::endl;

	for (int i = 0; i < 8; i++)
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << this->_format_str(this->_contact[i].get_firstname());
		std::cout << "|" << std::setw(10) << this->_format_str(this->_contact[i].get_lastname());
		std::cout << "|" << std::setw(10) << this->_format_str(this->_contact[i].get_nickname());
		std::cout << "|" << std::endl;
	}

	while (buf.empty())
	{
		is_num = true;
		getline(std::cin, buf);
		if (buf.empty())
		{
			std::cout << "Please provide the index to select the user: ";
			continue ;
		}
		for (int d = 0; buf[d]; d++)
		{
			if (!std::isdigit(buf[d]))
				is_num = false;
		}
		if (!is_num)
		{
			std::cout << buf << " is not a number." << std::endl;
			buf.clear();
			std::cout << "Please provide the index to select the user: ";
			continue ;
		}
		break ;
	}
	index = std::stoi(buf);

	if (index >= this->_contact_saved)
	{
		std::cout << "There is no contact at index " << index << std::endl;
		std::cout << std::endl;
	}
	for (int i = 0; i < this->_contact_saved; i++)
	{
		if (index == i)
		{
			this->_print_selected_contact(index);
			break ;
		}
	}
}
