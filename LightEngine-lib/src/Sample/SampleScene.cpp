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
#include "Debug.h"

void SampleScene::OnInitialize()
{
    
    // Physic
    Ball = CreateEntity<PhysicalEntity>(30.f, sf::Color::Red);
    Ball->SetPosition(400.f, 100.f);

    // Static
    Wall = CreateEntity<StaticEntity>(100.f, sf::Color::Blue);
    Wall->SetPosition(350.f, 400.f);
}

void SampleScene::OnEvent(const sf::Event& event)
{
    // Jump sur espace
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
    {
        Ball->ApplyImpulse(-1000.f);
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
    Debug::DrawRectangle(Ball->GetPosition().x, Ball->GetPosition().y, 100, 100, sf::Color::Cyan);
}
