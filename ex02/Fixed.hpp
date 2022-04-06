/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:09:49 by msousa            #+#    #+#             */
/*   Updated: 2022/04/04 19:38:43 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
# define __FIXED_H__

# include <iostream>
# include <cmath>

# define LOG(x) std::cout << x << std::endl
# define ERROR(x) std::cerr << x << std::endl

# define ABS(x) (((x) < 0) ? -(x) : (x))


// ************************************************************************** //
//                               Fixed Class                                 //
// ************************************************************************** //

class Fixed {

public:

	static Fixed &	min(Fixed & a, Fixed & b);
	static Fixed &	min(Fixed const & a, Fixed const & b);
	static Fixed &	max(Fixed & a, Fixed & b);
	static Fixed &	max(Fixed const & a, Fixed const & b);

	Fixed( void );
	Fixed( const int value );
	Fixed( const float value );
	Fixed( Fixed const & src );
	~Fixed( void );
	Fixed & operator = ( Fixed const & rhs );

	int		getRawBits( void ) const;
	void 	setRawBits( int const raw );
	float 	toFloat( void ) const;
	int 	toInt( void ) const;

	/* comparison operators */
	bool	operator == ( const Fixed & rhs ) const;
	bool	operator != ( const Fixed & rhs ) const;
	bool	operator > ( const Fixed & rhs ) const;
	bool	operator < ( const Fixed & rhs ) const;
	bool	operator >= ( const Fixed & rhs ) const;
	bool	operator <= ( const Fixed & rhs ) const;

	/* arithmetic operators */
	Fixed 	operator + (const Fixed & rhs) const;
	Fixed 	operator - (const Fixed & rhs) const;
	Fixed 	operator * (const Fixed & rhs) const;
	Fixed 	operator / (const Fixed & rhs) const;

	/* increment & decrement operators */
	Fixed &	operator ++ ( void );
	Fixed	operator ++ ( int );
	Fixed &	operator -- ( void );
	Fixed	operator -- ( int );

private:

	static const int	_fractionBits = 8;
	int					_raw;

};

std::ostream &	operator << ( std::ostream & o, Fixed const & i);

#endif /* __FIXED_H__ */
