#include <iostream>
#include <string>
#include <vector>
#include "optionparser.h"
#include "float-vs-decimal.hpp"

enum  optionIndex { UNKNOWN, HELP, DOUBLE };
const option::Descriptor usage[] =
{
 {UNKNOWN, 0, "", "",option::Arg::None, "USAGE: float-vs-decimal [--double | -d | --help ] strings \n\n"
                                        "Options:" },
 {HELP, 0,"", "help",option::Arg::None, "  --help  \tPrint usage and exit." },
 {DOUBLE, 0,"d","double",option::Arg::None, "  --double, -d  \tUse double precision." },
 {UNKNOWN, 0, "", "",option::Arg::None, "\nExamples:\n"
                               "  float-vs-decimal 0.1\n"
                               "  float-vs-decimal --double 0.1\n" },
 {0,0,0,0,0,0}
};

int main(int argc, char* argv[])
{
  argc-=(argc>0); argv+=(argc>0); // skip program name argv[0] if present
  option::Stats  stats(usage, argc, argv);
  std::vector<option::Option> options(stats.options_max);
  std::vector<option::Option> buffer(stats.buffer_max);
  option::Parser parse(usage, argc, argv, &options[0], &buffer[0]);

  if (parse.error())
    return 1;

  if (options[HELP] || argc == 0) {
    option::printUsage(std::cout, usage);
    return 0;
  }

  for (option::Option* opt = options[UNKNOWN]; opt; opt = opt->next())
    std::cout << "Unknown option: " << std::string(opt->name,opt->namelen) << "\n";

  if (options[DOUBLE].count() > 0 ){
	std::cout << "Using 64-bit floating point:" << std::endl;
	for (int i = 0; i < parse.nonOptionsCount(); ++i){
		bar( std::cout, DOUBLE_PRECISION, parse.nonOption(i) );
	}
  } else{
  	std::cout << "Using 32-bit floating point:" << std::endl;
	for (int i = 0; i < parse.nonOptionsCount(); ++i){
		bar( std::cout, SINGLE_PRECISION, parse.nonOption(i) );
	}
  }

  return 0;

}
