/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 23:09:49 by msousa            #+#    #+#             */
/*   Updated: 2022/04/01 20:03:25 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FIXED_H__
# define __FIXED_H__

# include <iostream>
# include <cmath>

# define LOG(x) std::cout << x << std::endl
# define ERROR(x) std::cerr << x << std::endl


// ************************************************************************** //
//                               Fixed Class                                 //
// ************************************************************************** //

class Fixed {

public:

	Fixed( void );
	Fixed( const int value );
	Fixed( const float value );
	Fixed( Fixed const & src );
	~Fixed( void );
	Fixed & operator = ( Fixed const & rhs );

	int 				getRawBits( void ) const;
	void 				setRawBits( int const raw );
	float 				toFloat( void ) const;
	int 				toInt( void ) const;

private:

	static const int	_fractionBits = 8;
	int					_raw;

};

std::ostream &	operator << ( std::ostream & o, Fixed const & i);

#endif /* __FIXED_H__ */
