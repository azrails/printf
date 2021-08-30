
#include "libft.h"

static	void	ft_parsnbr(int n, int fd)
{
	if (n / 10 != 0)
		ft_parsnbr((n / 10), fd);
	ft_putchar_fd((-(n % 10) + '0'), fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	else
		n = -n;
	ft_parsnbr(n, fd);
}
