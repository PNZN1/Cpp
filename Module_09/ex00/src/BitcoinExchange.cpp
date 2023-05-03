/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 10:50:19 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/03 18:30:38 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <sstream>

// Constructors
BitcoinExchange::BitcoinExchange() : mCSVFile("Module_09/ex00/data.csv")
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void)copy;
	std::cout << "FINISH THE COPY CONSTRUCTOR" << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string file) : mCSVFile("Module_09/ex00/data.csv"), mFile(file)
{
	try
	{
		this->parseFile();
		this->parseCSV();
	}
	catch(const std::invalid_argument &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	this->calculateResult();
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}


// Private functions
void	BitcoinExchange::parseCSV(void)
{
	std::string	line;
	std::string	key;
	double		value;

	if (this->mCSVFile != "Module_09/ex00/data.csv")
		throw(std::invalid_argument("data.csv must by in this folder 'Module_09/ex00/'"));

	std::ifstream	csv("data.csv");
	if (!csv)
		throw(std::invalid_argument("data.csv must by in this folder 'Module_09/ex00/'"));

	std::getline(csv, line);
	if (line != "date,exchange_rate")
		throw(std::invalid_argument("data.csv invalid"));

	while (getline(csv, line))
	{
		key = static_cast<std::string>(line.substr(0, line.find(',')));
		std::istringstream(line.substr(line.find(',') + 1, line.back())) >> value;

		this->mCSVData.insert(std::pair<std::string, double>(key, value));
		if (csv.eof())
			break ;
	}
}

void	BitcoinExchange::parseFile(void)
{
	if (!this->mFile)
		throw(std::invalid_argument("could not open file."));

	std::string	line;
	std::getline(this->mFile, line);

	if (line != "date | value")
		throw(std::invalid_argument("input.txt invalid"));
}

void	BitcoinExchange::calculateResult(void)
{
	// std::tm	tm = {};
	// std::stringstream ss("2011-41-03");
	// ss >> std::get_time(&tm, "%Y-%m-%d");
	// std::cout << (1900 + tm.tm_year) << " " << (1 + tm.tm_mon) << " " << tm.tm_mday << std::endl;

	std::string	line;
	std::string	parseDate;
	std::string	parseValue;
	std::tm	tm;
	double	value;

	while (getline(this->mFile, line))
	{
		if (line.find('|') == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		parseDate = line.substr(0, line.find('|'));
		parseValue = line.substr(line.find('|') + 1);
		std::stringstream	ssDate(parseDate);
		ssDate >> std::get_time(&tm, "%Y-%m-%d");
		std::stringstream	ssValue(parseValue);
		ssValue >> value;

		if (value < 0 || value > 1000)
		{
			std::cout << "Error: too large a number" << std::endl;
			continue ;
		}
		std::cout << parseDate << "---" << parseValue << " " << value << std::endl;
		std::cout << (1900 + tm.tm_year) << " " << (1 + tm.tm_mon) << " " << tm.tm_mday << std::endl;
	}

	// for (std::map<std::string, double>::iterator i = this->mCSVData.begin(); i != this->mCSVData.end(); i++)
	// 	std::cout << i->first << "\t" << i->second << std::endl;
}
