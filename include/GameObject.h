#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void initialize() = 0;
	virtual void update() = 0;

	void setX(float);
	void setY(float);
	void setR(float);
	
	float getX();
	float getY();
	float getR();

	bool collision(GameObject* gameObject);

private:
	float x;
	float y;
	float r;
};
#endif