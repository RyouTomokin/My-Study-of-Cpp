#include "Draw2DBox.h"
#include "MainWindow.h"

Draw2DBox::Draw2DBox()
{}

void Draw2DBox::CtrlerUpdate(MainWindow& wnd)
{
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		--y0;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		++y0;
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		--x0;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		++x0;
	}
	if (wnd.mouse.LeftIsPressed())
	{
		x1 = wnd.mouse.GetPosX();
		y1 = wnd.mouse.GetPosY();
	}
}

void Draw2DBox::DrawIt(Graphics& gfx)
{
	gfx.DrawRectXY(x0, y0, x1, y1, Colors::Yellow);
}
