#!/usr/bin/python3
"""A module that defines an island perimeter measuring function."""


def island_perimeter(grid):
    """Returns the perimiter of an island described in grid.

    Args:
        grid (list): A list of list of integers where 1 represents
                     a land zone and 0 represents a water zone.
    Returns:
            Perimeter of the island.
    """
    edge = 0
    lan = 0

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                lan += 1
                if (j > 0 and grid[i][j - 1] == 1):
                    edge += 1
                if (i > 0 and grid[i - 1][j] == 1):
                    edge += 1
    perimeter = lan * 4 - edge * 2
    return perimeter
