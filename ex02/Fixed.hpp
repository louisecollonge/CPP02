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

		bool	operator>( const Fixed& comparator  ) const;
		bool	operator<( const Fixed& comparator  ) const;
		bool	operator>=( const Fixed& comparator  ) const;
		bool	operator<=( const Fixed& comparator  ) const;
		bool	operator==( const Fixed& comparator  ) const;
		bool	operator!=( const Fixed& comparator  ) const;

		Fixed	operator+( const Fixed& plus ) const;
		Fixed	operator-( const Fixed& minus ) const;
		Fixed	operator*( const Fixed& multiplier ) const;
		Fixed	operator/( const Fixed& divider ) const;

		Fixed	&operator++();			// pre-incrementation: ++i
		Fixed	operator++( int nb ); 	// post-incrementation: i++
		Fixed	&operator--();			// pre-decrementation: ++i
		Fixed	operator--( int nb ); 	// post-decrementation: i++

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed&		min( Fixed& a, Fixed& b );
		static const Fixed&	min( const Fixed& a, const Fixed& b );
		static Fixed&		max( Fixed& a, Fixed& b );
		static const Fixed&	max( const Fixed& a, const Fixed& b );
};

// #define EPSILON	(1.0f / (1 << Fixed::bits)) // = 1/256

// << is a global operator, not modifying the objects of the Fixed class.
// If it were a Fixed method, the main would look like: a.operator<<(std::cout);
// and not just: std::cout << a;
// NB: the function is not const bc that only pertains to a method since it means
// that the current object is not modified.
std::ostream&	operator<<( std::ostream& out, const Fixed& fixed );
