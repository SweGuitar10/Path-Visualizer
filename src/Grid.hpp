#pragma once
#include "GridBox.hpp"
#include <vector>

class Grid
{
public:
	Grid(sf::Vector2i size, int gridSize);
	~Grid();

	inline std::vector<GridBox *> getRows()
	{
		return _rows;
	};

	inline std::vector<GridBox *> getColumns()
	{
		return _columns;
	};

private:
	std::vector<GridBox *> _rows;
	std::vector<GridBox *> _columns;
	sf::Vector2i _gridSize;
	int _blockSize;

	void calculateBlockSize();
	void placeGrid();
};
