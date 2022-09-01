#include "Grid.hpp"

Grid::Grid(sf::Vector2i gridSize, int blockSize)
{
	int rowSize = gridSize.x / blockSize;
	int colSize = gridSize.y / blockSize;

	_gridSize = gridSize;
	_blockSize = blockSize;

	for (size_t i = 0; i < rowSize; i++)
	{
		_rows.push_back(new GridBox(sf::Vector2f(_blockSize, _blockSize)));
	}

	for (size_t i = 0; i < colSize; i++)
	{
		_columns.push_back(new GridBox(sf::Vector2f(_blockSize, _blockSize)));
	}
}

Grid::~Grid()
{
	for (size_t i = 0; i < _rows.size(); i++)
	{
		delete _rows[i];
	}
	
	for (size_t i = 0; i < _columns.size(); i++)
	{
		delete _columns[i];
	}
	
}

void Grid::placeGrid()
{
}

void Grid::calculateBlockSize()
{
}