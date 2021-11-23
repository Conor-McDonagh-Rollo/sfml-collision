#include <./include/GameObject.h>

GameObject::GameObject(){};

GameObject::~GameObject(){};

void GameObject::setX(float x){this->x = x;}
void GameObject::setY(float y){this->y = y;}
void GameObject::setR(float r){this->r = r;}

float GameObject::getX(){return this->x + this->r;}
float GameObject::getY(){return this->y + this->r;}
float GameObject::getR(){return this->r;}

bool GameObject::collision(GameObject* gameObject){
    bool collision = false;

    float distance = ((this->getX() - gameObject->getX()) * (this->getX() - gameObject->getX())) +
    ((this->getY() - gameObject->getY()) * (this->getY() - gameObject->getY()));

    distance = sqrt(distance);

    std::cout << "Distance : " << distance << std::endl;

    if(this->getR() + gameObject->getR() >= distance){
        collision = true;
    }

    return collision;
}