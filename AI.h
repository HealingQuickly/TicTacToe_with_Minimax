#pragma once

#include "Board.h"

struct AIMove{
	AIMove() {}
	AIMove(int s) : score(s) {}
	int x;
	int y;
	int score;
};

class AI {
public:
	// Initializes the AI player
	void init(int aiPlayer);
	// Performs the AI move
	void performMove(Board& board);
private:
	AIMove getBestMove(Board& board, int player);
	int _aiPlayer; ///< Index of the AI
	int _humanPlayer; ///< Index of the player
};

