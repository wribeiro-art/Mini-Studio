#include "SampleScene.h"
#include "DummyEntity.h"
#include "PhysicalEntity.h"
#include "StaticEntity.h"
#include "Debug.h"

#include <iostream>

void SampleScene::OnInitialize()
{
	Ball = CreateEntity<PhysicalEntity>(30.f, sf::Color::Red);
	Ball->SetPosition(400.f, 100.f);


	for (int i = 0; i < 8; ++i)
	{
		if (sf::Joystick::isConnected(i))
		{
			std::cout << "Joystick " << i << " is connected" << std::endl;
		}
		else
		{
			std::cout << "Joystick " << i << " is not connected" << std::endl;
		}
	}
	
	
}

void SampleScene::OnEvent(const sf::Event& event)
{
	if (event.key.code == sf::Keyboard::Key::Space)
	{
		currentbutton++;
		if (currentbutton > 31)
		{
			currentbutton = 0;
		}
		std::cout << "Current button: " << currentbutton << std::endl;
	}

}


void SampleScene::OnUpdate()
{

		if (sf::Joystick::isButtonPressed(0, GetButtonPressed()))
{
			std::cout << "Joystick " << GetButtonPressed() << " is pressed" << std::endl;
		}

	//GetAxis
	{

		if (sf::Joystick::isButtonPressed(0, 4))
		{
			std::cout << "Joystick posX Value : " << ReturnJoystickValueX() << std::endl;
		}

		if (sf::Joystick::isButtonPressed(0, 5))
		{
			std::cout << "Joystick posY Value : " << ReturnJoystickValueY() << std::endl;
		}


	}

		if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 70)
		{
			Ball->SetPosition(Ball->GetPosition().x + 1, Ball->GetPosition().y);
		
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -70)
		{
			Ball->SetPosition(Ball->GetPosition().x - 1, Ball->GetPosition().y);
	
		}

		if (sf::Joystick::isButtonPressed(0, 0))//a changer mais en gros ça marche
		{
			if (Ball->GetPosition().y > 490)
			{
				Ball->ApplyImpulse(-100.f);
			}
		}
	
		if (Ball->GetPosition().y > 500)
		{
			Ball->SetGravitySpeed(-100.f);
		}

	Debug::DrawCircle(Ball->GetPosition().x, Ball->GetPosition().y, 10.f, sf::Color::Cyan);
}

int SampleScene::GetButtonPressed()
{
	for (int i = 0; i < sf::Joystick::ButtonCount; ++i)
	{
		if (sf::Joystick::isButtonPressed(0, i))
		{
			return i;
		}
	}
	return 31;
}

float SampleScene::ReturnJoystickValueX()
{
	int value = sf::Joystick::getAxisPosition(0, sf::Joystick::X);

	if (value <= 0 && value >= -10 || value >= 0 && value <= 10)
		return 0.f;

	return value / 100.f;
}

float SampleScene::ReturnJoystickValueY()
{
	int value = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

	if (value <= 0 && value >= -10 || value >= 0 && value <= 10)
		return 0.f;

	return value / 100.f;
}