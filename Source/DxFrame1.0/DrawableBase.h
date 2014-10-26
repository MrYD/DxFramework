#pragma once
class DrawableBase
{
public:
	DrawableBase();
	void setLayer(int layer);
	virtual ~DrawableBase() = 0;
	virtual void draw() = 0;
	virtual void upDate() = 0;
	int layer;
	bool isVisible = true;
};

