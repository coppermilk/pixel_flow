//
// Created by zvgdb on 27.10.22.
//

#include "CsvDataParser.h"

std::vector<std::string> CsvDataParser::get_activity_header_types(std::ifstream* file)
{
	// back to the start!
	(*file).seekg(0, std::ios::beg);

	std::vector<std::string> activity_header;
	std::string first_line;
	getline(*file, first_line);
	if (!file->eof())
	{
		boost::split(activity_header, first_line, boost::is_any_of(","), boost::token_compress_off);
	}
	// back to the start!
	(*file).seekg(0, std::ios::beg);
	return activity_header;
}

std::vector<std::vector<std::string>> CsvDataParser::get_activity_raw_data_lines(std::ifstream* file)
{
	// back to the start!
	(*file).seekg(0, std::ios::beg);

	std::vector<std::vector<std::string>> raw_data;
	std::vector<std::string> raw_lines;
	std::string raw_line;
	if (!(*file).is_open())
	{
		BOOST_LOG_TRIVIAL(error) << "Error open file.";
	}
	else
	{
		// Skip first line. This is header.
		getline(*file, raw_line);

		// Get other lines.
		while (!(*file).eof())
		{
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

std::vector<std::tuple<std::string,
					   std::map<boost::gregorian::date,
								int>>> CsvDataParser::get_activity_data(std::ifstream* file)
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
	std::vector<std::tuple<std::string,
						   std::map<boost::gregorian::date,
									int>>> _activity_data(activity_header_types.size() - NUM_FIRST_INSIGNIFICANT_COL);

	// Getting first element of tuple. And then it is assigning string value type to this element.
	for (unsigned long i = 0; i < activity_header_types.size() - NUM_FIRST_INSIGNIFICANT_COL; ++i)
	{
		std::get<0>(_activity_data[i]) = activity_header_types[i + NUM_FIRST_INSIGNIFICANT_COL];
	}

	for (auto& raw_data_line : raw_data_lines)
	{
		// Extract score and data.
		int score;
		boost::gregorian::date data = boost::gregorian::from_string(raw_data_line[DATA_COL]);
		for (unsigned long i = NUM_FIRST_INSIGNIFICANT_COL; i < raw_data_line.size(); ++i)
		{
			if ((score = (int)strtol(raw_data_line[i].c_str(), nullptr, 10)) != 0L)
			{
				// Getting second element of tuple.
				// And then it is getting map from this element.
				// And then it is inserting score into map by key data.
				std::get<(1)>(_activity_data[i - NUM_FIRST_INSIGNIFICANT_COL])[data] += score;
			}
		}
	}
	return _activity_data;
}

CsvDataParser::CsvDataParser(const std::string& file_name)
{
	std::ifstream file;
	file.open(file_name);

	this->activity_data = get_activity_data(&file);

	// Clear fail and eof bits.
	file.clear();

	// Back to the start!
	file.seekg(0, std::ios::beg);

	file.close();
	BOOST_LOG_TRIVIAL(info) << "File \'" + file_name + "\' is parsed.";
}


std::vector<std::tuple<std::string,
					   std::map<boost::gregorian::date,
								int>>> CsvDataParser::get_activity_data() const
{
	return activity_data;
}

std::vector<std::tuple<std::string,
					   std::map<boost::gregorian::date,
								int>>> CsvDataParser::activity_data_update(const std::string& file_name)
{
	std::ifstream file;
	file.open(file_name);

	this->activity_data = get_activity_data(&file);

	// Clear fail and eof bits.
	file.clear();

	// Back to the start!
	file.seekg(0, std::ios::beg);

	file.close();
	BOOST_LOG_TRIVIAL(info) << "File \'" + file_name + "\' is parsed.";
	return activity_data;
}
