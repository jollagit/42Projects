#ifndef FIXED_HPP
# define FIXED_HPP
#include <cmath>
#include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed& value);
	Fixed &operator=(const Fixed& val);
	~Fixed(void);
	Fixed(const int n);
	Fixed(const float f);
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const point);
private:
	int					_fixedPoint;
	static const int	_fractionalBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif