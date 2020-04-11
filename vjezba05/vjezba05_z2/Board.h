#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include "Point.h"

using namespace std;

enum angles { verthor, diagonal };
enum directions { updown, leftright, brtl, bltr }; //brtl(bottom-right top-left), bltr(bottom-left top-right)

class Board : public Point
{
private:
	void set_board();
	void check_row_column(unsigned int&);
	bool validate_point(int, int);
	bool check_diagonal(int, int, int, int);
	void draw(int, int, int, char, const directions, const angles);
	bool check_direction(int, int, int, int);
	int to_int(double x) { return int(rint(x)); }

public:
	char **board;
	unsigned int rows, columns;
	char frameSymbol;

	Board(unsigned int r = 8, unsigned int c = 8, char fs = 'x');
	Board(const Board& b2) { board = b2.board; 
						   	 rows = b2.rows; 
							 columns = b2.columns; 
							 frameSymbol = b2.frameSymbol; };
	void draw_char(int x, int y, char ch) { board[x][y] = ch; }
	void draw_up_line(Point, char);
	void draw_line(Point, Point, char);
	void draw_board();
	~Board();
};


