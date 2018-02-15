
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
	string token;
	int temp = 0;
	int sum = 0;
	while(std::getline(iss, token,',')){
		sum += stoi(token);
	}

	return sum;
}


TEST_CASE("sum function -- single integer"){
	
	REQUIRE(sum("") == 0);
	REQUIRE(sum("1") == 1);
	REQUIRE(sum("1,") == 1);
	REQUIRE(sum("102030000") == 102030000);
	REQUIRE(sum("-1") == -1);
	REQUIRE(sum("13") == 13);
	REQUIRE(sum("45") == 45);
	REQUIRE(sum("-2") == -2);

}

TEST_CASE("sum function -- N integers"){
	REQUIRE(sum("1,2") == 3);
	REQUIRE(sum("1,2,3") == 6);

}