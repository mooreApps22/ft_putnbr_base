#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_is_base_valid(char *base)
{
	int	i;
	int	j;

	if (!base)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i >= 2)
		return (1);
	else
		return (0);
}

void	ft_putnbr_base_rec(int nbr, char *base, int base_len)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base_len)
	{
		ft_putnbr_base_rec(nbr / base_len, base, base_len);
	}
	write(1, &base[nbr % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;
	
	base_len = ft_strlen(base);
	if (ft_is_base_valid(base))
	{
		ft_putnbr_base_rec(nbr, base, base_len);
	}
}
