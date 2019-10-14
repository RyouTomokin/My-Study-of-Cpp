#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snake, const Walls& wall)
{
	Respawn(rng, brd, snake, wall);
}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snake& snake, const Walls& wall)
{
	std::uniform_int_distribution<int> xDist(0, brd.Get_Width() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.Get_Heigth() - 1);

	Location newLoc;
	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);

	} while (snake.IsIntile(newLoc) && !wall.IsExit(newLoc));

	loc = newLoc;
}

void Goal::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

const Location& Goal::GetLocation() const
{
	return loc;
}
