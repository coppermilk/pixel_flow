#include "GitHubDataExporter.h"

void GitHubDataExporter::to_csv(const std::string &user_name, const std::string &name_export_file)
{
	BOOST_LOG_TRIVIAL(info) << "Connecting to github...";
// Initialise the Python interpreter
	Py_Initialize();

	std::string pyScript;
	pyScript += "from bs4 import BeautifulSoup\n";
	pyScript += "import requests\n";

	pyScript += "url = 'https://github.com/" + user_name + "'\n";
	pyScript += "html = requests.get(url).text\n";
	pyScript += "soup = BeautifulSoup(html, 'html.parser')\n";

	pyScript += "results = soup.findAll('rect')\n";

	pyScript += "f = open('github.csv', 'w')\n";
	pyScript += "f.write(',date,github\\n')\n";
	pyScript += "primary_key = 1\n";
	pyScript += "for result in results:\n";
	pyScript += "    if len(result.attrs) > 6:\n";
	pyScript += "        count = result.get('data-count')\n";
	pyScript += "        if int(count):\n";
	pyScript += "            string = str(primary_key) + ',' + result.get('data-date') + ',' + result.get('data-count') + ',\\n'\n";
	pyScript += "            f.write(string)\n";
	pyScript += "            primary_key += 1\n";
	pyScript += "f.close()\n";

	bool is_run_not_ok;
	//  0 - success, -1 Unsuccessful.
	is_run_not_ok = PyRun_SimpleString(pyScript.c_str());
	if (is_run_not_ok)
	{
		BOOST_LOG_TRIVIAL(error) << "Error execution python script. File \'" + name_export_file + "\' not generated.";
	}
	else
	{
		BOOST_LOG_TRIVIAL(info) << "File \'" + name_export_file + "\' successfully generated from github.";
	}
	Py_Finalize();
}
