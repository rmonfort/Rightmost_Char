#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::istringstream;
using std::distance;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	// Get line from input file
	while (getline(ifs, line))
	{
		istringstream iss(line);
		// Load string and character to be searched
		string s, t;
		getline(iss, s, ',');
		getline(iss, t, ',');
		// Find and print position of rightmost occurence
		int found = s.find_last_of(t);
		if (found == string::npos)
		{
			// Set found to -1 if character not found
			found = -1;
		}
		cout << found << endl;
	}

	return 0;
}