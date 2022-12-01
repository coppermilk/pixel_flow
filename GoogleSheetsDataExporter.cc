#include "GoogleSheetsDataExporter.h"


void GoogleSheetsDataExporter::to_csv(const std::string &sheet_csv_link, const std::string &name_export_file) {
    BOOST_LOG_TRIVIAL(info) << "Connecting to google sheets...";
    Py_Initialize();

    // A python script that is executed by the python interpreter.
    std::string pyScript;

    pyScript += "import requests as rs\n";
    pyScript += "url = '" + sheet_csv_link + "'\n";
    pyScript += "res = rs.get(url=url)\n";
    pyScript += "lines = res.content.split()\n";
    pyScript += "with open('" + name_export_file + "', 'w') as f:\n";
    pyScript += "    for line in lines:\n";
    pyScript += "        line = line + b','\n";
    pyScript += "        f.write(line.rstrip().decode() + str('\\n'))\n";
    pyScript += "f.close()\n";

    bool is_run_not_ok;
    //  0 - success, -1 Unsuccessful.
    is_run_not_ok = PyRun_SimpleString(pyScript.c_str());
    if (is_run_not_ok) {
        BOOST_LOG_TRIVIAL(error) << "Error execution python skript. File \'" + name_export_file + "\' not generated.i";
    } else {
        BOOST_LOG_TRIVIAL(info) << "File \'" + name_export_file + "\' successfully generated from google sheets.";
    }
    Py_Finalize();
}
