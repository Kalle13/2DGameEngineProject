// GameLogic.h
#pragma once

#include <iostream>

namespace ge2d;

class GameLogic
{
public:

	GameLogic() {}
	~GameLogic() {}

	void GameInit();
	void ProcessInputs();
	void Update();
	void Render();

};