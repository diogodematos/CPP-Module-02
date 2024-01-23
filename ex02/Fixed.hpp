/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:50:11 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/01/23 15:57:31 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
  private:
    int _fixedPoint;
    static const int _bits = 8;

  public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &copy);
    Fixed(const int nbr);
    Fixed(const float number);
    Fixed &operator=(const Fixed &fixed);
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    bool  operator>(const Fixed& other) const;
    bool  operator<(const Fixed& other) const;
    bool  operator>=(const Fixed& other) const;
    bool  operator<=(const Fixed& other) const;
    bool  operator==(const Fixed& other) const;
    bool  operator!=(const Fixed& other) const;

    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif