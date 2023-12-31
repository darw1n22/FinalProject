#include "pch.h"
#include "Ball.h"

Ball::Ball(int weight, string sport, long productCode, string brand, string type, string color, int stock, int shelf, float price)
	: Product(productCode, brand, type, color, stock, shelf, price)
{
	this->weight = weight;
	this->sport = sport;
}
int Ball::getWeight()
{
	return weight;
}
string Ball::getSport()
{
	return sport;
}

void Ball::showInfo()
{
	Product::showInfo();
	Console::showBall(weight, sport);
}

bool Ball::operator<=(Ball& b)
{
	return this->getProductCode() <= b.getProductCode();
}

bool Ball::operator>=(Ball& b)
{
	return this->getProductCode() >= b.getProductCode();
}