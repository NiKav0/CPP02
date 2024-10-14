#pragma once

#include <iostream>

class Fixed {
	public:
		Fixed(void);
		Fixed(Fixed &old);
		~Fixed(void);
		Fixed &operator=(Fixed &old);
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int const bits;
		int fixed;
};
