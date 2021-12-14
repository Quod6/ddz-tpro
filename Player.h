#include "Libs.h"

class Player
{
private:
	Vector3i position;
	int speed;
	Texture texture;
	Sprite sprite;

	void initVariables();
	void initShape(float x, float y);

	void setDirection();
	void destroy();
public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	void move();
	void rotate(int direction);

	void update();
	void render(RenderTarget *target);
};
