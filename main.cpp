
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
using std::runtime_error;

// function find_del
// Returns the 2nd element in the character array as the delimiter.
char find_del(const string & str){

	if (str[0] == '/' && str[1] == '/'){
		return str[2];
	}

	return ',';
}

// function get_del
// Returns the delimiter
char get_del(const string & str){

	return find_del(str);
}

// function sum
// returns the sum of integers seperated some delimiter character.
int sum(const string &muh_string){

	istringstream iss(muh_string);
	string token;
	int temp = 0;
	int sum = 0;
	char del;

	// Get Delimiter
	del = get_del(muh_string);

	while(std::getline(iss, token, del)){

		try {
			sum += stoi(token);
		}
		catch (...){
			sum += 0;
		}
	}
	return sum;
}

/*
	Test Driven Development Section
*/

TEST_CASE("sum function -- single integer"){
	
	REQUIRE(sum("") == 0);
	REQUIRE(sum("1") == 1);
	REQUIRE(sum("1,") == 1);
	REQUIRE(sum("102030000") == 102030000);
	REQUIRE((sum("-1") == -1));
	REQUIRE(sum("13") == 13);
	REQUIRE(sum("45") == 45);
	REQUIRE(sum("-2") == -2);

}

TEST_CASE("sum function -- N integers"){
	REQUIRE(sum("1,2") == 3);
	REQUIRE(sum("1,2,3") == 6);
	REQUIRE(sum("-1,-1,-1") == -3);
	REQUIRE(sum("1,2,3,4") == 10);
	REQUIRE(sum("87,1,7") == 95);
	REQUIRE(sum("1,-7,3") == -3);


}

TEST_CASE("sum function -- Newline testing"){

	REQUIRE(sum("1\n") == 1);
	REQUIRE(sum("1\n,1") == 2);
	REQUIRE(sum("1,\n") == 1);
	REQUIRE(sum("1,\n\n\n\n\n\n1,1") == 3);
	REQUIRE(sum("\n\n\n\n1,\n\n\n\n\n\n1,1\n\n\n\n\n") == 3);

}

TEST_CASE("sum function -- Deliminator testing"){

	REQUIRE(sum("//;\n1;") == 1);
	REQUIRE(sum("//;\n1;2;") == 3);
	REQUIRE(sum("//;\n1;2;3") == 6);

	REQUIRE(sum("///\n1/2/3") == 6);
	REQUIRE(sum("//.\n1.2.3") == 6);
	// Don't use numbers please!
	REQUIRE(!(sum("//2\n12223") == 10));


}


