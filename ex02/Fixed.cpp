#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
    _fixed_point = 0;
    std::cout<<"Default constructor called"<<std::endl;
}

Fixed::~Fixed()
{
    std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed&t)
{
    std::cout<<"Copy constructor called"<<std::endl;
    _fixed_point = t.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& x)
{
    std::cout<<"Copy assignment operator called"<<std::endl;
    this->setRawBits(x.getRawBits());
    return *this;
}

void Fixed::setRawBits( int const raw )
{
    _fixed_point = raw;
}

int Fixed::getRawBits( void ) const
{
    return _fixed_point;
}


Fixed::Fixed(const int num)
{
    setRawBits(num<<_fixed);
    std::cout<<"Int constructor called"<<std::endl;
}

Fixed::Fixed(const float num)
{
    setRawBits((int)(roundf(num*(1<<_fixed))));
    std::cout<<"Float constructor called"<<std::endl;
}

float Fixed::toFloat( void ) const
{
    return  ((float)(_fixed_point)/(1<<_fixed));
}

int Fixed::toInt( void ) const
{
    return (((int)(getRawBits()/(1<<_fixed))));
}

std::ostream & operator << (std::ostream &o,const Fixed &c)
{
    std::cout<<(c.toFloat());
    return (o);
}

Fixed&  Fixed::operator++()
{
    ++_fixed_point;
    return *this;
}

Fixed  Fixed::operator++(int num)
{
    (void)num;
    Fixed temp(*this);
    ++_fixed_point;
    return temp;
}

Fixed&  Fixed::operator--()
{
    --_fixed_point;
    return *this;
}

Fixed  Fixed::operator--(int num)
{
    (void)num;
    Fixed temp(*this);
    --_fixed_point;
    return temp;
}

Fixed Fixed::operator+(const Fixed& a) const
{
    return Fixed( this->toFloat() + a.toFloat());
}

Fixed Fixed::operator-(const Fixed& a) const
{
    return Fixed( this->toFloat() - a.toFloat());
}

Fixed Fixed::operator*(const Fixed& a) const
{
    return Fixed( this->toFloat() * a.toFloat());
}

Fixed Fixed::operator/(const Fixed& a) const
{
    return Fixed( this->toFloat() / a.toFloat());
}

bool Fixed::operator>(const Fixed& a) const
{
    return (_fixed_point > a._fixed_point);
}

bool Fixed::operator<(const Fixed& a) const
{
    return (_fixed_point < a._fixed_point);
}

bool Fixed::operator>=(const Fixed& a) const
{
    return (_fixed_point >= a._fixed_point);
}

bool Fixed::operator<=(const Fixed& a) const
{
    return (_fixed_point <= a._fixed_point);
}

bool Fixed::operator==(const Fixed& a) const
{
    return (_fixed_point == a._fixed_point);
}

bool Fixed::operator!=(const Fixed& a) const
{
    return (_fixed_point != a._fixed_point);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if(a._fixed_point>b._fixed_point)
        return(b);
    else 
        return (a);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if(a._fixed_point>b._fixed_point)
        return(a);
    else 
        return(b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
     if(a._fixed_point>b._fixed_point)
        return(a);
    else 
        return(b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
     if(a._fixed_point>b._fixed_point)
        return(b);
    else 
        return(a);
}