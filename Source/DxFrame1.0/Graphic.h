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
	void setMidPosition(Vector2 pos);
	void setTopPosition(Vector2 pos);
	void setGraphPx(Vector2 graphPx);
	void setGraph(TCHAR* graphName);
	void setGraph(Vector2 pix,TCHAR* graphName);
	bool pointOnFlag(Vector2 point);
	Vector2 top;
	Vector2 bottom;
	int graphHandle;
	Vector2 getMidPosition();
	
};

