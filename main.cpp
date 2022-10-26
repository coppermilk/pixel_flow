#include <iostream>
#include <boost/circular_buffer.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time_adjustor.hpp>
#include <boost/date_time/c_local_time_adjustor.hpp>
#include <boost/format.hpp>

#include "Board.h"
int main() {
	uint8_t x = 16;
	uint8_t y = 7;
	Board b(x, y);

	std::vector<std::string> activity = {"Codding", "English"};

	/* Setting the pixel value of each cell to the index of the cell. */
	for(int i = 0; i < b.size(); ++i){
			b.set_pixel(i, i % 256);
	}

	b.push_back(Pixel(99));
	b.show_in_cell_mode();
	return 0;
}
