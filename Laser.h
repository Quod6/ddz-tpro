#include "Libs.h"

class Laser
{
private:
	ConstParser *parser;
	vector<Vector3f> positions;
	Vector2f oldPos;
	float oldAngle;
	int playerIndex;
	vector<Sprite> lines;
	Texture textureV;
	Texture textureH;
	Sprite sprite;

	void initParser();
	void initVariables(Sprite * sprite, bool isPlayer, int playerIndex);

public:
	Laser(Sprite * sprite, bool isPlayer, int playerIndex);
	virtual ~Laser();

	vector<FloatRect> getBounds();

	void update(Sprite * sprite);
	void render(RenderTarget *target);
};
