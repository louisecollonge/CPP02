#include "Fixed.hpp"

int	main()
{
    Fixed		a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ));
    Fixed const c(2);
    Fixed const d(3.14f);

    std::cout << ORANGE << "a = " << a << std::endl
    		  << "b = " << b << std::endl
    		  << "c = " << c << std::endl
    		  << "d = " << d << RESET << std::endl 
			  << std::endl;

    std::cout << TURQUOISE << "b + c = " << b + c << std::endl
    		  << "b - d = " << b - d << std::endl
			  << "b * c = " << b * c << std::endl
			  << "b / d = " << b / d << RESET << std::endl 
			  << std::endl;

    std::cout << BLUE << "b > c:	" << ((b > c)? "true" : "false") << std::endl
    		  << "b < c:	" << ((b < c)? "true" : "false") << std::endl
    		  << "b >= c:	" << ((b >= c)? "true" : "false") << std::endl
    		  << "b == c:	" << ((b == c)? "true" : "false") << std::endl
    		  << "b != c:	" << ((b != c)? "true" : "false") << RESET << std::endl 
			  << std::endl;

    std::cout << PINK << "a	= " << a << std::endl
		 	  << "++a	= " << ++a << std::endl
   			  << "a++	= " << a++ << std::endl
   			  << "a	= " << a << std::endl
   			  << "--a	= " << --a << std::endl
   			  << "a--	= " << a-- << std::endl
   			  << "a	= " << a << RESET << std::endl 
			  << std::endl;

    std::cout << BOLD_RED << "Max between a and b = " << Fixed::max(a, b) << std::endl
    		  << "Min between a and b = " << Fixed::min(a, b) << RESET << std::endl;

    return (0);
}
