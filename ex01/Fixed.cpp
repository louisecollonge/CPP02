#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) { std::cout << ORANGE << "Default constructor called" << RESET << std::endl; }
Fixed::~Fixed() { std::cout << BOLD_RED << "Destructor called" << RESET << std::endl; }
int		Fixed::getRawBits( void ) const { return (fixedPoint); }
void	Fixed::setRawBits( int const raw ) { fixedPoint = raw; }

// Copy constructor
Fixed::Fixed( const Fixed& other )
{
	std::cout << LIGHT_GREEN << "Copy constructor called" << RESET << std::endl;

	*this = other; // calls the overloaded '=' operator
}

// Constructor: int -> fixed point
Fixed::Fixed( const int value ) 
{
	std::cout << BLUE << "Int constructor called" << RESET << std::endl;

	this->fixedPoint = value << bits;	// = value * 2^bits 
										// = value * 2^8 
										// = value * 256 : shifting 8 bits to the left
										//* only possible bc value is integer
}

// Constructor: float -> fixed point
Fixed::Fixed( const float value ) 
{
	std::cout << TURQUOISE << "Float constructor called" << RESET << std::endl;

	this->fixedPoint = static_cast<int>(roundf(value * (1 << bits)));	// = value * (1<<8) 
																		// = value * 256 : shifting 8 bits to the left
																		//* we cannot do (value << bits) here bc value is not integer
	// roundf() rounds up to the closest integer.
	// without it, the fractional part is just truncated.
}

Fixed	&Fixed::operator=( const Fixed& alternative )
{
	std::cout << PINK << "Copy assignment operator called" << RESET << std::endl;

	if (this != &alternative)
		this->setRawBits(alternative.getRawBits());
	return (*this);
}

// fixed -> floating point
float	Fixed::toFloat( void ) const 
{
	return (static_cast<float>(fixedPoint) / (1 << bits));	// = /(1 << 8)
															// = /256
}

// fixed point -> integer
int	Fixed::toInt( void ) const { return (fixedPoint >> bits); }

// Operator overload for << insertion: inserts a floating point nb to output stream
std::ostream&	operator<<( std::ostream& outstream, const Fixed& fixedPoint )
{
	outstream << fixedPoint.toFloat();
	return (outstream);
}


/* 


* Integer VS fixed point VS floating point:

float	nb_float	= 1.0f;
int		fixedPoint	= nb_float * 2^bits;

fixedPoint is an integer coding for a real (the floating point nb_float).

bits is the number of bits reserved for the fractional part of the real.
If bits = 8, then we just multiply the float real by 2^8 = 256 to get the
fixedPoint version. That corresponds to shifting 8 bits to the left.

In binary form, shifting 8 bits is:
00000000.11111111 -> 11111111.00000000
  _______________________________|
 |
this part is emptied, to store the fractional part of the real, with
a precision of 8 bits.



* Static_cast: 

It has nothing to do with static variables/functions. Here it means that 
the conversion is straight forward, no dynamic memory, we say it is 
resolved by the compilation: the compilator knows ahead of time what the 
result is (unlike a dynamic_cast, which is resolved by the execution).

float	nb_float	= 3.14f;
int		nb_int		= static_cast<int>(nb_float)	= 3

*/
