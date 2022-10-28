#ifndef PIXEL_FLOW_SRC_CSV_DATA_PARSER_H
#define PIXEL_FLOW_SRC_CSV_DATA_PARSER_H

#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/log/trivial.hpp>

class CsvDataParser
{
/**
 	* @brief It reads the first line of the file, splits it into a vector of strings, and then returns that vector.
	*
 	* @param file the file stream to read from
 	*
 	* @return A vector of strings.
 	*/
	static std::vector<std::string> get_activity_header_types(std::ifstream* file);

	/**
	* @brief This function reads the raw data from the file and returns a vector of vectors of strings.
 	*
 	* @param file The file to read from.
	*
	* @return A vector of vectors of strings.
 	*/
	static std::vector<std::vector<std::string>> get_activity_raw_data_lines(std::ifstream* file);

	/**
 	* @brief It reads the activity data from the file and returns a vector of tuples,
	* where each tuple contains the name of the activity and a map of dates and scores.
 	*
 	* @param file The file to read from.
	*
 	* @return Vector of tuples.
 	*/
	static std::vector<std::tuple<std::string,
								  std::map<boost::gregorian::date,
										   int>>> get_activity_data(std::ifstream* file);

	/**
 	* @brief A value for store vector of tuples. Each tuple contains a string and a map.
	* The string is the name of the activity, and the map contains the date and the score.
 	*/
	std::vector<std::tuple<std::string,
						   std::map<boost::gregorian::date,
									int>>> activity_data;

public:

	/**
 	* @brief A constructor.
 	*/
	explicit CsvDataParser(const std::string& file_name = "out.csv");


	/**
 	* @brief It update the activity data from the file and returns a vector of tuples,
	* where each tuple contains the name of the activity and a map of dates and scores.
 	*
 	* @param file The file to read from.
	*
 	* @return Vector of tuples.
 	*/
	std::vector<std::tuple<std::string,
						   std::map<boost::gregorian::date,
									int>>> activity_data_update(const std::string& file_name);

	/**
	 * @brief Getter activity data.
	 * @return Activity data.
	 */
	[[nodiscard]] std::vector<std::tuple<std::string,
										 std::map<boost::gregorian::date,
												  int>>> get_activity_data() const;


};


#endif //PIXEL_FLOW_SRC_CSV_DATA_PARSER_H
