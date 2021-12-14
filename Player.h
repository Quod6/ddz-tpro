#include "Libs.h"

class Player
{
private:
	Vector3i position;
	float speed;
	Texture texture;
	Sprite sprite;

	void initVariables();
	void initShape(float x, float y);

	void destroy();
	void setDirection();
	void move();
	void rotate(int direction);

public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	void updateInput();
	void update();
	void render(RenderTarget *target);
};
