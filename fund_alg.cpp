#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include "is_stable_funs.h"
#include "fund_alg_funs.h"
#include "file_to_pref.h"

//performs the fundamental algorithm.
//requires two file names as inputs; the first file contains preference table information for the men,
//the second file contains preference table information for the women.
int main(int argc, char* argv[]){
	//converts the contents of the first file into a preference table for the men.
	std::string f_name_one{argv[1]};
	std::unordered_map<int,std::vector<int>> men {file_to_pref(f_name_one)};
	//converts the contents of the first file into a preference table for the women.
	std::string f_name_two{argv[2]};
	std::unordered_map<int,std::vector<int>> women {file_to_pref(f_name_two)};

	//obtains a matching using the fundamental algorithm.
	std::vector<std::vector<int>> matching {fund_alg(men,women)};
	std::cout<<"Matching:"<<std::endl;
	for(auto i:matching){
		std::cout<<i[0]<<" "<<i[1]<<std::endl;
	}
	
	//checks if matching is stable for the given preference tables.
	if(is_stable(men,women,matching)){
		std::cout<<"Matching is stable."<<std::endl;
	}else{
		std::cout<<"Matching is unstable."<<std::endl;
	}
	return 0;
}		
