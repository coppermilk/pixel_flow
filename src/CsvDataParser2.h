//
// Created by zvgdb on 27.10.22.
//

#ifndef PIXEL_FLOW_SRC_CSVDATAPARSER2_H
#define PIXEL_FLOW_SRC_CSVDATAPARSER2_H

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

class CsvDataParser2
{
public:
	CsvDataParser2();
	map<string, map<date, int>> data;
};


#endif //PIXEL_FLOW_SRC_CSVDATAPARSER2_H
