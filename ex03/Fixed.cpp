/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:55:17 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/01/26 11:29:00 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int nbr) : _fixedPoint(nbr << _bits)
{
  std::cout << "Int constructor called" << std::endl; 
}

Fixed::Fixed(const float number) : _fixedPoint(static_cast<int>(roundf(number * (1 << _bits))))
{
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
  std::cout << "Copy constructor called" << std::endl;
  _fixedPoint = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
  std::cout << "Copy assignation operator called" << std::endl;
  if (this != &fixed)
    _fixedPoint = fixed.getRawBits();	
  return (*this);
}

int Fixed::getRawBits(void) const
{
  std::cout << "getRawBits member function called" << std::endl;
  return (_fixedPoint);
}

void  Fixed::setRawBits(int const raw)
{
  _fixedPoint = raw;
}

int Fixed::toInt(void) const
{
  return _fixedPoint >> _bits;
}

float Fixed::toFloat(void) const
{
  return static_cast<float>(_fixedPoint) / (1 << _bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
  os << fixed.toFloat();
  return os;
}

bool  Fixed::operator>(const Fixed& other) const
{
  return _fixedPoint > other._fixedPoint;
}

bool  Fixed::operator<(const Fixed& other) const
{
  return _fixedPoint < other._fixedPoint;
}

bool  Fixed::operator>=(const Fixed& other) const
{
  return _fixedPoint >= other._fixedPoint;
}

bool  Fixed::operator<=(const Fixed& other) const
{
  return _fixedPoint <= other._fixedPoint;
}

bool  Fixed::operator==(const Fixed& other) const
{
  return _fixedPoint == other._fixedPoint;
}

bool  Fixed::operator!=(const Fixed& other) const
{
  return _fixedPoint != other._fixedPoint;
}

Fixed Fixed::operator+(const Fixed& other) const
{
  Fixed result;
  result._fixedPoint = _fixedPoint + other._fixedPoint;
  return result;
}

//  Fixed Fixed::operator+(const Fixed& other) const
// {
//   return Fixed(this->toFloat() + other.toFloat());
// }

// Fixed Fixed::operator+(const Fixed& other) const
// {
//   return Fixed(_fixedPoint + other._fixedPoint);
// }

Fixed Fixed::operator-(const Fixed& other) const
{
  Fixed result;
  result._fixedPoint = _fixedPoint - other._fixedPoint;
  return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
  Fixed result;
  result._fixedPoint = (_fixedPoint * other._fixedPoint)/(1 << _bits);
  return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
  if(other._fixedPoint == 0)
  {
    std::cerr << "Error: Division by 0" << std::endl;
    return Fixed();
  }
  
  Fixed result;
  result._fixedPoint = ((_fixedPoint * 1 << _bits))/ other._fixedPoint;
  return result;
}
// pos
Fixed Fixed::operator++(int)
{
  Fixed temp(*this);
  _fixedPoint++;
  return temp;
}

//pre
Fixed& Fixed::operator++()
{
  _fixedPoint++;
  return *this;
}

Fixed Fixed::operator--(int)
{
  Fixed temp(*this);
  _fixedPoint--;
  return temp;
}

Fixed& Fixed::operator--()
{
  _fixedPoint--;
  return *this;
}

Fixed& Fixed::min(Fixed& one, Fixed& two)
{
    return (one.getRawBits() < two.getRawBits()) ? one : two;
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two)
{
  return (one.getRawBits() < two.getRawBits()) ? one : two;
}

Fixed& Fixed::max(Fixed& one, Fixed& two)
{
    return (one.getRawBits() > two.getRawBits()) ? one : two;
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two)
{
  return (one.getRawBits() > two.getRawBits()) ? one : two;
}