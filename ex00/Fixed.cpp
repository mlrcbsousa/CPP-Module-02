/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:08:01 by msousa            #+#    #+#             */
/*   Updated: 2022/03/31 20:43:56 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _value(0) {
	LOG("Default constructor called");
}

Fixed::Fixed( Fixed const & src )
{
	LOG("Copy constructor called");
	*this = src;
}

Fixed::~Fixed( void )
{
	LOG("Destructor called");
}

Fixed &	Fixed::operator = ( Fixed const & rhs )
{
	LOG("Copy assignment operator called");

	if (this != &rhs)
		this->_value = rhs.getRawBits();

	return *this;
}

int	Fixed::getRawBits( void ) const
{
	LOG("getRawBits member function called");
	return this->_value;
}

void	Fixed::setRawBits( int const raw )
{
	(void)raw;
}

std::ostream &	operator << ( std::ostream & o, Fixed const & i)
{
	(void)i;
	o << "Serialized Fixed "; // << rhs.getVar();
	return o;
}

