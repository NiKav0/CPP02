#include "Fixed.hpp"

Fixed::Fixed() : _bits(8) , _fixed(0) {

}

Fixed::Fixed(Fixed const &num) : _bits(num._bits) , _fixed(num._fixed) {
	//std::cout << "Constructor called." << std::endl;
}

Fixed::Fixed(const int x) : _bits(8) {
	//std::cout << "Int constructor called." << std::endl;
	this->_fixed = x << this->_bits;
	return;
}

Fixed::Fixed(const float x) : _bits(8) {
	//std::cout << "Float constructor called." << std::endl;
	this->_fixed = roundf(x * (1 << this->_bits));
	return;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called." << std::endl;
}


bool	Fixed::operator>(Fixed const &num) {
	return this->_fixed > num.getRawBits();
}

bool	Fixed::operator>=(Fixed const &num) {
	return this->_fixed >= num.getRawBits();
}

bool	Fixed::operator<(Fixed const &num) {
	return this->_fixed < num.getRawBits();
}

bool	Fixed::operator<=(Fixed const &num) {
	return this->_fixed <= num.getRawBits();
}

bool	Fixed::operator==(Fixed const &num) {
	return this->_fixed == num.getRawBits();
}

bool	Fixed::operator!=(Fixed const &num) {
	return this->_fixed != num.getRawBits();
}

Fixed &Fixed::operator+(Fixed const &num) {
	this->_fixed = this->_fixed + num.getRawBits();
	return *this;
}

Fixed &Fixed::operator-(Fixed const &num) {
	this->_fixed = this->_fixed - num.getRawBits();
	return *this;
}

Fixed Fixed::operator*(Fixed const &num) {
	return ((Fixed)(this->toFloat() * num.toFloat()));
	// this->_fixed = this->_fixed * num.getRawBits();
	return *this;
}

Fixed &Fixed::operator/(Fixed const &num) {
	this->_fixed = this->_fixed / num.getRawBits();
	return *this;
}

Fixed &Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed Fixed::operator++(int) {
	// this->_fixed = ++this->_fixed;
	Fixed tmp(*this);
	*this = operator++();
	return (tmp);
}

Fixed &Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);

	*this = operator--();
	return (tmp);
}

Fixed &Fixed::operator=(Fixed const &num) {
	this->_fixed = num.getRawBits();
	return (*this);
}

const Fixed &Fixed::min(Fixed const &num, Fixed const &num2) {
	if (num._fixed > num2._fixed)
		return (num2);
	return (num);
}

Fixed &Fixed::min(Fixed &num, Fixed &num2) {
	return (num < num2) ? num : num2;
}

const Fixed &Fixed::max(Fixed const &num, Fixed const &num2) {
	if (num._fixed < num2._fixed)
		return (num2);
	return (num);
}

Fixed &Fixed::max(Fixed &num, Fixed &num2) {
	return (num2 < num) ? num2 : num;
}

int Fixed::getRawBits(void) const {
	return this->_fixed;
}

void Fixed::setRawBits(int const raw) {
	this->_fixed = raw;
}

int Fixed::toInt(void) const {
	return this->_fixed >> this->_bits; 
}

float Fixed::toFloat(void) const {
	return ((float)this->_fixed / (1 << this->_bits));
}

std::ostream &operator<<(std::ostream &out, Fixed const &in){
	out << in.toFloat();
	return out;
}
