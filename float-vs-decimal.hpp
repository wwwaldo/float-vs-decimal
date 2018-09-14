#pragma once

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
typedef std::numeric_limits< double > dbl;

enum ftdOpt { SINGLE_PRECISION, DOUBLE_PRECISION };

bool bar( std::ostream& os, ftdOpt opt, std::string original ){
	std::stringstream stream;
	stream.str("");

	float f;
	double d;
	switch(opt){ // Cast string value to nearest float / double
		case SINGLE_PRECISION:
			os.precision(flt::max_digits10);
			stream.precision(flt::max_digits10);
			
			f = std::stof(original);
			stream << f;
			break;
		case DOUBLE_PRECISION:
			os.precision(dbl::max_digits10);
			stream.precision(dbl::max_digits10);
			
			d = std::stod(original);
			stream << d;
			break;
		default:
			return false;
	}

	// Cast nearest back to string
	std::string repr = stream.str();
	// Remove trailing zeroes
	repr.erase( repr.find_last_not_of('0') + 1, std::string::npos ); 
		
	os << original << std::endl;
	// Print rounded value with colour encoding
	if (original == repr){
		os << _ANSI_GREEN << repr << _ANSI_WHITE << std::endl;
	} else{
		os << _ANSI_RED << repr << _ANSI_WHITE << std::endl;
	}
	
	return true;
}
