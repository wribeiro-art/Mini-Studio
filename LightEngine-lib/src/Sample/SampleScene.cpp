#include "SampleScene.h"

#include "DummyEntity.h"

#include "Debug.h"

#include <iostream>

void SampleScene::OnInitialize()
{
	pEntity1 = CreateEntity<DummyEntity>(100, sf::Color::Red);
	pEntity1->SetPosition(100, 100);
	pEntity1->SetRigidBody(true);

	pEntity2 = CreateEntity<DummyEntity>(50, sf::Color::Green);
	pEntity2->SetPosition(500, 500);
	pEntity2->SetRigidBody(true);

	pEntitySelected = nullptr;

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


	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		TrySetSelectedEntity(pEntity1, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pEntity2, event.mouseButton.x, event.mouseButton.y);
	}
}

void SampleScene::TrySetSelectedEntity(DummyEntity* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
		return;

	pEntitySelected = pEntity;
}

void SampleScene::OnUpdate()
{

		if (sf::Joystick::isButtonPressed(0, GetButtonPressed()))
{
			std::cout << "Joystick " << GetButtonPressed() << " is pressed" << std::endl;
		}

	{
		if (!pEntitySelected)
			return;



		if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 70)
		{
			pEntitySelected->SetPosition(pEntitySelected->GetPosition().x + 1, pEntitySelected->GetPosition().y);
		
		}
		else if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -70)
		{
			pEntitySelected->SetPosition(pEntitySelected->GetPosition().x - 1, pEntitySelected->GetPosition().y);
	
		}

		
		if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) < -50)
		{
			pEntitySelected->
		}
		
		if (sf::Joystick::isButtonPressed(0, 0))
		{
			std::cout << "Big saut trop bien animer et tt ouais" << std::endl;
		}

		else if (sf::Joystick::isButtonPressed(0, 1))
		{
			pEntitySelected->SetPosition(pEntitySelected->GetPosition().x, pEntitySelected->GetPosition().y + 1);
		}

	}
	

	if(pEntitySelected != nullptr)
	{
		sf::Vector2f position = pEntitySelected->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}
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