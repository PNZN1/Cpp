/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 14:17:44 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/17 11:24:57 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <list>

class RPN
{
	private:
		std::list<int>	_numbers;

		int	getIndex(size_t i);

	public:
		// Constructors
		RPN();
		RPN(const RPN &copy);
		RPN & operator=(const RPN &assign);
		// Destructor
		~RPN();

		void	pushNumber(int num);
		void	operation(char c);
		int		getResult() const;
};

// Insertion overload
std::ostream &operator<<(std::ostream &out, const RPN &rpn);

#endif
