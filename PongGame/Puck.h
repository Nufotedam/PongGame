#pragma once
#include "Paddle.h"

class Puck
{
public:
	Puck(int _X, int _y, int _dx, int _dy);
	void Print() const;
	void Clean() const;
	void BallMovement(int width_i, int width_f, int height_i, int height_f, Paddle _player1, Paddle _player2, int& _scoreP1, int& _scoreP2);
	void Reset(int _resetx, int _resety);

	int GetX() {
		return x;
	}
	int GetY() {
		return y;
	}
	int GetDx() {
		return dx;
	}
	int GetDy() {
		return dy;
	}

private:
	int x;
	int y;
	int dx;
	int dy;
};

