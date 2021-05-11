#include "stdafx.h"
#include "BasicObject.h"

const bool BaseObject::GetHit()
{
    return this->hit;
}

void BaseObject::SetHit()
{
    this->hit = true;
}

const double BaseObject::GetX()
{
    return this->x;
}

const double BaseObject::GetY()
{
    return this->y;
}

const double BaseObject::GetWidth()
{
    return this->width;
}

const double BaseObject::GetHeight()
{
    return this->height;
}

const int BaseObject::GetType()
{
    return this->type;
}
