/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 09:18:28 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/27 13:04:22 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	public:

		Harl(void);
		~Harl(void);

		void	complain(std::string level);
	private:

		enum	levels{DEBUG, INFO, WARNING, ERROR};
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif
