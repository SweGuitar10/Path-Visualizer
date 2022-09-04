#include "Grid.hpp"

Grid::Grid(sf::Vector2i gridSize, int blockSize)
{
	rowSize = gridSize.x / blockSize;
	colSize = gridSize.y / blockSize;

	_gridSize = gridSize;
	_blockSize = blockSize;

	float posX = 0, posY = 0;

	for (size_t i = 0; i < colSize; i++)
	{
		std::vector<GridBox> gridBoxRows;

		for (size_t j = 0; j < rowSize; j++)
		{
			GridBox box(sf::Vector2f(blockSize, blockSize));
			box.setColor(sf::Color::White);
			box.setPosition(sf::Vector2f(posX, posY));
			gridBoxRows.push_back(box);
			posX += blockSize;
		}
		posY += blockSize;
		posX = 0;
		gridBoxCols.push_back(gridBoxRows);
	}

	_nullBox = GridBox(-1, GridBox::GridType::Null);
}

Grid::~Grid()
{

}

void Grid::placeGrid(sf::RenderWindow& window)
{
	for (size_t i = 0; i < colSize; i++)
	{
		for (size_t j = 0; j < rowSize; j++)
		{
			window.draw(gridBoxCols[i][j].getRectangleShape());
		}
	}
}

void Grid::setGridBoxColor(sf::Vector2f pos, sf::Color color)
{
	for (size_t i = 0; i < colSize; i++)
	{
		for (size_t j = 0; j < rowSize; j++)
		{
			if (gridBoxCols[i][j].getPosition() == pos)
			{
				gridBoxCols[i][j].setColor(color);
			}
		}
	}
}

GridBox& Grid::getGridBox(sf::Vector2f pos)
{
	for (size_t i = 0; i < colSize; i++)
	{

		for (size_t j = 0; j < rowSize; j++)
		{
			sf::Vector2f rectPos = gridBoxCols[i][j].getPosition();

			if (pos.x <= rectPos.x + _blockSize && pos.x >= rectPos.x
				&& pos.y <= rectPos.y + _blockSize && pos.y >= rectPos.y)
			{
				return gridBoxCols[i][j];
			}
		}
	}
	return _nullBox;
}