#ifndef PIXEL_FLOW_SRC_BOARD_H
#define PIXEL_FLOW_SRC_BOARD_H

#include "Pixel.h"
#include <boost/circular_buffer.hpp>
#include <boost/format.hpp>
#include <boost/log/trivial.hpp>
#include <cstdint>
#include <iostream>

/**
 * @brief Board class used for pixel matrix manipulation.
 */
class Board {
 private:

  /**
   * @brief A circular buffer of pixels.
   * Matrix rectangle of RGB Pixels.
   * @Note 2D matrix represented as 1D string array.
   */
  boost::circular_buffer<Pixel> pixel_board;

  /**
   * @brief A variable that stores the height of the board.
   * Allowable range is [0, 256).
   */
  uint8_t height;

  /**
   * @brief A variable that stores the width of the board.
   * Allowable range is [0, 256).
   */

  uint8_t width;

  /**
   * @brief A variable that stores the size of the board.
   *
   * Size means the number of unit pixels 1x1.
   * Size is also the number obtained by multiplying the height by the width.
   * Allowable range is [0, 65536).
   */
  uint16_t board_size;

 public:
  /**
   * @brief This is a constructor. It is called when a new object is created
   * a new matrix rectangle object.
   * @param width X coordinate of size for creating rectangle matrix object.
   * Allowable range is [0, 256).
   * @param height Y coordinate of size for creating rectangle matrix object.
   * Allowable range is [0, 256).
   */
  Board(uint8_t width, uint8_t height);

  /**
   * @brief This function is returning a pixel board size.
   *
   * Size means the number of unit pixels 1x1.
   * Size is also the number obtained by multiplying the height by the width.
   * @return Size of rectangle. Allowable range is [0, 65536).
   */
  uint16_t size() const;

  /**
   * @brief This function is returning a pixel object at the given x and y coordinates.
   *
   * @param x Pixel coordinate in rectangle matrix object.
   * @param y Pixel coordinate in rectangle matrix object.
   * @return RGB Pixel Object. Allowable range each color [0, 256).
   */
  Pixel get_pixel(uint8_t x, uint8_t y);

  /**
   * @brief This function is returning a pixel object at the given i coordinate.
   *
   * @param i Pixel coordinate in 1D matrix object.
   * @return RGB Pixel Object. Allowable range each color [0, 256).
   */
  Pixel get_pixel(uint16_t i);

  /**
   * @brief This function is returning a string of the pixel data
   * in the format of {r,g,b} at the given x and y coordinates.
   *
   * @param x Pixel coordinate in rectangle matrix object.
   * @param y Pixel coordinate in rectangle matrix object.
   * @return String contains RBG information.
   */

  std::string get_pixel_data(uint8_t x, uint8_t y);

  /**
   * @brief This function is setting a pixel object at the given x and y coordinates in rgb value.
   * @param x Pixel coordinate in rectangle matrix object.
   * @param y Pixel coordinate in rectangle matrix object.
   * @param rbg Color range [0, 256) for setup all colors in this value.
   */
  void set_pixel(uint8_t x, uint8_t y, uint8_t rbg);

  /**
   * @brief This function is setting a pixel object at the given i coordinate in rgb value.
   * @param i Pixel coordinate in 1D matrix object.
   * @param rbg Color range [0, 256) for setup all colors in this value.
   */
  void set_pixel(uint16_t i, uint8_t rbg);

  void set_pixel(uint16_t i, Pixel &p);

  void set_pixel(uint16_t i, uint8_t r, uint8_t b, uint8_t g);

  /**
   * @brief Adding a new pixel to the end of the board.
   * @param pixel To adding to the end of circular board object.
   */
  void push_back(Pixel pixel);

  /**
   * @brief Printing the pixel board in row mode.
   */
  void show_in_row_mode();

  /**
   * @brief Printing the pixel board in cell mode.
   */
  void show_in_cell_mode();

  [[nodiscard]] uint8_t get_height() const;

  [[nodiscard]] uint8_t get_width() const;

  void reset_all_pixel();

  /**
   * @brief This function is mapping the value of x from the range (from_low, from_high) to the range (to_low, to_high).
   * @param value The number to map.
   * @param from_low The lower bound of the value’s current range.
   * @param from_high The upper bound of the value’s current range.
   * @param to_low The lower bound of the value’s target range.
   * @param toHigh The upper bound of the value’s target range.
   * @return The mapped value.
   */
  static uint8_t map(long value, int from_low, int from_high, uint8_t to_low = 0, uint8_t to_high = 255);
};

#endif //PIXEL_FLOW_SRC_BOARD_H
