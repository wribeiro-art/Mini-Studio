//#include "SampleScene.h"
//
//#include "DummyEntity.h"
//
//#include "Debug.h"
//
//void SampleScene::OnInitialize()
//{
//	pEntity1 = CreateEntity<DummyEntity>(100, sf::Color::Red);
//	pEntity1->SetPosition(100, 100);
//	pEntity1->SetRigidBody(true);
//
//	pEntity2 = CreateEntity<DummyEntity>(50, sf::Color::Green);
//	pEntity2->SetPosition(500, 500);
//	pEntity2->SetRigidBody(true);
//
//	pEntitySelected = nullptr;
//}
//
//void SampleScene::OnEvent(const sf::Event& event)
//{
//	if (event.type != sf::Event::EventType::MouseButtonPressed)
//		return;
//
//	if (event.mouseButton.button == sf::Mouse::Button::Right)
//	{
//		TrySetSelectedEntity(pEntity1, event.mouseButton.x, event.mouseButton.y);
//		TrySetSelectedEntity(pEntity2, event.mouseButton.x, event.mouseButton.y);
//	}
//
//	if (event.mouseButton.button == sf::Mouse::Button::Left)
//	{
//		if (pEntitySelected != nullptr) 
//		{
//			pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);
//		}
//	}
//}
//
//void SampleScene::TrySetSelectedEntity(DummyEntity* pEntity, int x, int y)
//{
//	if (pEntity->IsInside(x, y) == false)
//		return;
//
//	pEntitySelected = pEntity;
//}
//
//void SampleScene::OnUpdate()
//{
//	if(pEntitySelected != nullptr)
//	{
//		sf::Vector2f position = pEntitySelected->GetPosition();
//		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
//	}
//}





//Cook
#include "SampleScene.h"
#include "PhysicalEntity.h"
#include "StaticEntity.h"
#include "Player.h"
#include "PlayerController.h"
#include "Controller.h"
#include "Debug.h"


#include <iostream>
void SampleScene::OnInitialize()
{
    // Physic
    Ball = CreateEntity<Player>(30.f, sf::Color::Red);
    Ball->SetPosition(400.f, 100.f);
    Ball->SetTag(1);

    // Static
    Wall = CreateEntity<StaticEntity>(100.f, sf::Color::Blue);
    Wall->SetPosition(350.f, 400.f);
    Wall->SetTag(2);

    //Manette
    Controller1 = new Controller(0);
}

void SampleScene::OnEvent(const sf::Event& event)
{

	//Activer/Desactiver le debug avec F1
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F1)
    {
		mDebug = !mDebug;
    }

    //Clavier souris
    
    // Jump sur espace
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
    {
        Ball->ApplyImpulse(-100.f);
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
    {
        Ball->MoveX(GetDeltaTime(), 1.0f);
    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q)
    {
        Ball->MoveX(GetDeltaTime(), -1.0f);
    }

    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::D)
    {
        Ball->SetSpeed(0.f);
    }

    if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Q)
    {
        Ball->SetSpeed(0.f);
    }

    // Mettre la gravité
    if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
    {
        Ball->EnableGravity();
    }

    // Enlever la gravité
    if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Right)
    {
        Ball->DisableGravity();
    }

    // Toggle mur avec E
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::E)
    {
        if (Wall->GetShape()->getFillColor() == sf::Color::Blue)
            Wall->GetShape()->setFillColor(sf::Color::Green);
        else
            Wall->GetShape()->setFillColor(sf::Color::Blue);

    }

    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F2) //Toggle mode Psychique
    {
        if (Ball->GetShape()->getFillColor() == sf::Color::Red)
        {
            Ball->GetShape()->setFillColor(sf::Color::Magenta);
			mPsychicMode = true;
        }
        else
        {
            Ball->GetShape()->setFillColor(sf::Color::Red);
			mPsychicMode = false;
        }

    }
    //Manette 

    //Debug
    
    if (mDebug)
    {

        if (sf::Joystick::isButtonPressed(0, 6))
        {
            std::cout << "Joystick posX Value : " << Controller1->ReturnJoystickValueX() << std::endl;
        }

        if (sf::Joystick::isButtonPressed(0, 7))
        {
            std::cout << "Joystick posY Value : " << Controller1->ReturnJoystickValueY() << std::endl;
        }
    }

    if (sf::Joystick::isButtonPressed(0, 0) && Ball->GetPosition().y >= 500)//jump
    {
        Ball->ResetVelocity();
        Ball->ApplyImpulse(-500.f);
    }
}

void SampleScene::OnUpdate()
{
	if (sf::Joystick::isButtonPressed(0, 5))//Dash
	{
		if (mPsychicMode == false)
		{
			if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -10)
				Ball->Dash(-500.f, 0.f);
			else
				Ball->Dash(500.f, 0.f);
		}
        else if (mPsychicMode == true)
        {
			float stickX = Controller1->ReturnJoystickValueX();
			float stickY = Controller1->ReturnJoystickValueY();
			Ball->Dash(stickX * 500.f, stickY * 500.f);
        }
    }

    if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 10)
		Ball->MoveX(GetDeltaTime(), 1.0f);

    else if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -10)
		Ball->MoveX(GetDeltaTime(), -1.0f);

    if (Ball->GetPosition().y >= 500.f)//Mimic de sol à remplacer une fois les colliders fait
    {
        Ball->ApplyImpulse(-70.f);
    }

    Debug::DrawCircle(Ball->GetPosition().x, Ball->GetPosition().y, 10.f, sf::Color::Cyan);
}
