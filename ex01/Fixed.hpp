#pragma once

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed const &old);
		Fixed(int const num);
		Fixed(float const num);
		~Fixed(void);
		Fixed &operator=(Fixed const &old);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
	private:
		int const _bits;
		int _fixed;
};

std::ostream &operator<<(std::ostream &out, Fixed const &in);