#ifndef PIXEL_FLOW_SRC_DATA_H
#define PIXEL_FLOW_SRC_DATA_H

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/log/trivial.hpp>
#include <map>
#include <string>

using std::map;
using std::string;
using boost::gregorian::date;
class Data
{
private:

	/**
	 * @brief Getting the raw data from the file.
	 * @param file File name.
	 */
    static std::vector<std::vector<std::string>> get_activity_raw_data_lines(std::ifstream* file);

    /**
    * @brief Getting the header types from the file.
    * @param file File name.
    */
	static std::vector<std::string> get_activity_header_types(std::ifstream* file);

public:
    /**
    * @brief A pointer to a map of maps.
    */
	map<string, map<date, int>> * p_data_from_csv;

    /**
    * @brief A map of maps to store activity's types, and day datas.
    */
	map<string, map<date, int>> data;

    /**
    * @brief A function that takes a file name as a parameter and returns a map of maps.
    * @param file_name File name.
    */
	map<string, map<date, int>> update_data_from_csv(const string &file_name);

    /**
    * @brief A function that takes a pointer to a Data object and returns a vector of strings.
    * @param p_data pointer to data.
    */
    static std::vector<std::string> get_activity_types(Data * p_data);
};

#endif //PIXEL_FLOW_SRC_DATA_H
