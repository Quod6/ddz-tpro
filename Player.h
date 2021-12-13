#include "Libs.h"

class Player
{
private:
	Vector3i position;
	int speed;
	Texture texture;
	Sprite sprite;

	void initVariables();
	void setDirection();
	void destroy();
public:
	Player();
	virtual ~Player();

	void move();
	void rotate(int direction);
};
