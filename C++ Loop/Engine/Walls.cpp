#include "Walls.h"

void Walls::Add(std::mt19937& rng, const Board& brd, const Snake& snake)
{
	if (nUnit < nUnitMax )
	{
		std::uniform_int_distribution<int> xDist(0, brd.Get_Width() - 1);
		std::uniform_int_distribution<int> yDist(0, brd.Get_Heigth() - 1);

		Location newLoc;
		do
		{
			newLoc.x = xDist(rng);
			newLoc.y = yDist(rng);

		} while (snake.IsIntile(newLoc) && !IsExit(newLoc));
		
		units[nUnit].InitNewWall(newLoc);
		++nUnit;
	}
}

void Walls::Draw(Board& brd)
{
	for (int i = 0; i < nUnit; i++)
	{
		units[i].Draw(brd);
	}
}

bool Walls::IsExit(const Location& in_loc)const
{
	for (int i = 0; i < nUnit; i++)
	{
		if (in_loc == units[i].GetLocation())return false;
	}
	return true;
}

void Walls::Unit::Draw(Board& brd) const
{
	brd.DrawCell(loc, c);
}

void Walls::Unit::InitNewWall(Location& in_loc)
{
	loc = in_loc;
}

const Location& Walls::Unit::GetLocation() const
{
	return loc;
}
