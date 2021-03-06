#include "Bullet.h"


Bullet::Bullet()
{

}

Bullet::Bullet(Texture * texture,int degree, float pos_x, float pos_y, float dir_x, float dir_y, float movement_speed)
{
	this->shape.setTexture(*texture);
	this->shape.setRotation(degree);
	this->shape.setPosition(pos_x, pos_y-60);
	this->shape.scale(1.5f, 1.5f);
	this->direction.x = dir_x;
	this->direction.y = dir_y;
	this->movementspeed = movement_speed;
}

Bullet::~Bullet()
{

}


const FloatRect Bullet::getBounds() const
{
	return this->shape.getGlobalBounds();
}


void Bullet::update()
{
	//Movement
	this->shape.move(this->movementspeed * this->direction);
}

void Bullet::render(RenderTarget* target)
{
	target->draw(this->shape);
}
