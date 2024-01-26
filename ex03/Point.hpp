/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcarrilh <dcarrilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 12:38:45 by dcarrilh          #+#    #+#             */
/*   Updated: 2024/01/26 12:47:01 by dcarrilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include "Fixed.hpp"

class Point
{
private:
	
	Fixed const x;
	Fixed	const	y;
	
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &copy);
	Point &operator=(const Point &point);
	~Point();
};

bool bsp(Point const a, Point const b, Point const c, Point const point);


#endif
