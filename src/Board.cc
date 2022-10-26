#include <iostream>
#include "Board.h"
#include "Pixel.h"
#include <boost/format.hpp>

Board::Board(uint8_t width, uint8_t height)
{
	// This is the constructor for the Board class. It is initializing the height, width, board_size, and pixel_board.
	this->height = height;
	this->width = width;
	board_size = width * height;
	pixel_board.resize(board_size, Pixel(0));
}

Pixel Board::get_pixel(uint8_t x, uint8_t y)
{
	// Convert a 2D array index into a 1D index
	return pixel_board[(x * width) + y];
}

uint16_t Board::size()
{
	return board_size;
}

Pixel Board::get_pixel(uint16_t i)
{
	return pixel_board[i];
}

void Board::set_pixel(uint8_t x, uint8_t y, uint8_t rbg)
{
	pixel_board[(x * width) + y].set_all(rbg);
}

void Board::set_pixel(uint16_t i, uint8_t rbg)
{
	pixel_board[i].set_all(rbg);
}


std::string Board::get_pixel_data(uint8_t x, uint8_t y)
{
	// Returning a string of the RGB values of the pixel at the given x and y coordinates.
	return "{" + std::to_string(pixel_board[(x * width) + y].get_r()) + "," +
			std::to_string(pixel_board[(x * width) + y].get_b()) + "," +
			std::to_string(pixel_board[(x * width) + y].get_g()) + "}";
}

void Board::push_back(Pixel p)
{
	pixel_board.push_back(p);
}

void Board::show_in_row_mode()
{
	// This is printing out the board in row mode.
	for (uint8_t i = 0; i < height; ++i)
	{
		for (uint16_t j = 0; j < width; ++j)
		{
			std::cout << (boost::format("%4i") % (int)get_pixel(i, j).get_r());
		}
		std::cout << std::endl;
	}
}

void Board::show_in_cell_mode()
{
	// This is printing out the board in cell mode.
	for (uint8_t h = 0; h < height; ++h) {
		for (uint16_t w = 0; w < board_size; w += height) {
			uint16_t pixel_index = w + h;
			if(pixel_index < board_size){
				int x = get_pixel(w + h).get_r();
				std::cout << (boost::format("%4i") % x);
			}
		}
		std::cout << std::endl;
	}
}

uint8_t Board::get_height() const
{
	return height;
}

uint8_t Board::get_width() const
{
	return width;
}

