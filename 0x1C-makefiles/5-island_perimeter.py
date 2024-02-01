#!/usr/bin/python3
"""Island Perimeter module"""


def island_perimeter(grid):
    """Calculates Island Perimeter"""
    perim = 0

    for row in range(len(grid)):
        for col in range(len(grid[row])):
            if grid[row][col] == 1:
                perim += 4
                if row < len(grid) - 1 and grid[row + 1][col] == 1:
                    perim -= 2
                if col < len(grid[row]) - 1 and grid[row][col + 1] == 1:
                    perim -= 2

    return perim
