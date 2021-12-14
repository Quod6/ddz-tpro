#include "Libs.h"

class Player
{
private:
	ConstParser *parser;
	Vector3f position;
	float speed;
	Texture texture;
	Sprite sprite;

	void initParser();
	void initVariables(float x, float y);
	void initShape();

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
