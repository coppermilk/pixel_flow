#include "Board.h"
#include "ControllerBoard.h"
#include "Data.h"
#include "GitHubDataExporter.h"
#include "GoogleSheetsDataExporter.h"

// sudo apt install build-essential
// sudo apt-get install python3-dev
// sudo apt-get install libboost-all-dev
// sudo apt install python3-pip

// pip install requests==2.28.1
// pip install bs4==0.0.1
// pip install pandas==1.5.1

int main() {

  using std::string;

  const string github_user_name = "coppermilk";
  const string github_name_export_file = "github.csv";

  const string googlesheets_sheet_id = "1axA_i8GiCK1V7aQCcK4O5IPsjpGNsiAayjn7zziXpgA";
  const string googlesheets_sheet_name = "db";
  const string googlesheets_name_export_file = "googlesheets.csv";

  GitHubDataExporter::to_csv(github_user_name, github_name_export_file);
  GoogleSheetsDataExporter::to_csv(googlesheets_sheet_id, googlesheets_sheet_name, googlesheets_name_export_file);

  Data data;
  data.update_data_from_csv(googlesheets_name_export_file);
  data.update_data_from_csv(github_name_export_file);

  Board board(8, 7);
  ControllerBoard controller_board(&board);

  auto types = Data::get_activity_types(&data);
  for (const auto &type : types) {
    controller_board.set_mode_activity(data, type);
    board.show_in_cell_mode();
  }

  return 0;
}
