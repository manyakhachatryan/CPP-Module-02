#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
class Fixed
{
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num );
        float toFloat( void ) const;
        int toInt( void ) const;
        Fixed( const Fixed& t);     
        Fixed& operator=(const Fixed& x); 
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
    private:
        int _fixed_point;
        static const int _fixed = 8;
};

std::ostream& operator << (std::ostream &o, const Fixed &c);

#endif