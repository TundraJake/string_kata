
// Jacob McKenna
// Paul Huskee
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::istringstream;
using std::getline;

int sum(const string &muh_string){

	istringstream iss(muh_string);
	int sum = 0;
	iss >> sum;
	return sum;
}


TEST_CASE("add_string function -- single integer"){
	REQUIRE(sum("") == 0);
	REQUIRE(sum("1") == 1);

}