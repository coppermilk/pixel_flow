#include "python.h" // Must include BEFORE Qt!
#include "MainWindow.h"
#include <QtWidgets/QApplication>
#include <boost/algorithm/hex.hpp>
#include <boost/log/trivial.hpp>
#include <vector>
#include <utility>
#include "Pixel.h"
#include "Board.h"
#include "ControllerBoard.h"
#include "Data.h"
#include "GitHubDataExporter.h"
#include "GoogleSheetsDataExporter.h"

int main(int argc, char *argv[]) {

  using std::string;
  const string github_user_name = "coppermilk";
  const string github_name_export_file = "github.csv";

  const string sheet_csv_link =
      "https://docs.google.com/spreadsheets/d/e/2PACX-1vQBT1unt3khao9AI8hoHrLUzEv6RDlS5wnr0rzn0TxaLJD4HtuTtBAtJVBxYsc14cQsmOTvM8RwCGsA/pub?gid=0&single=true&output=csv";
  const string googlesheets_name_export_file = "googlesheets.csv";

  GitHubDataExporter::to_csv(github_user_name, github_name_export_file);
  GoogleSheetsDataExporter::to_csv(sheet_csv_link, googlesheets_name_export_file);

  Data data;
  data.update_data_from_csv(googlesheets_name_export_file);
  data.update_data_from_csv(github_name_export_file);
  //std::cout <<  data.get_max_activy_score_in("github", 14 * 7);

  Board board(52, 7);
  ControllerBoard controller_board(&board, &data);

  auto types = Data::get_activity_types(&data);
  std::vector<std::pair<Pixel, Pixel>> default_min_max_brithnes;
  default_min_max_brithnes.emplace_back(std::make_pair(Pixel(14, 68, 41), Pixel(57, 211, 83)));
  default_min_max_brithnes.emplace_back(std::make_pair(Pixel(28, 35, 66), Pixel(255, 49, 87)));
  default_min_max_brithnes.emplace_back(std::make_pair(Pixel(66, 112, 14), Pixel(213, 203, 35)));
  default_min_max_brithnes.emplace_back(std::make_pair(Pixel(236, 236, 239), Pixel(42, 43, 89)));

  int i = 0;
  for (const auto &type : types) {
    if (i < default_min_max_brithnes.size()) {
      controller_board.set_mode_activity(type, default_min_max_brithnes[i].first,
                                         default_min_max_brithnes[i].second);
    }

    board.show_in_cell_mode();
    ++i;
  }

  QApplication a(argc, argv);
  MainWindow w(&controller_board);
  w.show();
  return a.exec();
}


/*
 
    
    BOST
    Project -> Propertis -> C/C++  -> General -> Additional Include Directories -> (boost_1_80_0\boost_1_80_0)
    Project -> Propertis -> Linker -> General -> Additional Library Directories -> (boost_1_80_0\boost_1_80_0)
    Project -> Propertis -> Configuration Properties -> VC++ Directories -> Library Directories -> (boost_1_80_0\boost_1_80_0\stage\lib)

    Qt
    To show console
    Go to Project Properties > Linker > System : set SubSystem to "SUBSYSTEM:CONSOLE"

    PYTHOH
    Project -> Propertis -> Configuration Properties -> VC++ Directories -> Include Directories -> (include)
    Project -> Propertis -> Configuration Properties -> VC++ Directories -> Library Directories -> (libs)
*/





