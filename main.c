#include "get_next_line_bonus.h"
#include <stdio.h>

int main()
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	fd1 = open("text.txt", O_RDONLY);
	fd2 = open("text1.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		printf("Error");
		return (1);
	}
	line1 = get_next_line_bonus(fd1);
	line2 = get_next_line_bonus(fd2);
	while (line1 != NULL || line2 != NULL)
	{
		if (line1)
		{
			printf("%s", line1);
			free(line1);
			line1 = get_next_line_bonus(fd1);
		}
		if (line2)
		{
			printf("%s", line2);
			free(line2);
			line2 = get_next_line_bonus(fd2);
		}
	}
	close(fd1);
	close(fd2);
	return(0);
}
