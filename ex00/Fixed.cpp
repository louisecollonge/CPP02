#include "Fixed.hpp"

// Constructor
Fixed::Fixed() : nb(0)
{
	std::cout << DARK_GREEN << "Default constructor called" << RESET << std::endl;
}

// Copy constructor
Fixed::Fixed( const Fixed& other )
{
	std::cout << LIGHT_GREEN << "Copy constructor called" << RESET << std::endl;
	
	this->nb = other.getRawBits();
}

// Operator overload
Fixed	&Fixed::operator=( const Fixed& alternative )
{
	std::cout << PINK << "Copy assignment operator called" << RESET << std::endl;

	if (this != &alternative) // avoiding self-assignment (would only cause pb with dynamic memory, but still good practice here)
		this->setRawBits(alternative.getRawBits());
	return (*this); // de-referencing 'this' pointer to return the value, making a reference
}

// Destructor
Fixed::~Fixed()
{
	std::cout << BOLD_RED << "Destructor called" << RESET << std::endl;
}

// Getter
int		Fixed::getRawBits( void ) const
{
	std::cout << ORANGE << "getRawBits member function called" << RESET << std::endl;
	return (nb);
}

// Setter
void	Fixed::setRawBits( int const raw ) { nb = raw; }
