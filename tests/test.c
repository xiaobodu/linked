#include <stdio.h>
#include <stdlib.h>

#include <linked.h>

int main(void) {
	link_t *table = link_init();
	link_iter *ii = NULL;

	/* generate a list */
	printf("generating list\n");
	int to = 100;
	while(to--)
		link_append(table, &to, sizeof(int));

	printf("print list of length %d\n", link_length(table) - 1);
	ii = link_iter_init(table);
	do {
		if(link_iter_content(ii))
			printf("%d ", *(int *) link_iter_content(ii));
	} while(!link_iter_next(ii));
	printf("\n");
	link_iter_free(ii);

	printf("shorten list by 25\n");
	link_shorten(table, 25);

	printf("print list of length %d\n", link_length(table) - 1);
	ii = link_iter_init(table);
	do {
		if(link_iter_content(ii))
			printf("%d ", *(int *) link_iter_content(ii));
	} while(!link_iter_next(ii));
	printf("\n");
	link_iter_free(ii);

	printf("truncate list to 56\n");
	link_truncate(table, 56);

	printf("print list of length %d\n", link_length(table) - 1);
	ii = link_iter_init(table);
	do {
		if(link_iter_content(ii))
			printf("%d ", *(int *) link_iter_content(ii));
	} while(!link_iter_next(ii));
	printf("\n");
	link_iter_free(ii);

	link_free(table);
	return 0;
}
