#ifndef PIXEL_FLOW_SRC_PIXEL_H
#define PIXEL_FLOW_SRC_PIXEL_H

#include <boost/log/trivial.hpp>
#include <cstdint>

/**
* @brief A class that represents a pixel.
*/
class Pixel {

 public:

  /**
   * @brief A default constructor witch set up the pixel object to the default value.
   */

  Pixel();

  /**
   * @brief A constructor. It is called when a new Pixel object is created.
   * @param r Red color value, range [0, 256).
   * @param b Blue color value, range [0, 256).
   * @param g Green color value, range [0, 256).
   */
  Pixel(uint8_t r, uint8_t b, uint8_t g);

  /**
   * @brief A constructor that takes one argument rgb for setting all pixel object colors in rgb value.
   * @param rgb RBG colors value, range [0, 256).
   */
  explicit Pixel(uint8_t rbg);

  /**
   * @brief A function that returns the red color value of the pixel object.
   * @return Red color value, range [0, 256).
   */
  [[nodiscard]] uint8_t get_r() const;

  /**
   * @brief A function that returns the blue color value of the pixel object.
   * @return Red color value, range [0, 256).
   */
  [[nodiscard]] uint8_t get_b() const;

  /**
   * @brief A function that returns the green color value of the pixel object.
   * @return Red color value, range [0, 256).
   */
  [[nodiscard]] uint8_t get_g() const;

  /**
   * @brief It sets all the colors of the pixel object to the same value.
   * @param rbg RBG color value, range [0, 256).
   */
  void set_all(uint8_t rbg);

  /**
   * @brief A function that resets the pixel object to the default value.
   */
  void reset();

 private:
  /**
   * @brief A variable that stores red color value, range [0, 256).
   */
  uint8_t r;

  /**
   * @brief A variable that stores blue color value, range [0, 256).
   */
  uint8_t b;

  /**
   * @brief A variable that stores green color value, range [0, 256).
   */
  uint8_t g;
};

#endif //PIXEL_FLOW_SRC_PIXEL_H
