//
// Created by zvgdb on 27.10.22.
//

#ifndef PIXEL_FLOW_SRC_DATA_H
#define PIXEL_FLOW_SRC_DATA_H

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/log/trivial.hpp>

#include <string>
#include <map>

using std::map;
using std::string;
using boost::gregorian::date;
class Data
{
private:

	static std::vector<std::vector<std::string>> get_activity_raw_data_lines(std::ifstream* file);
	static std::vector<std::string> get_activity_header_types(std::ifstream* file);
	void csv_file_preparation();
public:
	map<string, map<date, int>> * p_data_from_csv;
	map<string, map<date, int>> data;
	//map<string, map<date, int>> data_from_csv_clear();

	map<string, map<date, int>> update_data_from_csv(const string &file_name);
};


#endif //PIXEL_FLOW_SRC_DATA_H
