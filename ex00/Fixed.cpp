/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:08:01 by msousa            #+#    #+#             */
/*   Updated: 2022/03/31 20:10:24 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void )
{

}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
}

Fixed::~Fixed( void )
{

}

Fixed &	Fixed::operator = ( Fixed const & rhs )
{
	if (this != &rhs)
		// this->_var = rhs.getVar();

	return *this;
}

std::ostream &	operator << ( std::ostream & o, Fixed const & i)
{
	(void)i;
	o << "Serialized Fixed "; // << rhs.getVar();
	return o;
}

