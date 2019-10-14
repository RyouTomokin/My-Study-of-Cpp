#pragma once
#include "Graphics.h"
#include "Keyboard.h"
#include "Mouse.h"

class Draw2DBox
{
public:
	Draw2DBox();
	void CtrlerUpdate(class MainWindow& wnd);
	void DrawIt(Graphics& gfx);
private:
	int xPox = 100;
	int yPox = 100;
	int x0 = 200;
	int x1 = 400;
	int y0 = 200;
	int y1 = 400;
};

