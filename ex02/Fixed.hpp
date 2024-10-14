#pragma once

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const &num);
		Fixed(int const num);
		Fixed(float const num);
		~Fixed(void);
		bool	operator>(Fixed const &num); // logical comparisons
		bool	operator>=(Fixed const &num);
		bool	operator<(Fixed const &num);
		bool	operator<=(Fixed const &num);
		bool	operator==(Fixed const &num);
		bool	operator!=(Fixed const &num);

		Fixed &operator+(Fixed const &num); // arithmetic ops
		Fixed &operator-(Fixed const &num);
		Fixed operator*(Fixed const &num);
		Fixed &operator/(Fixed const &num);

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		Fixed &operator=(Fixed const &num);

		static const Fixed &min(Fixed const &num, Fixed const &num2);
		static Fixed &min(Fixed &num, Fixed &num2);
		static const Fixed &max(Fixed const &num, Fixed const &num2);
		static Fixed &max(Fixed &num, Fixed &num2);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
	private:
		int const _bits;
		int _fixed;
};

std::ostream &operator<<(std::ostream &out, Fixed const &in); // for shifting
