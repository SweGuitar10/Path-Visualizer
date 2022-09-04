#pragma once
#include <SFML/Graphics.hpp>
#include "GridBox.hpp"

class GridBoxBehaviour
{
public:
    GridBoxBehaviour();
    ~GridBoxBehaviour();

    static void setObstacle(GridBox& box);
    static void setStart(GridBox& box);
    static void setEnd(GridBox& box);
    static void setEmpty(GridBox& box);

private:

};
