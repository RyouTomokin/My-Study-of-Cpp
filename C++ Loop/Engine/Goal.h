#pragma once

#include "Snake.h"
#include "Board.h"
#include "Walls.h"
#include <random>

class Goal
{
public:
	Goal(std::mt19937& rng, const Board& brd, const Snake& snake, const Walls& wall);
	void Respawn(std::mt19937& rng, const Board& brd, const Snake& snake, const Walls& wall);
	void Draw(Board& brd)const;
	const Location& GetLocation() const;
private:
	static constexpr Color c = Colors::Red;
	Location loc;
};