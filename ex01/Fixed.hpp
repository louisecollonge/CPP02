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
#include <string>
#include <cmath>

class Fixed
{
	private:
		int					fixedPoint;
		static const int	bits = 8;

	public:
		Fixed();
		Fixed( const Fixed& other );
		Fixed( const int value );
		Fixed( const float value );
		~Fixed();
		Fixed	&operator=( const Fixed& alternative );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

// Prototypes
std::ostream&	operator<<( std::ostream& out, const Fixed& fixed );
