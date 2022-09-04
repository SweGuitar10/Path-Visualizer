#pragma once
#include "GridBox.hpp"
#include <vector>

class Grid
{
public:
	Grid(sf::Vector2i size, int gridSize);
	~Grid();

	inline std::vector<std::vector<GridBox>> getGridBoxCols()
	{
		return gridBoxCols;
	};
	GridBox getNullBox() { return _nullBox; }

	void placeGrid(sf::RenderWindow& window);
	void setGridBoxColor(sf::Vector2f pos, sf::Color color);
	GridBox& getGridBox(sf::Vector2f pos);

private:

	sf::Vector2i _gridSize;
	int _blockSize;
	int rowSize;
	int colSize;
	std::vector<std::vector<GridBox>> gridBoxCols;
	GridBox _nullBox;
};
