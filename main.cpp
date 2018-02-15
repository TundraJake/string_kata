
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

	return 0;
}


TEST_CASE("add_string function -- single integer"){
	REQUIRE(sum("") == 0);
}