#pragma once
#include <Arduino.h>

class Button
{
public:
	Button(const byte btnPin);
	void Init();
	bool ShortClickListener();
	bool LongClickListener();
	int PageTracker(int index);
private:
	int page;
	int pages;
	bool longState;
	const byte buttonPin;
	int buttonState;
	int lastButtonState;
	int lastButtonStateShort;
	unsigned long buttonClickTime;
	int index;

	bool isStartClicked = false;
	bool isClickEven = false;
};
