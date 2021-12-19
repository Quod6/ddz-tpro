#include "Libs.h"

class Bot
{
private:
	ConstParser *parser;
	Vector3f position;
	Vector3f newPosition;
	float speed;
	Texture texture;
	Sprite sprite;

	void initParser();
	void initNewNextPos();
	void initVariables(float x, float y, float z);
	void initShape();

	void destroy(float dt);
	void setDirection();
	void move(float dt);
	void rotate(short direction);

public:
	Bot(float x = 0.f, float y = 0.f, float z = 0.f);
	virtual ~Bot();

	void updateInput(float dt);
	void update(float dt);
	void render(RenderTarget *target);
};
