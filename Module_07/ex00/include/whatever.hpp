/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   whatever.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 13:00:57 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/01 13:13:18 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T	temp = a;

	a = b;
	b = temp;
}

template<typename T>
const T	min(const T &a, const T &b)
{
	return (a < b ? a : b);
}

template<typename T>
const T	max(const T &a, const T &b)
{
	return (a > b ? a : b);
}

#endif
