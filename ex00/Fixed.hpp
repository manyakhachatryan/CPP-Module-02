#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed( const Fixed& t);           
        Fixed& operator=(const Fixed& x); 
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int _fixed_point;
        static const int _fixed = 8;
};

#endif