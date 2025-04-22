#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0) {}
Fixed::Fixed( const Fixed& other ) { *this = other; }
Fixed::Fixed( const int value ) { this->fixedPoint = value << bits; }
Fixed::Fixed( const float value ) { this->fixedPoint = static_cast<int>(roundf(value * (1 << bits))); }
Fixed::~Fixed() {}

int		Fixed::getRawBits( void ) const { return (fixedPoint); }
void	Fixed::setRawBits( int const raw ) { fixedPoint = raw; }

Fixed	&Fixed::operator=( const Fixed& alternative )
{
	if (this != &alternative)
		this->setRawBits(alternative.getRawBits());
	return (*this);
}

float	Fixed::toFloat( void ) const { return (static_cast<float>(fixedPoint) / (1 << bits)); }

int	Fixed::toInt( void ) const { return (fixedPoint >> bits); }

std::ostream&	operator<<( std::ostream& outstream, const Fixed& fixedPoint )
{
	outstream << fixedPoint.toFloat();
	return (outstream);
}

bool	Fixed::operator>( const Fixed& comparator ) const { return (this->fixedPoint > comparator.fixedPoint); }
bool	Fixed::operator<( const Fixed& comparator  ) const { return (this->fixedPoint < comparator.fixedPoint); }
bool	Fixed::operator>=( const Fixed& comparator  ) const { return (this->fixedPoint >= comparator.fixedPoint); }
bool	Fixed::operator<=( const Fixed& comparator  ) const { return (this->fixedPoint <= comparator.fixedPoint); }
bool	Fixed::operator==( const Fixed& comparator  ) const { return (this->fixedPoint == comparator.fixedPoint); }
bool	Fixed::operator!=( const Fixed& comparator  ) const { return (this->fixedPoint != comparator.fixedPoint); }

Fixed	Fixed::operator+( const Fixed& plus ) const {
	Fixed	result;
	result.fixedPoint = this->fixedPoint + plus.fixedPoint;
	return (result);
}
Fixed	Fixed::operator-( const Fixed& minus ) const {
	Fixed	result;
	result.fixedPoint = this->fixedPoint - minus.fixedPoint;
	return (result);
}
Fixed	Fixed::operator*( const Fixed& multiplier ) const {
	Fixed	result;
	long	tmp = static_cast<long>(this->fixedPoint) * multiplier.fixedPoint;
	result.fixedPoint = static_cast<int>(tmp >> bits);	// both fixedPoints and the real value are *2^bits
														// so their product is multiplied one too many
														// times by 2^8, so we divide it once (>> bits).
	return (result);
}
Fixed	Fixed::operator/( const Fixed& divider ) const {
	Fixed	result;
	long	tmp = (static_cast<long>(this->fixedPoint) << bits) / divider.fixedPoint;
	result.fixedPoint = static_cast<int>(tmp);	// same a multiplication, here both fixedPoints
												// are multiplied by 2^bits, so the result is
												// not multiplied by anything (*256 / *256 = *1)
												// so we need to multiply it once (<< bits)
	return (result);
}

Fixed	&Fixed::operator++() // pre-incrementation
{
	this->fixedPoint += 1;	// integer, so no smaller value than 1
							// fixedPoint has 256 bits reserved on the right
							// which means the value was multiplied by 256
							// so 1, compared to fixedPoint, is really small
							// in fact, it is to smallest value for that scale
	return (*this);
}
Fixed	Fixed::operator++( int nb ) // post-incrementation
{
	(void)nb;
	Fixed	tmp(*this);
	this->fixedPoint += 1;
	return (tmp);
}
Fixed	&Fixed::operator--() //pre-decrementation
{
	this->fixedPoint -= 1;
	return (*this);
}
Fixed	Fixed::operator--( int nb ) // post-decrementation
{
	(void)nb;
	Fixed	tmp(*this);
	this->fixedPoint -= 1;
	return (tmp);
}

Fixed&			Fixed::min( Fixed& a, Fixed& b ) { return (a < b ? a : b); }
const Fixed&	Fixed::min( const Fixed& a, const Fixed& b ) { return (a < b ? a : b); }
Fixed&			Fixed::max( Fixed& a, Fixed& b ) { return (a > b ? a : b); }
const Fixed&	Fixed::max( const Fixed& a, const Fixed& b ) { return (a > b ? a : b); }
