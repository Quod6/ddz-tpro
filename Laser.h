#include "Libs.h"

class Laser
{
private:
	ConstParser *parser;
	vector<Vector3f> positions;
	vector<Sprite> sprites;
	Texture texture;
	Sprite sprite;

	void initParser();
	void initVariables(Sprite * sprite, bool isPlayer);

public:
	Laser(Sprite * sprite, bool isPlayer);
	virtual ~Laser();

	void update(Sprite * sprite);
	void render(RenderTarget *target);
};
