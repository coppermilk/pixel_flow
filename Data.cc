#include "Data.h"

map<string, map<date, int>> Data::update_data_from_csv(const string &file_name) {
  std::ifstream file;
  file.open(file_name);
  //****************************

  // Struct of table:

  // 	       ,date, type, type, type,    <-- header_types
  // 1, YYYY-MM-DD,  int,  int,  int,    <-- raw_data_line
  // 2, YYYY-MM-DD,  int,  int,  int,    <-- raw_data_line
  // 3, YYYY-MM-DD,  int,  int,  int,    <-- raw_data_line

  const int DATA_COL = 1;
  const int NUM_FIRST_INSIGNIFICANT_COL = 2;

  std::vector<string> activity_header_types = get_activity_header_types(&file);
  std::vector<std::vector<string>> raw_data_lines = get_activity_raw_data_lines(&file);

  for (auto &raw_data_line : raw_data_lines) {
    // Extract score and data.
    int score;
    try {
      boost::gregorian::date date = boost::gregorian::from_string(raw_data_line[DATA_COL]);
      for (unsigned long i = NUM_FIRST_INSIGNIFICANT_COL; i < raw_data_line.size(); ++i) {
        if ((score = (int) strtol(raw_data_line[i].c_str(), nullptr, 10)) != 0L) {
          this->data[activity_header_types[i]][date] = score;
        }
      }
    } catch (std::exception const &ex) {
      BOOST_LOG_TRIVIAL(error) << ex.what();
    }

  }
  file.clear();
  file.seekg(0, std::ios::beg);
  file.close();
  BOOST_LOG_TRIVIAL(info) << "File \'" + file_name + "\' is parsed. Data updated.";
  return data;
}

std::vector<std::string> Data::get_activity_header_types(std::ifstream *file) {

  // back to the start!
  (*file).seekg(0, std::ios::beg);

  std::vector<std::string> activity_header;
  std::string first_line;
  getline(*file, first_line);
  if (!file->eof()) {
    boost::split(activity_header, first_line, boost::is_any_of(","), boost::token_compress_off);
  }
  // back to the start!
  (*file).seekg(0, std::ios::beg);
  return activity_header;

}

std::vector<std::vector<std::string>> Data::get_activity_raw_data_lines(std::ifstream *file) {
  // back to the start!
  (*file).seekg(0, std::ios::beg);

  std::vector<std::vector<std::string>> raw_data;
  std::vector<std::string> raw_lines;
  std::string raw_line;
  if (!(*file).is_open()) {
    BOOST_LOG_TRIVIAL(error) << "Error open file.";
  } else {
    // Skip first line. This is header.
    getline(*file, raw_line);

    // Get other lines.
    while (!(*file).eof()) {
      getline(*file, raw_line);
      boost::split(raw_lines, raw_line, boost::is_any_of(","), boost::token_compress_off);
      raw_data.push_back(raw_lines);
    }
    raw_data.pop_back();
  }

  // back to the start!
  (*file).seekg(0, std::ios::beg);
  return raw_data;
}

std::vector<std::string> Data::get_activity_types(Data *p_data) {
  std::vector<std::string> activity_types;
  for (const auto &d : p_data->data) {
    activity_types.push_back(d.first);
  }
  return activity_types;
}

int Data::get_max_activy_score_in(const string &type, int for_last_n_days) {
  using namespace boost::gregorian;
  using namespace boost::posix_time;

  date today = second_clock::local_time().date();
  date oldest_possible_day = today - days(for_last_n_days);
  int max = 0;

  for (const auto &i : this->data[type]) {
    if (i.first >= oldest_possible_day) {
      max = std::max(max, i.second);
    }
  }
  return max;
}

