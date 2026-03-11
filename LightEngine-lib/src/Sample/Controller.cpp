
#include "Controller.h"
#include <iostream>
Controller::Controller(int ID)
{
	IsConnected(ID);
}

bool Controller::IsConnected(int ID)
{
	if(sf::Joystick::isConnected(ID))
	{
		std::cout << "Controller " << ID + 1 << " is connected." << std::endl;
		return true;
	}
	else
	{
		std::cout << "Controller " << ID + 1<< " is not connected." << std::endl;
		return false;
	}
}

int Controller::ReturnPressedButton(int ID)
{
	if (!IsConnected(ID))
	{
		return 31;
	}
	for (int i = 0; i < sf::Joystick::ButtonCount; i++)
	{
		if (sf::Joystick::isButtonPressed(ID, i))
		{
			std::cout << "Button " << i << " is pressed." << std::endl;
			return i;
		}
		else return 31;
		
	}
}

float Controller::ReturnJoystickValueX()
{
	int value = sf::Joystick::getAxisPosition(0, sf::Joystick::X);

	if (value <= 0 && value >= -10 || value >= 0 && value <= 10)
		return 0.f;

	return value / 100.f;
}

float Controller::ReturnJoystickValueY()
{
	int value = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

	if (value <= 0 && value >= -10 || value >= 0 && value <= 10)
		return 0.f;

	return value / 100.f;
}