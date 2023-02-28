/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/28 10:30:38 by pniezen       #+#    #+#                 */
/*   Updated: 2023/02/28 10:51:10 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>


class Fixed
{
	public:
		// Constructors
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed(const int number);
		Fixed(const float number);

		// Destructor
		~Fixed(void);

		// Operators
		Fixed & operator=(const Fixed &assign);

		// Member Functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:

		int					_fpoint;
		static const int	_fbits = 8;
};

std::ostream & operator<<(std::ostream &out, const Fixed &fixed);

#endif
