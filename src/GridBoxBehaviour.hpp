#pragma once
#include <SFML/Graphics.hpp>
#include "GridBox.hpp"

class GridBoxBehaviour
{
public:
    GridBoxBehaviour();
    ~GridBoxBehaviour();

    void setObstacle(GridBox& box);
    void setStart(GridBox& box);
    void setEnd(GridBox& box);
    void setEmpty(GridBox& box);

private:
    GridBox* _boxStart;
    GridBox* _boxEnd;
    GridBox _nullBox;
    //GridBoxBehaviour() {}
};
