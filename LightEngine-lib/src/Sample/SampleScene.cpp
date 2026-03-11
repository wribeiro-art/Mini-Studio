#include "SampleScene.h"
#include "PhysicalEntity.h"
#include "Debug.h"

#include <iostream>

void Ball::OnCollision(Entity* other)
{
    if (other->IsTag(2))
    {
        std::cout << "Collision avec le mur.\n";
        int hit = GetCollisionFace(other);
        std::cout << hit << std::endl;
    }
}


void SampleScene::OnInitialize()
{
    ball = CreateEntity<Ball>(30.f, sf::Color::Red);
    ball->SetPosition(400.f, 100.f);

    wall = CreateEntity<Entity>(100.f, sf::Color::Blue);
    wall->SetPosition(350.f, 400.f);
    wall->SetTag(2);
}

void SampleScene::OnEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
        ball->ApplyImpulse(-100.f, 0.0f);
}

void SampleScene::OnUpdate()
{
    Debug::DrawCircle(ball->GetPosition().x, ball->GetPosition().y, 10.f, sf::Color::Cyan);
}