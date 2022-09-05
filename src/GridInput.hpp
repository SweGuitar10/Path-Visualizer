#pragma once
#include "GridBox.hpp"
#include "GridBoxBehaviour.hpp"

class GridInput
{
public:
    GridInput();
    ~GridInput();
    void handleMouseInput(GridBox& box);
private:
    GridBoxBehaviour _boxBehaviour;
};
