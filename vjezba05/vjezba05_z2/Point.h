#pragma once
class Point
{
private:
	double x, y;
public:
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	Point(const Point& p) { x = p.x; y = p.y; }
	void set_XY(double x, double y) { this->x = x; this->y = y; } // made it just to play with shapes, so I don't need to call setX and setY for every change of whole point
	void setX(double x) { this->x = x; }
	double getX() const {return x; }
	void setY(double y) { this->y = y; }
	double getY() { return y; }
};

