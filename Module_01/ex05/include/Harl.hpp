/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/27 09:18:28 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/27 11:48:51 by pniezen       ########   odam.nl         */
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

		typedef struct	s_log
		{
			std::string	level;
			void		(Harl::*f)(void);
		}	t_log;

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif
