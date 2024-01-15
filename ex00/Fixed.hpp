/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:50:11 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/01/15 17:54:48 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
  private:
    int _fixedPoint;
    static const int _bits = 8;

  public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &copy);
    Fixed &operator=(const Fixed &fixed);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif