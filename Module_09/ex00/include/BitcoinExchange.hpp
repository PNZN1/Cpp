/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 10:34:38 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/15 13:50:27 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <fstream>
# include <map>

class BitcoinExchange
{
	public:
		// Constructors
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange(std::string file);
		// Operators
		BitcoinExchange & operator=(const BitcoinExchange &assign);
		// Destructors
		~BitcoinExchange();

	private:
		BitcoinExchange();

		typedef std::greater_equal<std::string>				GreaterEqual;
		typedef std::map<std::string, double, GreaterEqual>	DataBase;

		DataBase		mDataBase;
		std::ifstream	mFile;

		void			parseCSV(void);
		void			parseFile(void);
		void			calculateResult(void);
};

#endif
