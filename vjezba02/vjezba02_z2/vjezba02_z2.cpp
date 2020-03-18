#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct _Point{
	int x, y;
} Point;

typedef struct _Circle{
	Point center;
	int radius;
} Circle;

Circle* create_array_of_circles(int);
void num_of_rectangle_intersecting(Circle *, int&, int);
bool is_intersecting(int, int, int, int, int, int);

int main()
{
	int size = 2, intersectionCnt;

	Circle *circle_arr = create_array_of_circles(size);

	num_of_rectangle_intersecting(circle_arr, intersectionCnt, size);

	cout << "Number of rectangles intersecting: " << intersectionCnt << endl;

	delete[] circle_arr;
	circle_arr = NULL;

	return 0;
}

Circle* create_array_of_circles(int size)
{
	Circle* new_circle_arr = new Circle[size];

	for (int i = 0; i < size; i++) {
		cout << "Circle[" << i + 1 << "] x: ";
		cin >> new_circle_arr[i].center.x;
		cout << "Circle[" << i + 1 << "] y: ";
		cin >> new_circle_arr[i].center.y;
		cout << "Circle[" << i + 1 << "] radius: ";
		cin >> new_circle_arr[i].radius;
		cout << endl;
	}
	return new_circle_arr;
}

void num_of_rectangle_intersecting(Circle *circle, int& interCnt, int size)
{
	interCnt = 0;

	for (int i = 1; i < size; i++) {
		if (is_intersecting(circle[0].radius, circle[i].radius, circle[0].center.x, circle[0].center.y, circle[i].center.x, circle[i].center.y)) {
			interCnt++;
		}
	}
}


bool is_intersecting(int r1, int r2, int x1, int y1, int x2, int y2)
{
	if (pow((r1 + r2), 2) > pow((x2 - x1), 2) + pow((y2 - y1), 2)) {
		return true;
	}
	return false;
 }