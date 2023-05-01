/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   easyfind.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 15:15:31 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/01 16:45:03 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template<typename T>
typename T::iterator	easyfind(T value, int num)
{
	typename T::iterator	found;

	found = std::find(value.begin(), value.end(), num);
	if (found == value.end())
		throw(std::runtime_error("easyfind could not find the given num within the given value."));
	return (found);
}

#endif
