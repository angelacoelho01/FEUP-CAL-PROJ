#ifndef SRC_UTIL_POSITION_H
#define SRC_UTIL_POSITION_H

// Represents the coordinates of a point in the graph: (x, y)
class Position {
public:
    Position() = default;
    Position(double x, double y);
    Position(const Position &pos);

    double getX() const;
    double getY() const;

    void setX(double x);
    void setY(double y);

    double euclideanDistance(const Position &p2) const;
private:
    double _x{};
    double _y{};
};

#endif //SRC_UTIL_POSITION_H
