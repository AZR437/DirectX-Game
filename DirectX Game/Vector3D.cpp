#include "Vector3D.h"

Vector3D::Vector3D()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3D::Vector3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}



Vector3D::Vector3D(const Vector3D& vector)
{
	this->x = vector.x;
	this->y = vector.y;
	this->z = vector.z;
}

Vector3D::~Vector3D()
{
}

Vector3D Vector3D::Lerp(const Vector3D& start, const Vector3D& end, float delta)
{
	Vector3D result;
	result.x = start.x * (1.0f - delta) + end.x*(delta);
	result.y = start.y * (1.0f - delta) + end.y*(delta);
	result.z = start.z * (1.0f - delta) + end.z*(delta);
	return result;
}

Vector3D Vector3D::operator*(float num)
{
	return Vector3D(this->x*num, this->y * num, this->z * num );
}

Vector3D Vector3D::operator+(Vector3D vec)
{
	return Vector3D(this->x + vec.x, this->y + vec.y, this->z + vec.z);
}

Vector3D operator-(const Vector3D& right) {
    return Vector3D(-right.x, -right.y, -right.z);
}

Vector3D operator+(const Vector3D& left, const Vector3D& right) {
    return Vector3D(left.x + right.x, left.y + right.y, left.z + right.z);
}

Vector3D& operator+=(Vector3D& left, const Vector3D& right) {
    left = left + right;
    return left;
}

Vector3D operator-(const Vector3D& left, const Vector3D& right) {
    return Vector3D(left.x - right.x, left.y - right.y, left.z - right.z);
}

Vector3D& operator-=(Vector3D& left, const Vector3D& right) {
    left = left - right;
    return left;
}

Vector3D operator*(const Vector3D& left, const Vector3D& right) {
    return Vector3D(left.x * right.x, left.y * right.y, left.z * right.z);
}

Vector3D& operator*=(Vector3D& left, const Vector3D& right) {
    left = left * right;
    return left;
}

Vector3D operator*(const Vector3D& left, const float& right) {
    return Vector3D(left.x * right, left.y * right, left.z * right);
}

Vector3D operator*(const float& left, const Vector3D& right) {
    return Vector3D(left * right.x, left * right.y, left * right.z);
}

Vector3D& operator*=(Vector3D& left, const float& right) {
    left = left * right;
    return left;
}

Vector3D operator/(const Vector3D& left, const Vector3D& right) {
    return Vector3D(left.x * right.x, left.y * right.y, left.z * right.z);
}

Vector3D& operator/=(Vector3D& left, const Vector3D& right) {
    left = left / right;
    return left;
}

Vector3D operator/(const Vector3D& left, const float& right) {
    return Vector3D(left.x / right, left.y / right, left.z / right);
}

Vector3D operator/(const float& left, const Vector3D& right) {
    return Vector3D(left / right.x, left / right.y, left / right.z);
}

Vector3D& operator/=(Vector3D& left, const float& right) {
    left = left / right;
    return left;
}

bool operator==(const Vector3D& left, const Vector3D& right) {
    return (left.x == right.x && left.y == right.y && left.z == right.z);
}

bool operator!=(const Vector3D& left, const Vector3D& right) {
    return (left.x != right.x || left.y != right.y || left.z != right.z);
}

bool operator<(const Vector3D& left, const Vector3D& right)
{
    return (left.x < right.x || left.y < right.y || left.z < right.z);
}

