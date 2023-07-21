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



//-------

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