#include "Vector2D.h"

Vector2D::Vector2D():x(0),y(0) {
}

Vector2D::Vector2D(float x, float y) :x(x), y(y) {}

Vector2D& Vector2D::operator=(const Vector2D& rhs) {
	x = rhs.x;
	y = rhs.y;
	return *this;
}
Vector2D Vector2D::operator+(const Vector2D& rhs) {
	return Vector2D(x+rhs.x, y+rhs.y);
}

Vector2D Vector2D::operator-(const Vector2D& rhs) {
	return Vector2D(x-rhs.x, y-rhs.y);
}

Vector2D Vector2D::operator*(float f) {
	return Vector2D(x*f,y*f);
}

Vector2D Vector2D::operator/(float f) {
	return Vector2D(x/f,y/f);
}

Vector2D& Vector2D::operator*=(float f) {
	x *= f;
	y *= f;
	return *this;
}

Vector2D& Vector2D::operator/=(float f) {
	x /= f;
	y /= f;
	return *this;
}

Vector2D& Vector2D::operator+=(const Vector2D& rhs) {
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& rhs) {
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

bool Vector2D::operator==(const Vector2D& rhs) {
	return (x==rhs.x && y ==rhs.y);
}
