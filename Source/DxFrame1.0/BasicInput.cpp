#include "BasicInput.h"


BasicInput::BasicInput()
{
	update();
}


BasicInput::~BasicInput()
{
}

void BasicInput::update()
{
	int x, y;
	GetMousePoint(&x, &y);
	mouse.speed = Vector2(x, y) - mouse.position;
	mouse.position = Vector2(x, y);
	mouse.wheelRotVol = GetMouseWheelRotVol();
	int input = GetMouseInput();
	mouse.buttonDawn = false;
	mouse.buttonUp = false;
	mouse.left.up = false;
	mouse.right.up = false;
	mouse.middle.up = false;
	mouse.left.dawn = false;
	mouse.right.dawn = false;
	mouse.middle.dawn = false;
	if (GetMouseInputLog(&input, &x, &y, TRUE) == -1)
		//クリックが検知されなかった場合
	{
		if ((input & MOUSE_INPUT_LEFT) != 0);
		else if (mouse.left.input)
		//左クリックされていた
		{
			mouse.left.up = true;
			mouse.left.input = false;
			mouse.buttonInput = false;
			mouse.left.lastUp = Vector2(x, y);
		}
		if ((input & MOUSE_INPUT_RIGHT) != 0);
		else if (mouse.right.input)
		//右クリックされていた
		{
			mouse.right.up = true;
			mouse.right.input = false;
			mouse.buttonInput = false;
			mouse.right.lastUp = Vector2(x, y);
		}
		if ((input & MOUSE_INPUT_MIDDLE) != 0);
		else if (mouse.middle.input)
		//中クリックされていた
		{
			mouse.middle.up = true;
			mouse.middle.input = false;
			mouse.buttonInput = false;
			mouse.middle.lastUp = Vector2(x, y);
		}
	}
	else
		//クリックされた
	{
		mouse.buttonInput = true;
		if ((input & MOUSE_INPUT_LEFT) != 0)
		//左クリックされた
		{
			mouse.left.dawn = true;
			mouse.left.lastDown = Vector2(x, y);
			mouse.left.input = true;
			mouse.right.input = false;
			mouse.middle.input = false;
		}
		if ((input & MOUSE_INPUT_RIGHT) != 0)
		//右クリックされた
		{
			mouse.right.dawn = true;
			mouse.right.lastDown = Vector2(x, y);
			mouse.left.input = false;
			mouse.right.input = true;
			mouse.middle.input = false;
		}
		if ((input & MOUSE_INPUT_MIDDLE) != 0)
		//中クリックされた
		{
			mouse.middle.dawn = true;
			mouse.middle.lastDown = Vector2(x, y);
			mouse.left.input = false;
			mouse.right.input = false;
			mouse.middle.input = true;
		}
	}
	if (mouse.left.up || mouse.right.up || mouse.middle.up)
	{
		mouse.buttonUp = true;
	}
	if (mouse.left.dawn || mouse.right.dawn || mouse.middle.dawn)
	{
		mouse.buttonDawn = true;
	}
	GetHitKeyStateAll(Buf);
}
Mouse BasicInput::mouse;
char BasicInput::Buf[256];
