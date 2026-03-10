#include "SampleScene.h"
#include "PhysicalEntity.h"
#include "Debug.h"
#include <iostream>

void SampleScene::OnInitialize()
{
    // Physic
    Ball = CreateEntity<PhysicalEntity>(30.f, sf::Color::Red);
    Ball->SetPosition(600.f, 450.f);

    // Static
    Wall = CreateEntity<Entity>(100.f, sf::Color::Blue);
    Wall->SetPosition(350.f, 400.f);
}

void SampleScene::OnEvent(const sf::Event& event)
{
    // Jump sur espace
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
    {
        Ball->ApplyImpulse(-0.f, 500.f);
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

    if (sf::Joystick::isButtonPressed(0, 6))
    {
        std::cout << "Joystick posX Value : " << ReturnJoystickValueX() << std::endl;
    }

    if (sf::Joystick::isButtonPressed(0, 7))
    {
        std::cout << "Joystick posY Value : " << ReturnJoystickValueY() << std::endl;
    }

   
    
    if (sf::Joystick::isButtonPressed(0, 0) && Ball->GetPosition().y >= 500)//a changer mais en gros ça marche
    {
        Ball->ResetVelocity();
        Ball->ApplyImpulse(-500.f);
    }

}

void SampleScene::OnUpdate()
{
    if (sf::Joystick::isButtonPressed(0, 5))
    {
        if(sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -10)
         Ball->ApplyImpulse(-0.f, -100.f);
        else
            Ball->ApplyImpulse(-0.f, 100.f);

    }
    if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 10)
        Ball->SetPosition(Ball->GetPosition().x + 1, Ball->GetPosition().y);

    else if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -10)
        Ball->SetPosition(Ball->GetPosition().x - 1, Ball->GetPosition().y);

    if (Ball->GetPosition().y >= 500.f)
    {
        Ball->ApplyImpulse(-80.f);
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