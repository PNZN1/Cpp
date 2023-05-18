/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 17:05:36 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/18 15:53:49 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>

// Constructors
PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(char **argv)
{
	this->parseArgs(argv);
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
	this->_intDeque = copy._intDeque;
	this->_intVector = copy._intVector;
}

PmergeMe & PmergeMe::operator=(const PmergeMe &assign)
{
	this->_intDeque = assign._intDeque;
	this->_intVector = assign._intVector;
	return (*this);
}

// Destructor
PmergeMe::~PmergeMe() {};



// Public functions
int	PmergeMe::getDequeSize() const
{
	return (static_cast<int>(this->_intDeque.size()));
}

void	PmergeMe::sort(int low, int high)
{
	clock_t dequeDuration = this->sortDeque(low, high);
	clock_t vectorDuration = this->sortVector(low, high);

	std::cout << "After:\t";
	for (size_t i = 0; i < this->_intDeque.size(); i++)
		std::cout << this->_intDeque[i] << " ";
	std::cout << std::endl;

	this->printAfter("deque", dequeDuration);
	this->printAfter("vector", vectorDuration);
}

clock_t	PmergeMe::sortDeque(int low, int high)
{
	const clock_t	start = clock();
	int	mid;

	// if (low < high)
	if (high - low > 5)
	{
		mid = (low + high) / 2;
		this->sortDeque(low, mid);
		this->sortDeque(mid + 1, high);
		this->mergeSortDeque(low, mid, high);
	}
	else
		this->insertionSortDeque(low, high);

	return (clock() - start);
}

void	PmergeMe::mergeSortDeque(int low, int mid, int high)
{
	int	i = low;
	int	k = low;
	int	j = mid + 1;
	int	temp[high];

	while (i <= mid && j <= high)
	{
		if (this->_intDeque[i] < this->_intDeque[j])
			temp[k++] = this->_intDeque[i++];
		else
			temp[k++] = this->_intDeque[j++];
	}
	while (i <= mid)
		temp[k++] = this->_intDeque[i++];
	while (j <= high)
		temp[k++] = this->_intDeque[j++];

	for (i = low; i < k; i++)
		this->_intDeque[i] = temp[i];
}

void	PmergeMe::insertionSortDeque(int low, int high)
{
	for (int i = low; i < high; i++)
	{
		int	temp = this->_intDeque[i + 1];
		int	j = i + 1;
		while (j > low && this->_intDeque[j - 1] > temp)
		{
			this->_intDeque[j] = this->_intDeque[j - 1];
			j--;
		}
		this->_intDeque[j] = temp;
	}
}


clock_t	PmergeMe::sortVector(int low, int high)
{
	const clock_t	start = clock();
	int	mid;

	// if (low < high)
	if (high - low > 5)
	{
		mid = (low + high) / 2;
		this->sortVector(low, mid);
		this->sortVector(mid + 1, high);
		this->mergeSortVector(low, mid, high);
	}
	else
		this->insertionSortVector(low, high);

	return (clock() - start);
}

void	PmergeMe::mergeSortVector(int low, int mid, int high)
{
	int	i = low;
	int	k = low;
	int	j = mid + 1;
	int	temp[high];

	while (i <= mid && j <= high)
	{
		if (this->_intVector[i] < this->_intVector[j])
			temp[k++] = this->_intVector[i++];
		else
			temp[k++] = this->_intVector[j++];
	}
	while (i <= mid)
		temp[k++] = this->_intVector[i++];
	while (j <= high)
		temp[k++] = this->_intVector[j++];

	for (i = low; i < k; i++)
		this->_intVector[i] = temp[i];
}

void	PmergeMe::insertionSortVector(int low, int high)
{
	for (int i = low; i < high; i++)
	{
		int	temp = this->_intVector[i + 1];
		int	j = i + 1;
		while (j > low && this->_intVector[j - 1] > temp)
		{
			this->_intVector[j] = this->_intVector[j - 1];
			j--;
		}
		this->_intVector[j] = temp;
	}
}


// Others
void	PmergeMe::printBefore()
{
	std::cout << "Before:\t";
	for (size_t i = 0; i < this->_intDeque.size(); i++)
		std::cout << this->_intDeque[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::printAfter(std::string collection, clock_t duration)
{
	static const long	CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000;
	static const long	CLOCKS_PER_US = CLOCKS_PER_MS / 1000;
	const clock_t us = duration / CLOCKS_PER_US;

	std::cout << "Time to process a range of " << this->_intDeque.size() << " elements with std::"
		<< collection << "\t: " << us << " µs!" << std::endl;
}


// Private functions
void	PmergeMe::parseArgs(char **argv)
{
	int	i = 1;
	while(argv[i])
	{
		long	num;
		for (int j = 0; argv[i][j]; j++)
		{
			if (!std::isdigit(argv[i][j]))
				throw(std::invalid_argument("Not a number"));
			else if (j >= 10)
				throw(std::invalid_argument("Number must be a positive number"));
		}

		std::stringstream	ss(argv[i]);
		ss >> num;

		if (num > std::numeric_limits<int>::max())
			throw(std::invalid_argument("Number must be in the range of 0 to 2147483647"));

		this->_intDeque.push_back(static_cast<int>(num));
		this->_intVector.push_back(static_cast<int>(num));
		i++;
	}
}

int	PmergeMe::convertToInt(char *arg)
{
	long	number;
	for (int i = 0; arg[i]; i++)
	{
		if (!std::isdigit(arg[i]))
			throw(std::invalid_argument("Not a number"));
		else if ((arg[i] - 48) > 10)
			throw(std::invalid_argument("Number must be a positive number"));
	}

	std::stringstream	ss(arg);
	ss >> number;

	if (number > std::numeric_limits<int>::max())
		throw(std::invalid_argument("Number must be in the range of 0 to 2147483647"));
	return (static_cast<int>(number));
}
