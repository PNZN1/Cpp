/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 17:01:48 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/17 16:39:41 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>
# include <string>

class PmergeMe
{
	private:
		std::deque<int>		_intDeque;
		std::vector<int>	_intVector;

		void	parseArgs(char **argv);
		int		convertToInt(char *arg);
		void	mergeSortDeque(int low, int mid, int high);
		void	insertionsortDeque(int low, int high);

	public:
		// Constructors
		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &copy);
		PmergeMe & operator=(const PmergeMe &assign);
		// Destructor
		~PmergeMe();

		int		getDequeSize();
		void	sortDeque(int low, int high);
		void	printBefore();
		void	printAfter();
};

#endif
