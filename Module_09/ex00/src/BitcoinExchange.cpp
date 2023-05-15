/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 10:50:19 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/15 13:51:04 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <utility>
#include <map>

// Constructors
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	(void)copy;
}

BitcoinExchange::BitcoinExchange(std::string file) : mFile(file)
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

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	this->mDataBase = assign.mDataBase;
	return (*this);
}

// Destructor
BitcoinExchange::~BitcoinExchange() {}


// Private functions
void	BitcoinExchange::parseFile(void)
{
	if (!this->mFile)
		throw(std::invalid_argument("could not open file."));

	std::string	line;
	std::getline(this->mFile, line);

	if (line != "date | value")
		throw(std::invalid_argument("input.txt invalid"));
}

void	BitcoinExchange::parseCSV(void)
{
	std::string	line;
	std::string	key;
	double		value;

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

		this->mDataBase.insert(std::pair<std::string, double>(key, value));
		if (csv.eof())
			break ;
	}
}

void	BitcoinExchange::calculateResult(void)
{

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

		parseDate = line.substr(0, line.find("|"));
		parseValue = line.substr(line.find('|') + 1);
		std::stringstream	ssDate(parseDate);
		ssDate >> std::get_time(&tm, "%Y-%m-%d");
		std::stringstream	ssValue(parseValue);
		ssValue >> value;

		if (1900 + tm.tm_year < 2009)
		{
			std::cout << "Error: no price before the date: " << parseDate << std::endl;
			continue ;
		}
		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}

		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		DataBase::iterator	rate = this->mDataBase.upper_bound(parseDate);
		std::cout << parseDate << "=> " << value << " = " << value*rate->second << std::endl;
	}
}
