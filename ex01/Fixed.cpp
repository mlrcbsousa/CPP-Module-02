/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:08:01 by msousa            #+#    #+#             */
/*   Updated: 2022/04/01 21:12:37 by msousa           ###   ########.fr       */
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
	// LOG(INT_MAX);
	// LOG(INT_MIN);
	// LOG((int)0b10000000000000000000000000000000);
	if (value > 8388607 || value < -8388608)
		ERROR("value out of bounds");
	// conversion of int into raw
	setRawBits(value << _fractionBits);
	// LOG("_raw");
	// LOG(_raw);
	// if (value < 0){
	// 	_raw = ~_raw + 1;
	// 	LOG("_raw");
	// 	LOG((~_raw));
	// }
	// 0b10000000000000000000000000000000;
	// INT_MAX;
	// 0xFF000000;
}

Fixed::Fixed( const float value )
{
	LOG("Float constructor called");
	(void)value;
	// conversion of float into raw
	// 1.0f / (1 << 8); // constant
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
	// if (_raw)
	// LOG("Copy assignment operator called");
	// LOG((_raw & INT_MIN));
	int		int_part = getRawBits() >> _fractionBits;
	float	float_part = 0.4;


	return (float_part + int_part);
}

int	Fixed::toInt( void ) const
{
	return roundf(toFloat());
}

std::ostream &	operator << ( std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}
