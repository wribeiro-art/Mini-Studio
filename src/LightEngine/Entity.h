#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "Collider.h"

namespace sf 
{
	class Shape;
    class Color;
}

class Scene;

class Entity
{
    struct Target 
    {
		sf::Vector2i position;
        float distance;
		bool isSet;
    };

    struct RectCollider
    {
        float xMin, xMax;
        float yMin, yMax;
    };

protected:
    sf::CircleShape mShape;
    sf::RectangleShape mShapeRect;
    sf::Vector2f mDirection;
	Target mTarget;
    float mSpeed = 0.f;
    bool mToDestroy = false;
    int mTag = -1;
	bool mRigidBody = true;
    Collider mCollider;

public:
	bool GoToDirection(int x, int y, float speed = -1.f);
    bool GoToPosition(int x, int y, float speed = -1.f);
    void SetPosition(float x, float y, float ratioX = 0.5f, float ratioY = 0.5f);
	void SetDirection(float x, float y, float speed = -1.f);
	void SetSpeed(float speed) { mSpeed = speed; }
	void SetTag(int tag) { mTag = tag; }
	float GetRadius() const { return mShape.getRadius(); }
	void SetRigidBody(bool isRigitBody) { mRigidBody = isRigitBody; } 
	bool IsRigidBody() const { return mRigidBody; } 

    sf::Vector2f GetPosition(float ratioX = 0.5f, float ratioY = 0.5f) const;
	sf::Shape* GetShape() { return &mShape; }
	Collider* GetCollider() { return &mCollider; }

	bool IsTag(int tag) const { return mTag == tag; }
    bool IsColliding(Entity* other) const;
    bool IsColliding(const RectCollider& c1, const RectCollider& c2) const;
	bool IsInside(float x, float y) const;

    void Destroy();
	bool ToDestroy() const { return mToDestroy; }
	
	template<typename T>
	T* GetScene() const;

    Scene* GetScene() const;
	float GetDeltaTime() const;

    template<typename T>
    T* CreateEntity(float radius, const sf::Color& color);

    int GetCollisionFace(Entity* other) const;

protected:
    Entity() = default;
    ~Entity() = default;

    virtual void OnUpdate() {};
    virtual void OnCollision(Entity* collidedWith) {};
	virtual void OnInitialize() {};
	virtual void OnDestroy() {};
    //virtual void Update(); Move dans protected
    virtual void Update();
    virtual void FixedUpdate(float Fix_DT) {};
	
private:
	void InitializeCircle(float radius, const sf::Color& color);
    void InitializeRect(float xMin, float xMax, float yMin, float yMax, const sf::Color& color);

	void Repulse(Entity* other);

    void UpdateCollider();
	
private:
	void Initialize(float radius, const sf::Color& color);
	virtual void Repulse(Entity* other);

    friend class GameManager;
    friend Scene;
};

#include "Entity.inl"