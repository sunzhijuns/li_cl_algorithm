//
// Created by sunzhijun on 18-2-6.
//

// sort algorithm example
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector
#include "AStar.h"


int main(){
    TileType map_data[MAXROW][MAXCOL] = {0};
    for (int i = 0; i < MAXROW; ++i) {
        for (int j = 0; j < MAXCOL; ++j) {
            map_data[i][j] = Tile_Open;
        }
    }
    AStar::run(map_data,8,8,1,1,5,5);
    return 0;
}
