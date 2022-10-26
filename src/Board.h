#ifndef PIXEL_FLOW_SRC_BOARD_H
#define PIXEL_FLOW_SRC_BOARD_H

#include <cstdint>
#include <boost/circular_buffer.hpp>
#include "Pixel.h"

/**
 * @brief Board class used for pixel matrix manipulation.
 */
class Board
{
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
	uint16_t size();

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

};

#endif //PIXEL_FLOW_SRC_BOARD_H
