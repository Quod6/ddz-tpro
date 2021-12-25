#include "Libs.h"

class Laser
{
private:
	ConstParser *parser;
	vector<Vector3f> positions;
	Vector2f oldPos;
	float oldAngle;
	vector<Sprite> lines;
	vector<Sprite> sprites;
	Texture textureV;
	Texture textureH;
	Sprite sprite;

	void initParser();
	void initVariables(Sprite * sprite, bool isPlayer);

public:
	Laser(Sprite * sprite, bool isPlayer);
	virtual ~Laser();

	void update(Sprite * sprite);
	void render(RenderTarget *target);
};
