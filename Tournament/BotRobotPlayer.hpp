// BotRobot, ATaco
// PPCG: http://codegolf.stackexchange.com/a/104910/11933

// BotRobot
// ONE HUNDRED THOUSAND GENERATIONS TO MAKE THE ULTIMATE LIFEFORM!

#ifndef __BOT_ROBOT_PLAYER_HPP__
#define __BOT_ROBOT_PLAYER_HPP__

#include "Player.hpp"

class BotRobotPlayer final : public Player
{
public:
	BotRobotPlayer(size_t opponent = -1) : Player(opponent) {}

public:
	virtual Action fight()
	{
		std::string action = "";
		action += std::to_string(getAmmo());
		action += ":";
		action += std::to_string(getAmmoOpponent());

		int toDo = 3;

		for (int i = 0; i < int(sizeof(options)/sizeof(*options)); i++) {
			if (options[i].compare(action) == 0) {
				toDo = outputs[i];
				break;
			}
		}

		switch (toDo) {
		case 0:
			return load();
		case 1:
			return bullet();
		case 2:
			return plasma();
		case 3:
			return metal();
		default:
			return thermal();
		}
	}

private:
	std::string options[29] =
	{
		"0:9",
		"1:12",
		"1:10",
		"0:10",
		"1:11",
		"0:11",
		"0:6",
		"2:2",
		"0:2",
		"2:6",
		"3:6",
		"0:7",
		"1:3",
		"2:3",
		"0:3",
		"2:0",
		"1:0",
		"0:4",
		"1:4",
		"2:4",
		"0:0",
		"3:0",
		"1:1",
		"2:1",
		"2:9",
		"0:5",
		"0:8",
		"3:1",
		"0:1"
	};

	int outputs[29] =
	{
		0,
		1,
		1,
		4,
		1,
		0,
		0,
		4,
		4,
		0,
		0,
		3,
		0,
		1,
		3,
		0,
		1,
		4,
		0,
		1,
		0,
		1,
		0,
		3,
		4,
		3,
		0,
		1,
		0
	};
};

#endif // !__BOT_ROBOT_PLAYER_HPP__
