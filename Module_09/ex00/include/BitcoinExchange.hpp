/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 10:34:38 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/03 18:30:34 by pniezen       ########   odam.nl         */
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
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange(std::string file);
		// Operators
		BitcoinExchange & operator=(const BitcoinExchange &assign);
		// Destructors
		~BitcoinExchange();

	private:
		std::map<std::string, double>	mCSVData;
		std::string						mCSVFile;
		std::ifstream					mFile;
		void		parseCSV(void);
		void		parseFile(void);
		void		calculateResult(void);
};

#endif
