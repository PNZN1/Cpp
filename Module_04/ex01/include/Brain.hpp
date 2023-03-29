/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/21 11:12:23 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/29 09:41:04 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:
		// Constructors
		Brain();
		Brain(const Brain &copy);

		// Destructor
		~Brain();

		// Operators
		Brain & operator=(const Brain &assign);

		// Member Funcitons
		std::string	getIdea(int index) const;
		void	setIdea(int index, std::string idea);

	private:
		std::string	ideas[100];
};

#endif
