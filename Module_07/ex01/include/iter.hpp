/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iter.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 13:17:24 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/01 13:28:08 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T, typename N, typename F>
void	iter(T *arr, N len, F func)
{
	for (N i = 0; i < len; i++)
		func(arr[i]);
}

#endif
