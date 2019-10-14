#pragma once

#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int Get_Width() const;
	int Get_Heigth() const;
	bool IsinsideBoard(const Location& loc) const;
	void DrawBorder();
private:
	static constexpr Color borderColor = Colors::Blue;
	static constexpr int dimension = 20;
	static constexpr int width = 20;
	static constexpr int height = 20;
	static constexpr int cellPadding = 1;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr int x = 200;
	static constexpr int y = 100;
	Graphics& gfx;
};

