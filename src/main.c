int main(void)
{
	if (!parse_input())
	{
		ft_putstr_fd("ERROR\n", 2);
		return (1);
	}
	run_simulation();
	return (0);
}