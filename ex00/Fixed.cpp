#include "Fixed.hpp"

Fixed::Fixed() : bits(8) , fixed(0){
	std::cout << "Default constructor called" << std::endl;	
}

Fixed::Fixed(Fixed &old) : bits(old.bits) , fixed(old.fixed) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed &old) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed = old.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed;
}

void Fixed::setRawBits(int const raw) {
	this->fixed = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
