#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

void Board::DrawCell(const Location& loc, Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);

	const int off_x = x;
	const int off_y = y;

	int out_x = loc.x * dimension + off_x + cellPadding;
	int out_y = loc.y * dimension + off_y + cellPadding;
	int out_w = dimension - cellPadding * 2;
	int out_h = dimension - cellPadding * 2;

	gfx.DrawRectWH(out_x, out_y, out_w, out_h, c);
}

int Board::Get_Width() const
{
	return width;
}

int Board::Get_Heigth() const
{
	return height;
}

bool Board::IsinsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x < width &&
		loc.y >= 0 && loc.y < height;
}

void Board::DrawBorder()
{
	const int top = y - borderWidth - borderPadding;
	const int left = x - borderWidth - borderPadding;
	const int bottom = top + (borderWidth + borderPadding) * 2 + height * dimension;
	const int right = left + (borderWidth + borderPadding) * 2 + width * dimension;

	//ио
	gfx.DrawRectXY(left, top, right, top + borderWidth, borderColor);
	//вС
	gfx.DrawRectXY(left, top + borderWidth, left + borderWidth, bottom - borderWidth, borderColor);
	//ср
	gfx.DrawRectXY(right - borderWidth, top + borderWidth, right, bottom - borderWidth, borderColor);
	//об
	gfx.DrawRectXY(left, bottom - borderWidth, right, bottom, borderColor);
}
