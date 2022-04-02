/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:08:01 by msousa            #+#    #+#             */
/*   Updated: 2022/04/02 20:56:48 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


/* Class methods */

Fixed &	Fixed::min(Fixed & a, Fixed & b)
{
	return a > b ? b : a;
}

Fixed &	Fixed::min(Fixed const & a, Fixed const & b)
{
	return Fixed::min((Fixed &)a, (Fixed &)b);
}

Fixed &	Fixed::max(Fixed & a, Fixed & b)
{
	return a < b ? b : a;
}

Fixed &	Fixed::max(Fixed const & a, Fixed const & b)
{
	return Fixed::max((Fixed &)a, (Fixed &)b);
}


/* Constructors */

Fixed::Fixed( void ) : _raw(0) { /* no-op */ }

Fixed::Fixed( const int value )
{
	setRawBits(value << _fractionBits);
}

Fixed::Fixed( const float value )
{
	// cant bit shift directly because float
	setRawBits(roundf(value * (1 << _fractionBits)));
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
}

Fixed::~Fixed( void ) { /* no-op */ }


/* Instance methods */

Fixed &	Fixed::operator = ( Fixed const & rhs )
{
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

/* comparison operators */
bool	Fixed::operator == ( const Fixed & rhs ) const
{
	return getRawBits() == rhs.getRawBits();
}

bool	Fixed::operator != ( const Fixed & rhs ) const
{
	return getRawBits() != rhs.getRawBits();
}

bool	Fixed::operator > ( const Fixed & rhs ) const
{
	return getRawBits() > rhs.getRawBits();
}

bool	Fixed::operator < ( const Fixed & rhs ) const
{
	return getRawBits() < rhs.getRawBits();
}

bool	Fixed::operator >= ( const Fixed & rhs ) const
{
	return getRawBits() >= rhs.getRawBits();
}

bool	Fixed::operator <= ( const Fixed & rhs ) const
{
	return getRawBits() <= rhs.getRawBits();
}

/* arithmetic operators */
Fixed	Fixed::operator + (const Fixed & rhs) const
{
	Fixed i;
	i.setRawBits(getRawBits() + rhs.getRawBits());
	return i;
}

Fixed	Fixed::operator - (const Fixed & rhs) const
{
	Fixed i;
	i.setRawBits(getRawBits() - rhs.getRawBits());
	return i;
}

Fixed	Fixed::operator * (const Fixed & rhs) const
{
	Fixed i;
	i.setRawBits(getRawBits() * rhs.getRawBits());
	// cut back one of these operations since it was done twice
	i.setRawBits(i.getRawBits() >> _fractionBits);
	return i;
}

Fixed	Fixed::operator / (const Fixed & rhs) const
{
	Fixed i;
	// need to multiply before dividing to not lose information
	i.setRawBits(getRawBits() << _fractionBits);
	i.setRawBits(i.getRawBits() / rhs.getRawBits());
	return i;
}

Fixed &	Fixed::operator ++ ( void )
{
	setRawBits(getRawBits() + 1);
	return *this;
}

Fixed	Fixed::operator ++ ( int )
{
	Fixed i = *this;
	++*this;
	return i;
}

Fixed &	Fixed::operator -- ( void )
{
	setRawBits(getRawBits() - 1);
	return *this;
}

Fixed	Fixed::operator -- ( int )
{
	Fixed i = *this;
	--*this;
	return i;
}

/* ostream override */
std::ostream &	operator << ( std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}
