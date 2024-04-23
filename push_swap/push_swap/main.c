#include "push_swap.h"

int main (int argc, char *argv[])
{
	t_list	*list;

	if (argc < 2)
		return (0);
	list = NULL;
	list = fill_list(list, argv);
	print_list(list);
	return (0);
}