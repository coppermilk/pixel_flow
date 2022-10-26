
#include "boost/filesystem/fstream.hpp"
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp> // Include for boost::split
#include <iostream>
#include <boost/date_time/gregorian/gregorian.hpp>

//namespace fs = boost::filesystem;


/**
 * It reads the first line of the file, splits it into a vector of strings, and then returns that vector
 *
 * @param file the file stream to read from
 *
 * @return A vector of strings.
 */
std::vector<std::string> get_activity_header_types(std::ifstream* file)
{
	(*file).seekg(0, std::ios::beg); // back to the start!
	std::vector<std::string> activity_header;
	std::string first_line;
	getline(*file, first_line);
	if (!file->eof())
	{
		boost::split(activity_header, first_line, boost::is_any_of(", "), boost::token_compress_on);
	}
	(*file).seekg(0, std::ios::beg); // back to the start!
	return activity_header;
}

/**
 * This function reads the raw data from the file and returns a vector of vectors of strings
 *
 * @param file The file to read from.
 *
 * @return A vector of vectors of strings.
 */
std::vector<std::vector<std::string>> get_activity_raw_data_lines(std::ifstream* file)
{
	(*file).seekg(0, std::ios::beg); // back to the start!
	std::vector<std::vector<std::string>> raw_data;
	std::vector<std::string> raw_lines(5);
	std::string raw_line;
	if (!(*file).is_open())
	{
		std::cout << "Error open file." << std::endl;
	}
	else
	{
		// Skip first line. This is header.
		getline(*file, raw_line);

		// Get other lines.
		while (!(*file).eof())
		{
			getline(*file, raw_line);
			boost::split(raw_lines, raw_line, boost::is_any_of(", "), boost::token_compress_on);
			raw_data.push_back(raw_lines);
		}
		//raw_data.pop_back();
	}
	(*file).seekg(0, std::ios::beg); // back to the start!
	return raw_data;
}


/**
 * It reads the activity data from the file and returns a vector of tuples, where each tuple contains the name of the
 * activity and a map of dates and scores
 *
 * @param file The file to read from.
 *
 * @return Vector of tuples.
 */
std::vector<std::tuple<std::string,
					   std::map<boost::gregorian::date,
								int>>> get_activity_data(std::ifstream* file)
{
	// Struct of table:
	// First row header.
	// 0 Col - primary key.
	// 1 Col - activity data.
	// 2 ... N - activity score.

	const int DATA_COL = 1;
	const int NUM_FIRST_INSIGNIFICANT_COL = 2;

	std::vector<std::string> activity_header_types = get_activity_header_types(file);
	std::vector<std::vector<std::string>> raw_data_lines = get_activity_raw_data_lines(file);
	std::vector<std::tuple<std::string, std::map<boost::gregorian::date, int>>> activity_data;

	// See rows of data.
	for (int i = NUM_FIRST_INSIGNIFICANT_COL; i < activity_header_types.size(); ++i)
	{

		// Crete map to emplace back.
		std::map<boost::gregorian::date, int> dates_and_scores;

		for (auto& raw_data_line : raw_data_lines)
		{
			// If value exist. Vector can be smaller than i (optimize).
			if (raw_data_line.size() > i)
			{
				// Extract score and data.
				int score;
				if ((score = (int)strtol(raw_data_line[i].c_str(), nullptr, 10)) != 0L)
				{
					boost::gregorian::date data = boost::gregorian::from_string(raw_data_line[DATA_COL]);
					dates_and_scores[data] += score;
				}
			}
		}
		activity_data.emplace_back(activity_header_types[i], dates_and_scores);
		dates_and_scores.clear();
	}
	return activity_data;
}

int main()
{

	std::ifstream file;
	file.open("out.csv");
	//
	std::vector<std::tuple<std::string, std::map<boost::gregorian::date, int>>> activity_data = get_activity_data(&file);

	file.clear(); // clear fail and eof bits
	file.seekg(0, std::ios::beg); // back to the start!
	file.close();


	return 0;
}

