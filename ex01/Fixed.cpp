#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) { std::cout << ORANGE << "Default constructor called" << RESET << std::endl; }
Fixed::~Fixed() { std::cout << BOLD_RED << "Destructor called" << RESET << std::endl; }

int		Fixed::getRawBits( void ) const { return (fixedPoint); }
void	Fixed::setRawBits( int const raw ) { fixedPoint = raw; }


Fixed::Fixed( const Fixed& other )
{
	std::cout << LIGHT_GREEN << "Copy constructor called" << RESET << std::endl;
	*this = other; // calls the overloaded '=' operator
}

Fixed	&Fixed::operator=( const Fixed& alternative )
{
	std::cout << PINK << "Copy assignment operator called" << RESET << std::endl;
	if (this != &alternative)
		this->setRawBits(alternative.getRawBits());
	return (*this);
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

// Constructor: floating -> fixed point
Fixed::Fixed( const float value ) 
{
	std::cout << TURQUOISE << "Float constructor called" << RESET << std::endl;
	this->fixedPoint = static_cast<int>(roundf(value * (1 << bits)));	// = value * (1<<8) 
																		// = value * 256 : shifting 8 bits to the left
																		//* we cannot do (value << bits) here bc value is not integer
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
