#pragma once
#include "Graphic.h"
#include"BasicInput.h"
#include <iostream>
using namespace std;
class Button :
	public Graphic
{
public:
	Button();
	~Button();
	void init();
	void upDate();
	void setTLight(int light);
	void setText(TCHAR* str,...);
	void setTextPosition(Vector2 pos);
	void setTextColor(int r, int g, int b);
	void setColor(int r, int g, int b);
	void setColor(bool flag);
	void setGraph(Vector2 pix,TCHAR* graphName);
	void setDragFlag(bool flag);
	void draw();
	void afterDraw();
	int getClickedTimes();
private:
	TCHAR* text;
	DWORD textColor;
	DWORD color;
	DWORD mouseOnColor;
	Vector2 textPosition;
	int TLight;
	int TGraphHandle;
	bool colorFlag;
	int clickedTimes;
	bool dragFlag;
	bool dragging;
};

