/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 17:01:48 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/15 17:44:10 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <list>
# include <vector>

class PmergeMe
{
	private:
		std::list<int>		_intList;
		std::vector<int>	_intVector;

	public:
		// Constructors
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe & operator=(const PemergeMe &assign);
		// Destructor
		~PmergeMe();

		void	vectorInsertionSort(std::vector<int> v, int n);
		void	vectorMergeSort();
};

#endif