/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 15:10:34 by pniezen       #+#    #+#                 */
/*   Updated: 2023/01/24 13:31:43 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include <Contact.hpp>

class PhoneBook
{
	public:

		PhoneBook(void);
		~PhoneBook(void);

		bool		do_command(std::string command);

	private:
		Contact		_contact[8];
		int			_contact_saved;

		void		_add(void);
		void		_search(void);
		std::string	_format_str(std::string str) const;
		void		_print_selected_contact(int	index);
		std::string	_get_input(std::string buf, std::string promt, bool first);
};

#endif
