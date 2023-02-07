#include "./push_swap.h"

static void	fill_numbers(t_nums *nums, char **buff)
{
	int	i;
	int	*tmp;

	i = 0;
	while (buff[i])
		i++;
	tmp = nums->numbers;
	nums->numbers = (int *)ft_calloc(sizeof(int), (nums->size + i));
	if (!nums->numbers)
		exit(1);
	i = 0;
	while (i < nums->size)
		i++;
	i = -1;
	while (++i < nums->size)
		nums->numbers[i] = tmp[i];
	if (tmp)
		free(tmp);
	i = -1;
	while (buff[++i])
	{
		check_isdigit(buff[i]);
		nums->numbers[nums->size++] = ft_atoi(buff[i]);
		free(buff[i]);
	}
}

void	ft_parse(int argc, char **argv, t_nums *numbers)
{
	int		i;
	char	**buff;

	i = 0;
	while (++i < argc)
	{
		buff = ft_split(argv[i], ' ');
		if (!buff)
			exit(1);
		fill_numbers(numbers, buff);
		free(buff);
	}
}
