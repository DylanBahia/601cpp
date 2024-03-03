#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

//creates a preference table using the information in the given file.
std::unordered_map<int,std::vector<int>> file_to_pref(std::string& filename){
	//variable for the lines of the file.
	std::string line;
	//variable for keys in preference table.
	std::string person;
	//variable for values in preference table.
	std::string name;
	//preference table.
	std::unordered_map<int,std::vector<int>> pref_table;
	//opens file.
	std::ifstream file {filename};
	if(file.is_open()){
		//iterates over lines of file.
		while(std::getline(file,line)){
			std::stringstream l(line);
			//first name in line is a key in preference table.
			std::getline(l,name,' ');
			person = name;
			//remaining names in line are values of corresponding key in preference table.
			std::vector<int> prefs;
			while(std::getline(l,name,' ')){
				prefs.push_back(std::stoi(name));
			}
			//creates entry in preference table.
			pref_table[std::stoi(person)] = prefs;
		}
		file.close();
	}
	return pref_table;	
}
