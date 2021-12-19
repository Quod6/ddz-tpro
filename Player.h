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

	void destroy(float dt);
	void setDirection();
	void move(float dt);
	void rotate(short direction);
	void makeLaser();

public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	void updateInput(float dt);
	void update(float dt);
	void render(RenderTarget *target);
};
