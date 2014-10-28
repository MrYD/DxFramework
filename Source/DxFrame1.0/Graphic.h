#pragma once
#include "DxLib.h"
#include "tchar.h"
#include "Vector2.cpp"
#include "DrawableBase.h"
class Graphic :public DrawableBase
{
public:
	Graphic(Vector2 top, Vector2 graphPx, TCHAR* graphName);
	Graphic();
	~Graphic();
	void draw();
	void upDate();
	void afterDraw();
	Graphic* setMidPosition(Vector2 pos);
	Graphic* setTopPosition(Vector2 pos);
	Graphic* setGraphPx(Vector2 graphPx);
	Graphic* setGraph(TCHAR* graphName);
	Graphic* setGraph(Vector2 pix, TCHAR* graphName);
	bool pointOnFlag(Vector2 point);
	Vector2 top;
	Vector2 bottom;
	int graphHandle;
	Vector2 getMidPosition();
	
};

