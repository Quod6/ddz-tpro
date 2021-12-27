#include "Libs.h"
#include "Laser.h"

class Player
{
private:
	bool isPlayer;
	int playerIndex;
	bool isCollided;
	ConstParser * parser;
	Laser * laser;
	Vector3f position;
	Vector3f newPosition;
	float speed;
	Texture texture;
	Sprite sprite;

	int typeOfTexture;
	int drawingFrame;
	float CURRENT_FRAME;
	Texture destruction;

	void initParser();
	void initLaser();
	void initNewNextPos();
	void initVariables(bool isPlayer, int playerIndex, float x, float y, float z);
	void initShape();

	bool wallCollision();
	void destroy(float dt);
	void setDirection();
	void move(float dt);
	void rotate(short direction);

public:
	Player(bool isPlayer, int indexPlayer, float x = 0.f, float y = 0.f, float z = 1.f);
	virtual ~Player();

	FloatRect getPlayerBounds();
	vector<FloatRect> getLaserBounds();

	void setCollided(bool value);
	bool getCollided();

	void updateInput(float dt);
	void update(float dt);
	void render(RenderTarget *target);
};
