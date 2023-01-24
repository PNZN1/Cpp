/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/22 12:06:36 by pniezen       #+#    #+#                 */
/*   Updated: 2023/01/24 14:01:38 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::set_firstname(std::string first_name)
{
	this->_first_name = first_name;
}

std::string	Contact::get_firstname(void) const
{
	return (this->_first_name);
}

void	Contact::set_lastname(std::string last_name)
{
	this->_last_name = last_name;
}

std::string Contact::get_lastname(void) const
{
	return (this->_last_name);
}

void	Contact::set_nickname(std::string nickname)
{
	this->_nickname = nickname;
}

std::string Contact::get_nickname(void) const
{
	return (this->_nickname);
}

bool	Contact::set_phonenumber(std::string phone_number)
{
	bool	is_num;

	is_num = true;
	for (int d = 0; phone_number[d]; d++)
	{
		if (!std::isdigit(phone_number[d]))
			is_num = false;
	}
	if (!is_num)
		return (false);

	this->_phone_number = phone_number;
	return (true);
}

std::string Contact::get_phonenumber(void) const
{
	return (this->_phone_number);
}

void	Contact::set_darkestsecret(std::string darkest_secret)
{
	this->_darkest_secret = darkest_secret;
}

std::string Contact::get_darkestsecret(void) const
{
	return (this->_darkest_secret);
}
