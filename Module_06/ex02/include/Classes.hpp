/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Classes.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pniezen <pniezen@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 11:18:47 by pniezen       #+#    #+#                 */
/*   Updated: 2023/05/01 11:26:20 by pniezen       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
# define CLASSES_HPP

class Base
{
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};


Base	*generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
