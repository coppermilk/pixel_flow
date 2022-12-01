#include "Board.h"

Board::Board(uint8_t width, uint8_t height) {
    // This is the constructor for the Board class. It is initializing the height, width, board_size, and pixel_board.
    this->height = height;
    this->width = width;
    board_size = width * height;
    pixel_board.resize(board_size, Pixel(0));
    BOOST_LOG_TRIVIAL(info) << "Board " << std::to_string(width) << "x" << std::to_string(height) << " created.";
}

Pixel Board::get_pixel(uint8_t x, uint8_t y) {
    // Convert a 2D array index into a 1D index
    return pixel_board[(x * width) + y];
}

uint16_t Board::size() const {
    return board_size;
}

Pixel Board::get_pixel(uint16_t i) {
    return pixel_board[i];
}

void Board::set_pixel(uint8_t x, uint8_t y, uint8_t rbg) {
    pixel_board[(x * width) + y].set_all(rbg);
}

void Board::set_pixel(uint16_t i, uint8_t rbg) {
    pixel_board[i].set_all(rbg);
}

void Board::set_pixel(uint16_t i, Pixel &p) {
    pixel_board[i].set_r(p.get_r());
    pixel_board[i].set_g(p.get_g());
    pixel_board[i].set_b(p.get_b());
}

void Board::set_pixel(uint16_t i, uint8_t r, uint8_t g, uint8_t b) {
    pixel_board[i].set_r(r);
    pixel_board[i].set_g(g);
    pixel_board[i].set_b(b);
}

std::string Board::get_pixel_data(uint8_t x, uint8_t y) {
    // Returning a string of the RGB values of the pixel at the given x and y coordinates.
    return "{" + std::to_string(pixel_board[(x * width) + y].get_r()) + "," +
           std::to_string(pixel_board[(x * width) + y].get_g()) + "," +
           std::to_string(pixel_board[(x * width) + y].get_b()) + "}";
}

void Board::push_back(Pixel p) {
    pixel_board.push_back(p);
}

void Board::show_in_row_mode() {
    // This is printing out the board in row mode.
    for (uint8_t i = 0; i < height; ++i) {
        std::string row;
        for (uint16_t j = 0; j < width; ++j) {
            // Green formatting value.
            //row += + "\x1B[32m" + (boost::format("%0i") % (int)get_pixel(i, j).get_r()).str() + "\033[0m\t\t";
            row += "\x1B[32m" + std::to_string(get_pixel(i, j).get_r()) + "\033[0m\t";
        }
        BOOST_LOG_TRIVIAL(debug) << row;
        row.clear();
    }
    BOOST_LOG_TRIVIAL(info) << "Board show in row mode.";
}

void Board::show_in_cell_mode() {
    // This is printing out the board in cell mode.
    BOOST_LOG_TRIVIAL(info) << "Board show in cell mode.";
    for (uint8_t h = 0; h < height; ++h) {
        std::string row;
        for (uint16_t w = 0; w < board_size; w += height) {
            uint16_t pixel_index = w + h;
            if (pixel_index < board_size) {
                int x = get_pixel(w + h).get_r();
                row += std::to_string(x) + "\t";
            }
        }
        BOOST_LOG_TRIVIAL(debug) << row;
        row.clear();
    }

}

uint8_t Board::get_height() const {
    return height;
}

uint8_t Board::get_width() const {
    return width;
}

void Board::reset_all_pixel() {
    for (uint16_t i = 0; i < board_size; ++i) {
        pixel_board[i].reset();
    }
}

uint8_t Board::map(long value, int from_low, int from_high, uint8_t to_low, uint8_t to_high) {
    return (value - from_low) * (to_high - to_low) / (from_high - from_low) + to_low;
}

