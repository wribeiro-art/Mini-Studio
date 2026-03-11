#include "SampleScene.h"
#include "PhysicalEntity.h"
#include "StaticEntity.h"
#include "Player.h"
#include "Controller.h"
#include "Debug.h"
#include <iostream>

void SampleScene::OnInitialize()
{
    // Physic
    Ball = CreateEntity<Player>(30.f, sf::Color::Red);
    Ball->SetPosition(600.f, 450.f);
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