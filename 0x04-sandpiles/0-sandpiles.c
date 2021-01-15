#include "sandpiles.h"
#include <stdio.h>
#define SIZE 3
#define DETECT_TOPPLING(x) ((x) > 3)
#define IS_VALID(x) ((x) >= 0 &&  (x) <= 2)
/**
 * print_grid - prints the grid
 * @grid: sanpile to print
 *
 * Return: None
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * initial_sum - sums two sandpiles
 * @grid1: first sandpile to sum
 * @grid2: second sandpile to sum
 *
 * Return: None
 */
static void initial_sum(int grid1[3][3], int grid2[3][3])
{
	int row = 0, col = 0;

	for (row = 0; row < SIZE; row++)
	{
		for (col = 0; col < SIZE; col++)
		{
			grid1[row][col] = grid1[row][col] + grid2[row][col];
		}
	}
}

/**
 * scan_toppling - scans if the sandpile has more than 3 grains
 * @grid1: sandpile to analyze
 * @flags: position of sandpiles to analyze
 *
 * Return: 1 if sandpile has topling, 0 else
 */
static int scan_toppling(int grid1[3][3], int flags[3][3])
{
	int row = 0, col = 0, activated = 0;

	for (row = 0; row < SIZE; row++)
	{
		for (col = 0; col < SIZE; col++)
		{
			if (DETECT_TOPPLING(grid1[row][col]))
			{
				flags[row][col] = 1;
				activated = 1;
			}
		}
	}
	if (activated)
		return (1);
	return (0);
}

/**
 * do_toppling - scans if the sandpile has m
 * @grid1: sandpile to analyze
 * @flags: position of sandpiles to analyze
 *
 * Return: 1 if sandpile has topling, 0 else
 */
static int do_toppling(int grid1[3][3], int flags[3][3])
{
	int row = 0, col = 0, i = 0, newcol = 0, newrow = 0;
	int translate[] = {1, -1, 0, 0};

	for (row = 0; row < SIZE; row++)
	{
		for (col = 0; col < SIZE; col++)
		{
			if (DETECT_TOPPLING(grid1[row][col]) && flags[row][col])
			{
				grid1[row][col] = grid1[row][col] - 4;
				for (i = 0; i < 4; i++)
				{
					newrow = row + translate[i];
					newcol = col + translate[3 - i];
					if (IS_VALID(newrow) && IS_VALID(newcol))
						grid1[newrow][newcol]++;
				}
			}
		}
	}
	return (0);
}

/**
 * sandpiles_sum - finds the sum of two sandpiles
 * @grid1: first sandpile to sum
 * @grid2: second sandpile to sum
 *
 * Return: None
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int flags[3][3];
	int row = 0, col = 0;

	initial_sum(grid1, grid2);

	for (row = 0; row < SIZE; row++)
	{
		for (col = 0; col < SIZE; col++)
		{
			flags[row][col] = 0;
		}
	}
	while (scan_toppling(grid1, flags))
	{
		printf("=\n");
		print_grid(grid1);
		do_toppling(grid1, flags);
		for (row = 0; row < SIZE; row++)
		{
			for (col = 0; col < SIZE; col++)
			{
				flags[row][col] = 0;
			}
		}
	}
}
