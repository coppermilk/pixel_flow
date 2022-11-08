#include "Board.h"
#include "ControllerBoard.h"
#include "GoogleSheetsDataExporter.h"
#include "GitHubDataExporter.h"
#include "Data.h"


// sudo apt install build-essential
// sudo apt-get install python3-dev
// sudo apt-get install libboost-all-dev
// sudo apt install python3-pip
// pip install requests
// pip install bs4
// pip install pandas

int main()
{

	GitHubDataExporter::to_csv("coppermilk", "github.csv");
	GoogleSheetsDataExporter::to_csv("1axA_i8GiCK1V7aQCcK4O5IPsjpGNsiAayjn7zziXpgA", "db", "googlesheets.csv");

    Data data;
	data.update_data_from_csv("googlesheets.csv");
	data.update_data_from_csv("github.csv");

	Board board(56, 7);
	ControllerBoard controller_board(&board);

    auto types = Data::get_activity_types(&data);
	for(const auto& type : types){
        controller_board.set_mode_activity(data, type);
        board.show_in_cell_mode();
    }


	return 0;
}
