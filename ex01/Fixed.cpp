/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:08:01 by msousa            #+#    #+#             */
/*   Updated: 2022/04/01 19:34:57 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _raw(0)
{
	LOG("Default constructor called");
}

Fixed::Fixed( const int value )
{
	LOG("Int constructor called");
	(void)value;
	// conversion of int into raw
}

Fixed::Fixed( const float value )
{
	LOG("Float constructor called");
	(void)value;
	// conversion of float into raw
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
		_raw = rhs.getRawBits();

	return *this;
}

int	Fixed::getRawBits( void ) const
{
	return _raw;
}

void	Fixed::setRawBits( int const raw )
{
	_raw = raw;
}

float	Fixed::toFloat( void ) const
{
	return 42.42f;
}

int	Fixed::toInt( void ) const
{
	return 42;
}

std::ostream &	operator << ( std::ostream & o, Fixed const & i)
{
	o << i.getRawBits();
	return o;
}
