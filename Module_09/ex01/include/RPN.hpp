/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 14:17:44 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/15 14:59:20 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <deque>

class RPN
{
	private:
		std::deque<double>	_numbers;

	public:
		// Constructors
		RPN();
		RPN(const RPN &copy);
		RPN & operator=(const RPN &assign);
		// Destructor
		~RPN();

		void	pushNumber(int num);
		void	operation(char c);
		double	getResult() const;
};

// Insertion overload
std::ostream &operator<<(std::ostream &out, const RPN &rpn);

#endif
