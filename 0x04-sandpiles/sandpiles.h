#ifndef _SANDPILES_H
#define _SANDPILES_H

#include <stdio.h>
#include <stdlib.h>

int validate_sandpile(int grid[3][3]);
void do_toppling(int grid1[3][3]);
void print_my_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif
