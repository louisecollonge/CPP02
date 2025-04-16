#pragma once

#define ORANGE		"\033[38;5;214m"
#define BOLD_RED 	"\033[1;31m"
#define RED 		"\033[0;31m"
#define TURQUOISE	"\033[38;5;49m"
#define PINK	 	"\033[0;35m"
#define BLUE		"\033[34m"
#define DARK_GREEN	"\033[38;5;22m"
#define LIGHT_GREEN	"\033[38;5;46m" 
#define RESET		"\033[0m"

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point();
		Point( const Point& other ); // copy constructor
		Point( const float a, const float b );
		~Point();

		Point	&operator=( const Point& alternative );
		const Fixed	getx() const;
		const Fixed	gety() const;
};
