#pragma once
#include <SFML/Graphics.hpp>
#include "GridBox.hpp"

class GridBoxBehaviour
{
public:
    GridBoxBehaviour();
    ~GridBoxBehaviour();

    void setColorObstacle(GridBox& box);
    void setColorStart(GridBox& box);
    void seColorEnd(GridBox& box);
    void setColorEmpty(GridBox& box);
    void setColorPath(GridBox& box);

private:
    GridBox* _boxStart;
    GridBox* _boxEnd;
    GridBox _nullBox;
    //GridBoxBehaviour() {}
};
