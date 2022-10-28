#ifndef PIXEL_FLOW_SRC_GOOGLE_SHEETS_DATA_EXPORTER_H
#define PIXEL_FLOW_SRC_GOOGLE_SHEETS_DATA_EXPORTER_H

#include <boost/log/trivial.hpp>
#include <Python.h>

/**
 * @brief The class is using the Python API to run a Python script.
 * The script is reading a Google Sheet and saving it as a CSV file.
 */
class GoogleSheetsDataExporter
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
	static void to_csv(const std::string &sheet_id, const std::string &sheet_name, const std::string &name_export_file = "googlesheets.csv");
};

#endif //PIXEL_FLOW_SRC_GOOGLE_SHEETS_DATA_EXPORTER_H
