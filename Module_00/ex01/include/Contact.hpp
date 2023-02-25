/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/22 11:28:18 by pniezen       #+#    #+#                 */
/*   Updated: 2023/01/24 13:23:11 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>

class Contact
{
	public:

		Contact(void);
		~Contact(void);

		void		set_firstname(std::string first_name);
		std::string	get_firstname(void) const;
		void		set_lastname(std::string last_name);
		std::string	get_lastname(void) const;
		void		set_nickname(std::string nickname);
		std::string	get_nickname(void) const;
		bool		set_phonenumber(std::string phone_number);
		std::string	get_phonenumber(void) const;
		void		set_darkestsecret(std::string darkest_secret);
		std::string	get_darkestsecret(void) const;

	private:

		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
};

#endif
