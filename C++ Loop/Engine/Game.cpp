/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(std::random_device()()),
	snake({ 2,2 }),
	goal(rng, brd, snake, wall)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = ft.Mark();
	if (gameIsStart)
	{
		if (!gameIsOver)
		{
			if (wnd.kbd.KeyIsPressed(VK_UP))
			{
				delta_loc = { 0,-1 };
			}
			if (wnd.kbd.KeyIsPressed(VK_DOWN))
			{
				delta_loc = { 0,1 };
			}
			if (wnd.kbd.KeyIsPressed(VK_LEFT))
			{
				delta_loc = { -1,0 };
			}
			if (wnd.kbd.KeyIsPressed(VK_RIGHT))
			{
				delta_loc = { 1,0 };
			}

			++snakeMoveCounter;
			if (snakeMoveCounter >= snakeMovePeriod)
			{
				snakeMoveCounter = 0;
				const Location next = snake.GetnextHeadLocation(delta_loc);
				if (!brd.IsinsideBoard(next) ||
					snake.IsIntileExceptEnd(next))
				{
					gameIsOver = true;
				}
				else
				{
					if (!wall.IsExit(next))
					{
						gameIsOver = true;
					}
					else
					{
						const bool eating = next == goal.GetLocation();
						if (eating)
						{
							snake.Grow();
							wall.Add(rng, brd, snake);
							++snakeSpeedUpCounter;
							if (snakeSpeedUp <= snakeSpeedUpCounter)
							{
								snakeMovePeriod = std::max(snakeMovePeriod - 1, snakeMaxSpeed);
							}
						}
						snake.MoveBy(delta_loc);
						if (eating)
						{
							goal.Respawn(rng, brd, snake, wall);
						}
					}

				}

			}
		}
	}
	else
	{
		gameIsStart = wnd.kbd.KeyIsPressed(VK_RETURN);
	}
}

void Game::ComposeFrame()
{
	if (gameIsStart)
	{
		snake.Draw(brd);
		goal.Draw(brd);
		wall.Draw(brd);
		if (gameIsOver)
		{

		}
		brd.DrawBorder();
	}
	else
	{
		gfx.DrawCircle(400, 300, 50, Colors::Yellow);
	}
}
