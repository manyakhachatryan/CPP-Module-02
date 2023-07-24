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
        Fixed&  operator=(const Fixed& x); 
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed& operator ++(void);
        Fixed operator++(int num);
        Fixed& operator--(void);
        Fixed operator--(int num);
        Fixed operator+(const Fixed& a) const;
        Fixed operator-(const Fixed& a) const;
        Fixed operator*(const Fixed& a) const;
        Fixed operator/(const Fixed& a) const;
        bool operator>(const Fixed& a) const;
        bool operator<(const Fixed& a) const;
        bool operator>=(const Fixed& a) const;
        bool operator<=(const Fixed& a) const;
        bool operator==(const Fixed& a) const;
        bool operator!=(const Fixed& a) const;
        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
    private:
        int _fixed_point;
        static const int _fixed = 8;
};

std::ostream & operator << (std::ostream &o, const Fixed &c);

#endif