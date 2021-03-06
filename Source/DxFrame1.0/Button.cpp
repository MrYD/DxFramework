#include"Button.h"

Button::Button() :Graphic()
{
	init();
}
Button::~Button()
{}
void Button::init()
{
	text = "";
	textColor = GetColor(0, 0, 0);
	color = GetColor(170, 170, 170);
	mouseOnColor = GetColor(200, 200, 200);
	textPosition = Vector2(0,0);
	TLight = 50;
	colorFlag = true;
	dragFlag = false;
	dragging = false;
	clickedTimes = 0;
}
void Button::upDate()
{
		//ドラッグ判定と処理
		if (pointOnFlag(BasicInput::mouse.left.lastDown))
		{
			dragging = true;
		}
		if (!BasicInput::mouse.left.input)
		{
			dragging = false;
		}
		if (dragging && dragFlag)
		{
			setMidPosition(getMidPosition() + BasicInput::mouse.speed);
		}

		//クリック判定
		if (BasicInput::mouse.left.up)
		{
			if (pointOnFlag(BasicInput::mouse.left.lastUp) && pointOnFlag(BasicInput::mouse.left.lastDown))
			{
				clickedTimes++;
			}
		}
}
Button* Button::setTLight(int light)
{
	TLight = light;
	TGraphHandle = graphHandle;
	GraphFilter(TGraphHandle, DX_GRAPH_FILTER_HSB, 0, 0, 0, TLight);
	return this;
}
Button* Button::setDragFlag(bool flag)
{
	dragFlag = flag;
	return this;
}

Button* Button::setTextPosition(Vector2 pos)
{
	textPosition = pos;
	return this;
}

Button* Button::setText(TCHAR* text, ...)
{
	this->text = text;
	return this;
}


Button* Button::setTextColor(int r, int g, int b)
{
	this->textColor = GetColor(r, g, b);
	return this;
}

Button* Button::setColor(int r, int g, int b)
{
	colorFlag = true;
	color = GetColor(r, g, b);
	mouseOnColor = GetColor(r + TLight, g + TLight, b + TLight);
	return this;
}
Button* Button::setColor(bool flag)
{
	colorFlag = flag;
	return this;
}

Button* Button::setGraph(Vector2 pix, TCHAR* graphName)
{
	colorFlag = false;
	bottom = top + pix;
	this->graphHandle = LoadGraph(graphName);
	this->TGraphHandle = LoadGraph(graphName);
	GraphFilter(TGraphHandle, DX_GRAPH_FILTER_HSB, 0, 0, 0, TLight);
	return this;
}


void Button::draw()
{
	if (pointOnFlag(BasicInput::mouse.position))
	{

		if (colorFlag == true)
		{
			DrawBox(top.x, top.y, bottom.x, bottom.y, mouseOnColor, TRUE);
		}
		DrawGraph(top.x, top.y, TGraphHandle, TRUE);
	}
	else
	{
		if (colorFlag == true)
		{
			DrawBox(top.x, top.y, bottom.x, bottom.y, color, TRUE);
		}
		Graphic::draw();
	}
	afterDraw();
}
void Button::afterDraw()
{
	DrawFormatString(top.x+textPosition.x, top.y+textPosition.y, textColor, text);
}
int Button::getClickedTimes()
{
	return clickedTimes;
}