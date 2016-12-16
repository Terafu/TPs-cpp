#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

struct cell {
	bool wall_top;
	bool wall_bottom;
	bool wall_left;
	bool wall_right;
	bool visited;
	bool to_visit;
};

class Maze {
	
	int width;
	int height;

public:

	Maze(int _height, int _width) {

		width = _width;
		height = _height;

		// Declaration
		cell ** maze = new cell*[width];
		for (int i = 0; i < width; i++) {
			maze[i] = new cell[height];
		}

		// Initialisation
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				maze[i][j].wall_top = true;
				maze[i][j].wall_bottom = true;
				maze[i][j].wall_left = true;
				maze[i][j].wall_right = true;
				maze[i][j].visited = false;
				maze[i][j].to_visit = false;
			}
		}

		GenerateMaze(maze);
		ShowMaze(maze);
	}

	void GenerateMaze(cell ** _maze) {

		srand(time(NULL));

		// Pick a random cell on the left of the maze to have an enter
		int x = rand() % width;
		int y = 0;

		// First cell we destroy the exterior wall (first cell is to the left but in a radom line)
		_maze[x][y].wall_left = false;
		_maze[x][y].visited = true;

		// Count of cells to visit
		int cells_to_visit = 0;

		// Count the number of wall we can destroy (init to 0 bescause we already destroy the first cell wall before)
		int wall_to_destroy = 0;

		// This is to choose the next cell randomly
		int pick_random_cell;

		// This is to choose the wall to destroy randomly
		int pick_random_wall;

		while (cells_to_visit>=0) {

			pick_random_cell = 0;
			pick_random_wall = 0;
			wall_to_destroy = 0;

			// mark the neigbours cells if not visited
			if (x + 1 < width) {
				if (_maze[x + 1][y].visited == false) {
					_maze[x + 1][y].to_visit = true;
					cells_to_visit++;
				}
			}

			if (x - 1 >= 0) {
				if (_maze[x - 1][y].visited == false) {
					_maze[x - 1][y].to_visit = true;
					cells_to_visit++;
				}
			}

			if (y + 1 < height) {
				if (_maze[x][y + 1].visited == false) {
					_maze[x][y + 1].to_visit = true;
					cells_to_visit++;
				}
			}

			if (y - 1 >= 0) {
				if (_maze[x][y - 1].visited == false) {
					_maze[x][y - 1].to_visit = true;
					cells_to_visit++;
				}
			}

			// We have the neighbour, now we choose a random cell mark as neighbour to be the next cell to visit
			if (cells_to_visit > 0) {
				pick_random_cell = rand() % cells_to_visit;
				for (int i = 0; i < width; i++) {
					for (int j = 0; j < height; j++) {

						if (_maze[i][j].visited == false && _maze[i][j].to_visit == true) {
							pick_random_cell--;
						}

						if (pick_random_cell == -1) {
							x = i;
							y = j;
							i = width;
							j = height;
						}
					}
				}

				// Add the cell to visited
				_maze[x][y].visited = true;
				cells_to_visit--;

				// count the walls to destroy
				if (x + 1 < width) {
					if (_maze[x + 1][y].visited == true) {
						wall_to_destroy++;
					}
				}

				if (x - 1 >= 0) {
					if (_maze[x - 1][y].visited == true) {
						wall_to_destroy++;
					}
				}

				if (y + 1 < height) {
					if (_maze[x][y + 1].visited == true) {
						wall_to_destroy++;
					}
				}

				if (y - 1 >= 0) {
					if (_maze[x][y - 1].visited == true) {
						wall_to_destroy++;
					}
				}

				if (wall_to_destroy > 0) {

					pick_random_wall = rand() % wall_to_destroy;

					if (x + 1 < width) {
						if (_maze[x + 1][y].visited == true) {
							pick_random_wall--;
							if (pick_random_wall == -1) {
								_maze[x + 1][y].wall_top = false;
								_maze[x][y].wall_bottom = false;
							}

							else {
								_maze[x + 1][y].wall_top = true;
								_maze[x][y].wall_bottom = true;
							}
						}
					}

					if (x - 1 >= 0) {
						if (_maze[x - 1][y].visited == true) {
							pick_random_wall--;
							if (pick_random_wall == -1) {
								_maze[x - 1][y].wall_bottom = false;
								_maze[x][y].wall_top = false;
							}

							else {
								_maze[x - 1][y].wall_bottom = true;
								_maze[x][y].wall_top = true;
							}
						}
					}

					if (y + 1 < height) {
						if (_maze[x][y + 1].visited == true) {
							pick_random_wall--;
							if (pick_random_wall == -1) {
								_maze[x][y + 1].wall_left = false;
								_maze[x][y].wall_right = false;
							}

							else {
								_maze[x][y + 1].wall_left = true;
								_maze[x][y].wall_right = true;
							}
						}
					}

					if (y - 1 >= 0) {
						if (_maze[x][y - 1].visited == true) {
							pick_random_wall--;
							if (pick_random_wall == -1) {
								_maze[x][y - 1].wall_right = false;
								_maze[x][y].wall_left = false;
							}

							else {
								_maze[x][y - 1].wall_right = true;
								_maze[x][y].wall_left = true;
							}
						}
					}
				}
			}

			// To stop the while
			else {
				cells_to_visit--;
			}
		}// end while

		// Pick a random cell on the right of the maze to have an exit
		x = rand() % width;
		y = height-1;

		// Last cell we destroy the exterior wall (last cell is to the right but in a random line)
		_maze[x][y].wall_right = false;
	}

	void ShowMaze(cell ** _maze) {

		for (int j = 0; j < height; j++) {
			if (_maze[0][j].wall_top) {
				std::cout << "__";
			}

			else {
				std::cout << "  ";
			}
		}

		std::cout << "\n";

		for (int i = 0; i < width; i++) {
			
			if (_maze[i][0].wall_left) {
				std::cout << "|";
			}

			else {
				std::cout << " ";
			}

			for (int j = 0; j < height; j++) {
				
				if (_maze[i][j].wall_bottom) {
					std::cout << "_";
				}

				else {
					std::cout << " ";
				}

				if (_maze[i][j].wall_right) {
					std::cout << "|";
				}

				else {
					if (_maze[i][j].wall_bottom) {
						std::cout << "_";
					}

					else {
						std::cout << " ";
					}
				}
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
};