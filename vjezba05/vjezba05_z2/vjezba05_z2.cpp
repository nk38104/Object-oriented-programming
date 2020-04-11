#include "Board.h"

void draw_beg_end(Board& board, Point, Point, double, double, double, double, double, double);
void draw_c(Board&, Point, Point);
void draw_plus(Board&, Point, Point, double, double, double, double, double, double, double, double);

#define SYMB '$'

int main()
{
	Board board(17, 35, 'X');
	Point p1(15, 2), p2;

	board.draw_up_line(p1, '|');

	draw_beg_end(board, p1, p2, 8, 4, 5, 7, 11, 7);
	draw_c(board, p1, p2);
	draw_plus(board, p1, p2, 10, 17, 6, 17, 8, 15, 8, 19);
	draw_plus(board, p1, p2, 10, 23, 6, 23, 8, 21, 8, 25);
	draw_beg_end(board, p1, p2, 8, 30, 5, 27, 11, 27);
		
	p1.set_XY(15, 32);
	board.draw_up_line(p1, '|');

	board.draw_board();

	return 0;
}

void draw_beg_end(Board& board, Point p1, Point p2, double x1, double y1, double x2, double y2, double x3, double y3) {
	p1.set_XY(x1, y1), p2.set_XY(x2, y2);
	board.draw_line(p1, p2, SYMB);
	p2.set_XY(x3, y3);
	board.draw_line(p1, p2, SYMB);
}

void draw_c(Board& board, Point p1, Point p2) {
	p1.set_XY(10, 9), p2.set_XY(6, 9);
	board.draw_line(p1, p2, SYMB);
	p1.set_XY(5, 10), p2.set_XY(5, 13);
	board.draw_line(p1, p2, SYMB);
	p1.set_XY(11, 10), p2.set_XY(11, 13);
	board.draw_line(p1, p2, SYMB);
}

void draw_plus(Board& board, Point p1, Point p2, double x1, double y1, double x2, double y2,
				double x3, double y3, double x4, double y4) {
	p1.set_XY(x1, y1), p2.set_XY(x2, y2);
	board.draw_line(p1, p2, SYMB);

	p1.set_XY(x3, y3), p2.set_XY(x4, y4);
	board.draw_line(p1, p2, SYMB);
}

