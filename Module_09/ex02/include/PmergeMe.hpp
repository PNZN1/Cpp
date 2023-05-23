/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 17:01:48 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/23 10:29:05 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>
# include <string>
# include <ctime>

class PmergeMe
{
	private:
		PmergeMe(); // Not implemented, must have values;

		std::deque<int>		_intDeque;
		std::vector<int>	_intVector;

		void	parseArgs(char **argv);

		clock_t	sortDeque(int low, int high);
		void	mergeSortDeque(int low, int mid, int high);
		void	insertionSortDeque(int low, int high);

		clock_t	sortVector(int low, int high);
		void	mergeSortVector(int low, int mid, int high);
		void	insertionSortVector(int low, int high);

		void	printBefore();
		void	printAfter(std::string collection, clock_t duration);

	public:
		// Constructors
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &copy);
		PmergeMe & operator=(const PmergeMe &assign);
		// Destructor
		~PmergeMe();

		int		getDequeSize() const;
		void	sort(int low, int high);
};

#endif
