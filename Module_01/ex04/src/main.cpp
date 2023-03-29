/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/25 16:01:31 by pniezen       #+#    #+#                 */
/*   Updated: 2023/03/29 08:35:07 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <fstream>
#include <iostream>

static std::string	replaced_line(std::string line, std::string search, std::string replace)
{
	int	start;
	int	pos;

	start = 0;
	pos = line.find(search, start);
	while (pos != (int) std::string::npos)
	{
		line.erase(pos, search.length());
		line.insert(pos, replace);
		start = pos + replace.length();
		pos = line.find(search, start);
	}
	return (line);
}

static int	checkArgs(std::string file, std::string s1, std::string s2)
{
	if (file.empty() || s1.empty() || s2.empty())
		return (0);
	return (1);
}

int main(int argc, char **argv)
{
	std::string	replace_ext = ".replace";
	std::string	s1;
	std::string	s2;
	std::string	line_str;

	if ((argc == 1 || argc < 4) || !checkArgs(argv[1], argv[2], argv[2]))
	{
		std::cerr << "Wrong arguments. Expected: ./sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::ifstream	file(argv[1]);
	s1 = argv[2];
	s2 = argv[3];
	if (!file)
	{
		std::cerr << "Could not open the file." << std::endl;
		return (1);
	}
	std::ofstream	replaced_file(argv[1] + replace_ext);
	if (!replaced_file)
	{
		std::cerr << "Could not open or create the .replace file." << std::endl;
		return (1);
	}
	while (getline(file, line_str))
	{
		replaced_file << replaced_line(line_str, s1, s2);
		if (file.eof())
			break ;
		replaced_file << std::endl;
	}
	return (0);
}
