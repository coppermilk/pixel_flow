
#include "Pixel.h"

Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b) {
    this->r = r;
    this->g = g;
    this->b = b;
    // BOOST_LOG_TRIVIAL(info) << "Pixel {" + std::to_string(r) + ","+ std::to_string(g) + "," + std::to_string(b) + "}created.";
}


Pixel::Pixel(uint8_t rgb) {
    r = b = g = rgb;
    //BOOST_LOG_TRIVIAL(info) << "Pixel {" + std::to_string(r) + ","+ std::to_string(b) + "," + std::to_string(b) + "} created.";
}

void Pixel::reset() {
    r = b = g = 255;
}

void Pixel::set_r(uint8_t color) {
    this->r = color;
}

void Pixel::set_b(uint8_t color) {
    this->b = color;
}

void Pixel::set_g(uint8_t color) {
    this->g = color;
}

void Pixel::set_rgb(uint8_t r, uint8_t g, uint8_t b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void Pixel::set_rbg(const Pixel &other) {
    this->r = other.r;
    this->b = other.b;
    this->g = other.g;
}

uint8_t Pixel::get_g() const {
    return this->g;
}

uint8_t Pixel::get_b() const {
    return this->b;
}

uint8_t Pixel::get_r() const {
    return this->r;
}

void Pixel::set_all(uint8_t rbg) {
    r = b = g = rbg;
}

Pixel::Pixel() {
    r = b = g = 0;
}
