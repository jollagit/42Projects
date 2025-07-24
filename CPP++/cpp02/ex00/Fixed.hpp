#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed& value);
	Fixed &operator=(const Fixed& val);
	~Fixed(void);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int					_fixPoint;
	static const int	_fractionalBits;
};

#endif