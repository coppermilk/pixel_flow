
#include "Pixel.h"


Pixel::Pixel(uint8_t r, uint8_t b, uint8_t g)
{
	this->r = r;
	this->b = b;
	this->g = g;
}

Pixel::Pixel(uint8_t rbg)
{
	r = b = g = rbg;
}

void Pixel::reset()
{
	r = b = g = 0;
}

uint8_t Pixel::get_g() const
{
	return this->g;
}

uint8_t Pixel::get_b() const
{
	return this->b;
}

uint8_t Pixel::get_r() const
{
	return this->r;
}

void Pixel::set_all(uint8_t rbg)
{
	r = b = g = rbg;
}

Pixel::Pixel()
{
	r = b = g = 0;
}
