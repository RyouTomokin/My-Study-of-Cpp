#pragma once
#include "Snake.h"
#include "Board.h"
#include <random>

class Walls
{
private:
	class Unit
	{
	public:
		void Draw(Board& brd) const;
		void InitNewWall(Location& in_loc);
		const Location& GetLocation()const;
	private:
		Location loc;
	};
public:
	void Add(std::mt19937& rng, const Board& brd, const Snake& snake);
	void Draw(Board& brd);
	bool IsExit(const Location& in_loc)const;
private:
	static constexpr int nUnitMax = 20;
	Unit units[nUnitMax];
	int nUnit = 0;
	static constexpr Color c = Colors::Gray;
	
};

