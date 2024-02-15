#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr_base(int nbr, char *base);

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int 	nbr;
		char	*base = av[2];

		nbr = atoi(av[1]);
		ft_putnbr_base(nbr, base);
		write(1, "\n", 1);
		return (0);
	}
	else
		return (1);
}
