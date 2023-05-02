/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Span.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/02 08:37:47 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/02 13:46:15 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>

class Span
{
	private:
		unsigned int		mN;
		std::vector<int>	mIntVector;

	public:
		// Constructors
		Span();
		Span(const Span &copy);
		Span(unsigned int N);
		// Destructor
		~Span();

		// Operators
		Span	&operator=(const Span &assign);

		// Member functions
		void				addNumber(int number);
		void				insertMany(void);
		unsigned int		shortestSpan(void);
		unsigned int		longestSpan(void);
		std::vector<int>	getVector(void) const;

		// Exceptions
		class MaxSize : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
		class NoSpan : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
};

#endif
