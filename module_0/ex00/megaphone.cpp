/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 12:50:39 by pniezen       #+#    #+#                 */
/*   Updated: 2023/01/17 14:56:20 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{

	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}

	for (int x = 1; x < argc; x++)
	{
		for (int i = 0; argv[x][i]; i++)
			std::cout << (char)toupper(argv[x][i]);
	}

	std::cout << std::endl;
	return 0;
}
