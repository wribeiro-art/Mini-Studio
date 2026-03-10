#include "SampleScene.h"
#include "PhysicalEntity.h"
#include "Debug.h"

void SampleScene::OnInitialize()
{
    // Physic
    Ball = CreateEntity<PhysicalEntity>(30.f, sf::Color::Red);
    Ball->SetPosition(400.f, 100.f);

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
}

void SampleScene::OnUpdate()
{
    Debug::DrawCircle(Ball->GetPosition().x, Ball->GetPosition().y, 10.f, sf::Color::Cyan);
}
