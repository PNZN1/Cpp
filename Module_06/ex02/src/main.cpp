/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 11:57:28 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/01 12:00:44 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Classes.hpp"

int	main(void)
{
	Base	*ptr = generate();
	Base	&rfc = *ptr;

	identify(ptr);
	identify(rfc);

	delete ptr;
	return (0);
}
