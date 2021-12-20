#include "Libs.h"
// #include "Laser.h"

class Player
{
protected:
	bool isPlayer;
	ConstParser * parser;
	// Laser * laser;
	Vector3f position;
	Vector3f newPosition;
	float speed;
	Texture texture;
	Sprite sprite;

	void initParser();
	void initNewNextPos();
	void initVariables(bool isPlayer, float x, float y, float z);
	// void initLaser();
	void initShape();

	void destroy(float dt);
	void setDirection();
	void move(float dt);
	void rotate(short direction);
	void makeLaser();

public:
	Player(bool isPlayer, float x = 0.f, float y = 0.f, float z = 1.f);
	virtual ~Player();

	void updateInput(float dt);
	void update(float dt);
	void render(RenderTarget *target);
};
