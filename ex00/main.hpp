/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msousa <mlrcbsousa@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 17:58:00 by msousa            #+#    #+#             */
/*   Updated: 2022/03/31 20:12:08 by msousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAIN_H__
#define __MAIN_H__

# include "Fixed.hpp"

# define LOG(x) std::cout << x << std::endl
# define ERROR(x) std::cerr << "Error: " << x << std::endl

# define CALL(object, member_pointer) ((object).*(member_pointer))

#endif /* __MAIN_H__ */
