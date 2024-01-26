/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:42:40 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/01/26 13:03:14 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	std::cout << "Constructor Called" << std::endl; 
}

Point::Point(const float x, const float y) : x(x), y(y)
{
	std::cout << "Float Constructor Called" << std::endl; 
}

Point::Point(const Point &copy) : x(copy.x), y(copy.y)
{
	std::cout << "Copy Constructor Called" << std::endl; 
}

Point	&Point::operator=(const Point &point)
{
	std::cout << "Copy assignation operator called" << std::endl; 	
	if(this != &point)
	{
		(Fixed)x = point.x;
		(Fixed)y = point.y;
	}
	return (*this);
}

