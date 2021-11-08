#include "ft_philo.h"

void	ft_bzero(void *s, size_t n)
{
	char	*aux;
	size_t	pos;

	aux = s;
	pos = 0;
	if (n != 0)
	{
		while (pos < n)
		{
			aux[pos] = '\0';
			pos++;
		}
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;

	mem = malloc(size * count);
	if (!mem)
		return (NULL);
	ft_bzero(mem, (size * count));
	return (mem);
}
