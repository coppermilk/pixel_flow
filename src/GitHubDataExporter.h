//
// Created by zvgdb on 27.10.22.
//

#ifndef PIXEL_FLOW_SRC_GITHUBDATAEXPORTER_H
#define PIXEL_FLOW_SRC_GITHUBDATAEXPORTER_H

#include <boost/log/trivial.hpp>
#include <Python.h>
#include <string>

class GitHubDataExporter
{
public:
	/**
	 * @brief The function is using the Python API to run a Python script.
	 * The script is reading a Google Sheet and saving it as a CSV file.
	 * @param sheet_id  Unique title and numeric sheetId value.
	 * You can find the "sheet id" in a Google Sheets URL.
	 * @param sheet_name String value that represents the sheet name.
	 * You can find the "sheet_name" in a Google Sheets URL.
	 * @param name_export_file Default name to export file is 'out.csv' this name can be changed.
	 */
	static void to_csv(const std::string &user_name, const std::string &name_export_file = "github.csv");
};


#endif //PIXEL_FLOW_SRC_GITHUBDATAEXPORTER_H
