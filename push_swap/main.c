#include "push_swap.h"

int main (int argc, char *argv[])
{
	t_list	*listA;
	t_list	*listB;

	if (argc < 2)
		return (0);
	listA = NULL;
	listB = NULL;
	listA = fill_list(listA, argv);
	push(&listA, &listB);
	print_list(listA, listB);
	return (0);
}

