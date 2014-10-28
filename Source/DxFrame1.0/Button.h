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
	Button* setTLight(int light);
	Button* setText(TCHAR* str, ...);
	Button* setTextPosition(Vector2 pos);
	Button* setTextColor(int r, int g, int b);
	Button* setColor(int r, int g, int b);
	Button* setColor(bool flag);
	Button* setGraph(Vector2 pix, TCHAR* graphName);
	Button* setDragFlag(bool flag);
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

