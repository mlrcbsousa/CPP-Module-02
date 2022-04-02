/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:08:01 by msousa            #+#    #+#             */
/*   Updated: 2022/04/02 17:40:54 by msousa           ###   ########.fr       */
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

	// int bounds when 8 bits are used for fraction part (2^23 - 1)
	if (value > 8388607 || value < -8388608)
		ERROR("value out of bounds");

	setRawBits(value << _fractionBits);
}

Fixed::Fixed( const float value )
{
	LOG("Float constructor called");

	if (value > 8388607 || value < -8388608)
		ERROR("value out of bounds");

	int		raw = (int)value << _fractionBits;
	float	float_part = value - (int)value;

	if (float_part > 0) {
		for (uint i = 1; i <= _fractionBits; i++) {

			// if remaining float part is bigger then fraction
			if (float_part - (1.0f / (1 << i)) > 0) {

				// decrease remaining float part
				float_part -= 1.0f / (1 << i);

				// insert bit at that position
				raw |= (1 << (_fractionBits - i));
			}
		}
	}
	setRawBits(raw);
	// 1.0f / (1 << 8); // constant EPSILON
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
	int		int_part = getRawBits() >> _fractionBits;
	float	float_part = 0.0;

	// if there are any bits in the fraction bits
	if (getRawBits() & 0b11111111) {
		for (uint i = 1; i <= _fractionBits; i++) {

			// if there is a bit at that position
			if (getRawBits() & (1 << (_fractionBits - i))) {

				// add the fraction to the float part
				float_part += 1.0f / (1 << i);
			}
		}
	}

	return (float_part + int_part);
}

int	Fixed::toInt( void ) const
{
	return (getRawBits() >> _fractionBits);
}

std::ostream &	operator << ( std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}
