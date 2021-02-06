#pragma once
class Paddle
{
public:
	Paddle(int _x, int _y);
	void Print() const;
	void Clean() const;
	void UpdateY(int _movement);
	void IAMovement(int _ballx, int _bally, int _balldx, int height_i, int height_f, int limit_reaction);

	int GetY() {
		return y;
	}
	int GetX() {
		return x;
	}
	void SetY(int _y) {
		y = _y;
	}
	void SetX(int _x) {
		x = _x;
	}

private:
	int x;
	int y;
};
