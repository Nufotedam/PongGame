#pragma once
class Menu
{
public:
	void MainMenu(int& a);
	void UserInput(int& a);
	void Score(int& _score_p1, int& _score_p2, int width_i, int width_f);
	void GameOver(int width_i, int width_f, int height_i, int height_f, int _player, int& a);
};

