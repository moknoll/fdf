#include "libft.h"


int main()
{
	char *line;
	int fd = open("test.txt", O_RDONLY);

	line = get_next_line(fd);

	printf("%s", line);
}
