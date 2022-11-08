#include "Board.h"
#include "ControllerBoard.h"

#include "GoogleSheetsDataExporter.h"
#include "GitHubDataExporter.h"
#include "Data.h"
#include <thread>
//sudo apt install gcc
// sudo apt install build-essential
// sudo apt-get install python3-dev
int main()
{
	Data data;
	

	GitHubDataExporter::to_csv("coppermilk");
	GoogleSheetsDataExporter::to_csv("1axA_i8GiCK1V7aQCcK4O5IPsjpGNsiAayjn7zziXpgA", "db");
	GitHubDataExporter::to_csv("coppermilk");
	data.update_data_from_csv("googlesheets.csv");

	data.update_data_from_csv("github.csv");
	Board board(8, 8);
	ControllerBoard controller_board(&board);

	board.show_in_cell_mode();
	std::string type = "github";
	controller_board.set_mode_activity(data, type);
	board.show_in_cell_mode();
	return 0;
}

