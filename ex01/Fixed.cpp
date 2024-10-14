#include "Fixed.hpp"

//Default
Fixed::Fixed() : _bits(8) , _fixed(0) {
	std::cout << "Default constructor called" << std::endl;	
}

//Copy constructor
Fixed::Fixed(Fixed const &old) : _bits(old._bits) , _fixed(old._fixed) {
	std::cout << "Copy constructor called" << std::endl;
}

//Copy assignment operator
Fixed &Fixed::operator=(Fixed const &old) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed = old.getRawBits();
	return (*this);
}

Fixed::Fixed(int const num) : _bits(8) , _fixed(0) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixed = num << this->_bits;
}

Fixed::Fixed(float const num) : _bits(8) , _fixed(0) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixed = roundf(num * (1 << this->_bits));
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void Fixed::setRawBits(int const raw) {
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixed = raw;
}

int Fixed::toInt(void) const {
	return this->_fixed >> this->_bits; 
}

float Fixed::toFloat(void) const {
	return (float)this->_fixed / (1 << this->_bits);
}

//Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, Fixed const &in){
	out << in.toFloat();
	return out;
}
