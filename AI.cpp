#include "AI.h"
#include <vector>

void AI::init(int aiPlayer) {
	_aiPlayer = aiPlayer;
	if (_aiPlayer == X_VAL) {
		_humanPlayer = O_VAL;
	}
	else {
		_humanPlayer = X_VAL;
	}
}

void AI::performMove(Board& board) {
	AIMove bestMove = getBestMove(board, _aiPlayer);
	board.setVal(bestMove.x, bestMove.y, _aiPlayer);
}

AIMove AI::getBestMove(Board& board, int player){
	int rv = board.checkVictory();
	if (rv == _aiPlayer){
		return AIMove(10);
	}
	else if (rv == _humanPlayer){
		return AIMove(-10);
	}
	else if (rv == TIE_VAL){
		return AIMove(0);
	}

	std::vector<AIMove> moves;

	// recursive
	for (int y = 0; y < board.getSize(); y++){
		for (int x = 0; x < board.getSize(); x++){
			if (board.getVal(x, y) == NO_VAL){
				AIMove move;
				move.x = x;
				move.y = y;
				board.setVal(x, y, player);
				if (player == _aiPlayer){
					move.score = getBestMove(board, _humanPlayer).score;
				}
				else{
					move.score = getBestMove(board, _aiPlayer).score;
				}
				moves.push_back(move);
				board.setVal(x, y, NO_VAL);
			}
		}
	}

	// pick the best move
	int bestMove = 0;
	if (player == _aiPlayer){
		int bestScore = -1000000;
		for (int i = 0; i < moves.size(); i++){
			if (moves[i].score > bestScore){
				bestMove = i;
				bestScore = moves[bestMove].score;
			}
		}
	}
	else{
		int bestScore = 1000000;
		for (int i = 0; i < moves.size(); i++){
			if (moves[i].score < bestScore){
				bestMove = i;
				bestScore = moves[bestMove].score;
			}
		}
	}
	return moves[bestMove];
}