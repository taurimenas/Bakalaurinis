#include "Button.h"

Button::Button(const byte buttonPin)
	:
	buttonPin(buttonPin)
{
}

void Button::Init()
{
	pinMode(buttonPin, INPUT);
	buttonState = 0;
	lastButtonState = 0;
	lastButtonStateShort = 0;
	longState = 0;
	page = 0;
	pages = 1;
}

bool Button::ShortClickListener()
{
	bool state = false;
	const int buttonStateShort = digitalRead(buttonPin);
	if (buttonStateShort != lastButtonStateShort)
	{
		state = buttonStateShort == LOW;
	}
	lastButtonStateShort = buttonStateShort;
	if (state == 1 && longState == 1)
	{
		longState = 0;
		return 0;
	}
	return state;
}


bool Button::LongClickListener()
{
	buttonState = digitalRead(buttonPin);
	if (buttonState != lastButtonState)
	{
		isStartClicked = true;
		isClickEven = !isClickEven;
		buttonClickTime = millis();
		lastButtonState = buttonState;
	}
	else if (isStartClicked && isClickEven)
	{
		if (millis() - buttonClickTime >= 2000)
		{
			isStartClicked = false;
			longState = 1;
			return true;
		}
	}
	return false;
}

int Button::PageTracker(int index)
{
	if (index != 0)
	{
		if (page != 2)
		{
			if (Button::ShortClickListener())
			{
				page = 1;
			}
			if (Button::LongClickListener())
			{
				page = 0;
			}
			return page;
		}
	}
	if (index == 0)
	{
		if (Button::ShortClickListener())
		{
			page = 2;
		}
		if (Button::LongClickListener())
		{
			page = 0;
		}
		return page;
	}
	if (Button::LongClickListener())
	{
		page = 0;
	}
	return page;
}
