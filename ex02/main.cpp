/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:56:49 by msousa            #+#    #+#             */
/*   Updated: 2022/04/02 20:37:05 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	/* subject */

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;


	/* personal */

	std::cout << a << std::endl;
	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;

	std::cout << Fixed::min( a, b ) << std::endl;

	Fixed const c = a;
	Fixed const d( Fixed( 5.05f ) / Fixed( 2 ) );

	std::cout << d + Fixed( 2 ) << std::endl;
	std::cout << d - Fixed( 2.2f ) << std::endl;

	std::cout << d << std::endl;

	std::cout << Fixed::min( c, d ) << std::endl;

	return 0;
}
