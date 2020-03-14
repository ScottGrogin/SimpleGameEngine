#pragma once
class Vector2D {
public:
	float x, y;
	Vector2D();
	Vector2D(float x, float y);
	Vector2D& operator=(const Vector2D& rhs);
	Vector2D& operator += (const Vector2D& rhs);
	Vector2D& operator -= (const Vector2D& rhs);
	bool operator == (const Vector2D& rhs);
	Vector2D operator+(const Vector2D& rhs);
	Vector2D operator-(const Vector2D& rhs);
	Vector2D operator*(float f);
	Vector2D operator/(float f);
	Vector2D& operator *= (float f);
	Vector2D& operator /= (float f);





};

