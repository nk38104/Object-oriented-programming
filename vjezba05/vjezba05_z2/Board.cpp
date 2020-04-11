#include "Board.h"

Board::Board(unsigned int r, unsigned int c, char fs)
{	
	check_row_column(r); 
	check_row_column(c);

	rows = r;
	columns = c;
	frameSymbol = fs;

	board = new char*[r];
	for (unsigned int i = 0; i < r; ++i) { board[i] = new char[c]; }

	set_board();
}

void Board::check_row_column(unsigned int& n) {
	if (n <= 2) {
		do {
			cout << "Row or column number too low. Please, enter number greater than 2: ";
			cin >> n;
		} while (n <= 2);
	}
}

void Board::set_board() {
	for (unsigned int i = 0; i < rows; ++i) {
		for (unsigned int j = 0; j < columns; ++j) {
			board[i][j] = (i == 0 || i == rows - 1 || j == 0 || j == columns - 1) ? frameSymbol : ' ';
		}
	}
}

void Board::draw_up_line(Point p, char ch) 
{
	int x = to_int(p.getX()), y = to_int(p.getY());

	if (validate_point(x, y)) {
		while (x != 0) { 
			draw_char(x, y, ch); 
			--x; 
		}
	}
}

bool Board::validate_point(int x, int y) {
	return ((x > 0) && (x < rows - 1) && (y > 0) && (y < columns - 1));
}

void Board::draw_line(Point p1, Point p2, char ch)
{
	int x1 = to_int(p1.getX()), y1 = to_int(p1.getY()), x2 = to_int(p2.getX()), y2 = to_int(p2.getY());

	if (validate_point(x1, y1) && validate_point(x2, y2))
	{
		if (y1 == y2) { draw(x1, y1, x2, ch, updown, verthor); }  // 1 indicates it's up or down direction(v-h)/bottom-right to top-left and vice versa(d) 
		else if (x1 == x2) { draw(y1, x1, y2, ch, leftright, verthor); }  // 2(can be any other than 1) for left or right direction(v-h)/bottom-left to top-right and vice versa(d)
		else {
			if (check_diagonal(x1, y1, x2, y2)) {  // checks possibility of drawing diagonal
				directions dir = (check_direction(x1, y1, x2, y2)) ? brtl : bltr;
				draw(x1, y1, x2, ch, dir, diagonal);
			}
			else { cout << "Couldn't draw one diagonal line. Please make sure points are diagonal." << endl; }
		}
	}
}

void Board::draw(int c1, int c1xy, int c2, char ch, const directions dir, const angles angl) 
{
	// Could make this with only one while but than for vertical and horizontal case, in every iteration
	// it would need to unnecessary check is it diagonal case because both coordinates need to be changed in diag case
	// (x coord change is always same, but y changes depending on direciton in diagonal case)
	if (angl == verthor) {
		// Order of function arugments is determined by direction for vertical/horizontal so I can use same function
		// If it's up/down y is constant, so x needs to be incremented/decremented untill it gets to other x,
		// and for left/right it's reversed( x constant, y needs to change )
		while (c1 != c2) {
			(dir == updown) ? draw_char(c1, c1xy, ch) : draw_char(c1xy, c1, ch);
			(c1 > c2) ? --c1 : ++c1; // Incr/decr depeneding on other cooridinate(inconstant) position(lower/higher)
		}
		(dir == updown) ? draw_char(c1, c1xy, ch) : draw_char(c1xy, c1, ch);
	}
	else {
		while (c1 != c2) {
			draw_char(c1, c1xy, ch);
			if (dir == brtl) {   // bottom-right to top-left or vice versa direction
				(c1 > c2) ? --c1xy : ++c1xy;
			}
			else {	// bottom-left to top-right or vice versa direction
				(c1 > c2) ? ++c1xy : --c1xy;
			}
			(c1 > c2) ? --c1 : ++c1;
		}
		draw_char(c1, c1xy, ch);
	}		
}

bool Board::check_diagonal(int x1, int y1, int x2, int y2) {
	directions dir = (check_direction(x1, y1, x2, y2)) ? brtl : bltr; // Get direction so we know which way to go
	
	while (x1 != x2) {  // Go from one point diagonally untill you reach other point
		if (dir == brtl) {   // Go in direction br-tl or vice verse 
			(x1 > x2) ? --y1 : ++y1; 
		}
		else { 
			(x1 > x2) ? ++y1 : --y1; // Go bl-tr or vice versa
		}
		(x1 > x2) ? --x1 : ++x1;
	}
	return (y1 == y2) ? true : false;
}

bool Board::check_direction(int x1, int y1, int x2, int y2) {
	return ((x1 > x2 && y1 > y2) || (x1 < x2 && y1 < y2)); // Checks for br-tl and vice versa if returns false we know it's bl-tr
}

void Board::draw_board() 
{
	for (unsigned int i = 0; i < rows; ++i) {
		for (unsigned int j = 0; j < columns - 1; ++j) { 
			cout << board[i][j] << " ";
		}
		cout << board[i][columns - 1] << endl;
	}
}

Board::~Board()
{
	for (unsigned int i = 0; i < rows; ++i) { 
		delete[] board[i]; 
	}
	delete[] board;
}

