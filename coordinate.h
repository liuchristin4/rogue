#ifndef _COORDINATE_H_
#define _COORDINATE_H_

struct Coordinate {
    int x;
    int y;

    bool operator==(const Coordinate &other){
        return (this->x == other.x && this->y == other.y);
    }
};

#endif