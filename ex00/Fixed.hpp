#pragma once

#define ORANGE		"\033[38;5;214m"
#define BOLD_RED 	"\033[1;31m"
#define RED 		"\033[0;31m"
#define PINK	 	"\033[0;35m"
#define DARK_GREEN	"\033[38;5;22m"
#define LIGHT_GREEN	"\033[38;5;46m" 
#define RESET		"\033[0m"

#include <iostream>
#include <string>

class Fixed
{
	private:
		int					nb;
		const static int	bits = 8;

	public:
		Fixed();
		Fixed( const Fixed& other );
		Fixed	&operator=( const Fixed& alternative );
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};
