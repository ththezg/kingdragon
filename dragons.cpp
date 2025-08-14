#include "dragons.h"

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

//3.1 MapElement class implementation
MapElement::MapElement(ElementType t, int in_req_dmg)
    : type(t), req_dmg(in_req_dmg) {}

MapElement::~MapElement() {}

ElementType MapElement::getType() const {
    return type;
}

int MapElement::getReqDmg() const {
    return req_dmg;
}

// 3.2 Map class implementation
Map::Map(int rows, int cols,
         int num_obst, Position *obst,
         int num_gro_obst, Position *gro_obst)
    : num_rows(rows), num_cols(cols) {
    grid = new MapElement**[num_rows];
    for (int i = 0; i < num_rows; ++i) {
        grid[i] = new MapElement*[num_cols];
        for (int j = 0; j < num_cols; ++j) {
            grid[i][j] = new MapElement(PATH);
        }
    }

    // Initialize obstacles
    for (int i = 0; i < num_obst; ++i) {
        grid[obst[i].getRow()][obst[i].getCol()] = new MapElement(OBSTACLE);
    }

    // Initialize ground obstacles
    for (int i = 0; i < num_gro_obst; ++i) {
        grid[gro_obst[i].getRow()][gro_obst[i].getCol()] = new MapElement(GROUND_OBSTACLE);
    }
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////