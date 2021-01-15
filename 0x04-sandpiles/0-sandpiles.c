#include "sandpiles.h"

#define FALSE  0
#define TRUE   1

/**
 * sandpiles_sum - Add grid2 to grid1 and make sure is a stable sandpile
 * @grid1: First sandpile
 * @grid2: Second sandpile
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row = 0, col = 0;

	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
		{
			grid1[row][col] = grid1[row][col] + grid2[row][col];
		}
	while (validate_sandpile(grid1) != TRUE)
	{
		printf("=\n");
		print_my_grid(grid1);
		do_toppling(grid1);
	}
}

/**
 * validate_sandpile - Check if the sandpile is stable or no
 * @grid1: Sandpile
 *
 * Return: FALSE if is not stable, TRUE if is stable
 */
int validate_sandpile(int grid1[3][3])
{
	int row = 0, col = 0;

	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			if (grid1[row][col] > 3)
				return (FALSE);
	return (TRUE);
}

/**
 * do_toppling - Do the toppling to the sandpile
 * @grid1: sandpile to do the toppling
 *
 * Return: Nothing
 */
void do_toppling(int grid1[3][3])
{
	int row = 0, col = 0;
	int flags[3][3];

	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			flags[row][col] = 0;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (grid1[row][col] > 3)
			{
				grid1[row][col] = grid1[row][col] - 4;
				if ((col - 1 >= 0) && (col - 1 < 3)) /* cell up */
					flags[row][col - 1]++;
				if ((row + 1 >= 0) && (row + 1 < 3)) /* cell right */
					flags[row + 1][col]++;
				if ((col + 1 >= 0) && (col + 1 < 3)) /* cell down */
					flags[row][col + 1]++;
				if ((row - 1 >= 0) && (row - 1 < 3)) /* cell left */
					flags[row - 1][col]++;
			}
		}
	}
	for (row = 0; row < 3; row++)
		for (col = 0; col < 3; col++)
			grid1[row][col] += flags[row][col];
}

/**
 * print_my_grid - Print 3x3 grid
 * @grid: The grid
 * Return: Nothing
 */
void print_my_grid(int grid[3][3])
{
	int row = 0, col = 0;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (col)
				printf(" ");
			printf("%d", grid[row][col]);
		}
		printf("\n");
	}
}
