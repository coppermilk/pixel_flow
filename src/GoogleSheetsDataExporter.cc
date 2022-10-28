#include "GoogleSheetsDataExporter.h"

void GoogleSheetsDataExporter::to_csv(const std::string &sheet_id, const std::string &sheet_name, const std::string &name_export_file)
{
	BOOST_LOG_TRIVIAL(info) << "Connecting to google sheets...";
	Py_Initialize();

	// A python script that is executed by the python interpreter.
	std::string pyScript;
	pyScript += "import pandas as pd\n";
	pyScript += "sheet_id = '" + sheet_id + "'\n";
	pyScript += "sheet_name = '" + sheet_name + "'\n";
	pyScript += "url = f'https://docs.google.com/spreadsheets/d/{sheet_id}/gviz/tq?tqx=out:csv&sheet={sheet_name}'\n";
	pyScript += "df = pd.read_csv(url)\n";
	pyScript += "df.to_csv('" + name_export_file + "', encoding='ascii')\n";

	bool is_run_not_ok;
	//  0 - success, -1 Unsuccessful.
	is_run_not_ok = PyRun_SimpleString(pyScript.c_str());
	if (is_run_not_ok)
	{
		BOOST_LOG_TRIVIAL(error) << "Error execution python skript. File \'"+name_export_file+"\' not generated.";
	}
	else
	{
		BOOST_LOG_TRIVIAL(info) << "File \'"+name_export_file+"\' successfully generated from google sheets.";
	}
	Py_Finalize();
}
