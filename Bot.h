#include "Lib.h"

class Bot : public Player
{
private:
	Vector3f NextPoint;
	void BotInitVariables(float x, float y);
public:
	Bot(float x = 0.f, float y = 0.f);
	

}
