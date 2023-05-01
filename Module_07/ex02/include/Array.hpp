/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 13:34:12 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/01 14:38:51 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<class T>
class Array
{
	private:
		unsigned int	mSize;
		T				*mArr;

	public:
		// Constructors
		Array() : mSize(0), mArr(NULL) {}
		Array(unsigned int n) : mSize(n)
		{
			this->mArr = new T[this->mSize]();
		}
		Array(const Array &copy)
		{
			*this = copy;
		}
		// Destructor
		~Array()
		{
			if (this->mArr)
				delete [] this->mArr;
		}

		// Operators
		Array	&operator=(const Array &assign)
		{
			if (this->mArr)
				delete [] this->mArr;
			this->mSize = assign.mSize;
			this->mArr = new T[this->mSize];
			for (unsigned int i = 0; i < this->mSize; i++)
				this->mArr[i] = assign.arr[i];
			return (*this);
		}
		T	&operator[](int i)
		{
			if (i < 0 || i > static_cast<int>(this->mSize))
				throw(IndexOutOfBound());
			return (this->mArr[i]);
		}

		// Member function
		void	setArray(int i, T value)
		{
			if (i < 0 || i > static_cast<int>(this->mSize))
				throw(IndexOutOfBound());
			this->mArr[i] = value;
		}

		int	size(void) const
		{
			return (static_cast<int>(this->mSize));
		}

		// Exceptions
		class IndexOutOfBound : public std::exception
		{
			public:
				virtual const char *what(void) const throw()
				{
					return ("Index out of bound.");
				}
		};
};

#endif
