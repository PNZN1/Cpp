/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 17:05:36 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/15 17:44:37 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	this->_intList = copy._intList;
	this->_intVector = copy._intVector
}

PmergeMe & PmergeMe::operator=(const PmergeMe &assign)
{
	this->_intList = assign._intList;
	this->_intVector = assign._intVector;
	return (*this);
}

// Destructor
PmergeMe::~PmergeMe() {};


void	PmergeMe::vectorInsertionSort(std::vector<int> v, int n)
{
	
}
