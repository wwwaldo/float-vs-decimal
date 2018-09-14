// Executable without option parsing library.

#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <math.h>
#include <sstream> // string streams

// ANSI terminal colour codes -- UNIX only, not in cstdlib
#define _ANSI_WHITE "\x1b[0m"
#define _ANSI_RED "\x1b[31m"
#define _ANSI_GREEN "\x1b[32m"

typedef std::numeric_limits< float > flt; // import with limits. Header for max precision of a float.

int main(int argc, char *argv[]){
	if (argc <= 1) return 1;
	
	// Configure cout to display floats with max precision.
	std::vector<std::string> arguments(argv + 1, argv + argc);
	std::cout.precision(flt::max_digits10); 

	// create a string stream to store my strings.
	std::stringstream stream;
	stream.precision(flt::max_digits10);

	for (auto& arg : arguments){
		// Get closest-float repr of input string
		float val = std::stof(arg);
		stream.str(""); // Clear the string stream.
		stream << val;
		std::string repr = stream.str();

		// Remove trailing zeroes from repr.
		repr.erase( repr.find_last_not_of('0') + 1, std::string::npos ); 
		
		std::cout << arg << std::endl;
		if (arg == repr){
			std::cout << _ANSI_GREEN << repr << _ANSI_WHITE << std::endl;
		} else{
			std::cout << _ANSI_RED << repr << _ANSI_WHITE << std::endl;
		}
	}

	return 0;
}
