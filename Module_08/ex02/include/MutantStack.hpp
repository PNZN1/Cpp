/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 14:18:30 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/02 14:36:54 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		// Constructors
		MutantStack() {}
		MutantStack(const MutantStack &copy)
		{
			*this = copy;
		}
		// Destructor
		~MutantStack() {}

		// Operators
		MutantStack	&operator=(const MutantStack &assign)
		{
			*this = assign;
			return (*this);
		}

		typedef T	*iterator;

		iterator	begin(void)
		{
			iterator	iter = &this->top();

			for (unsigned int i = 1; i < this->size(); i++)
				iter--;
			return (iter);
		}

		iterator	end(void)
		{
			return (&this->top() + 1);
		}
};

#endif
