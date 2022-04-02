/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:08:01 by msousa            #+#    #+#             */
/*   Updated: 2022/04/02 18:51:32 by msousa           ###   ########.fr       */
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

	setRawBits(value << _fractionBits);
}

Fixed::Fixed( const float value )
{
	LOG("Float constructor called");

	// cant bit shift directly because float
	setRawBits(roundf(value * (1 << _fractionBits)));
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
		setRawBits(rhs.getRawBits());

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
	return float(getRawBits()) / (1 << _fractionBits);
}

int	Fixed::toInt( void ) const
{
	return getRawBits() >> _fractionBits;
}

std::ostream &	operator << ( std::ostream & o, Fixed const & i)
{
	// if fractional part
	if (i.getRawBits() & 0xFF)
		o << i.toFloat();
	else
		o << i.toInt();

	// not really needed because ostream already rounds to int if no
	// float part, so just `o << i.toFloat();` is enough
	return o;
}
