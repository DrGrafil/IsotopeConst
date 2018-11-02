
#include <iostream>
#include <vector>
#include <string>


#include <stdlib.h>
#include <cstring>
#include <stdint.h>
#include <iomanip>  
#include "AtomicName/AtomicNumberToNameAndSymbol.hpp"
#include <string>

#if defined(_WIN32)
#include <experimental/filesystem> // C++-standard header file name  
#include <filesystem> // Microsoft-specific implementation header file name  
using namespace std::experimental::filesystem::v1;

#endif

#include "IsotopeDataParser.hpp"
#include "HeaderGenerator.hpp"






int main(int argc, char** argv) {
    std::cout << "Generating IsotopeConst Header File." << std::endl;

#if defined(_WIN32)
    std::cout << std::experimental::filesystem::current_path() << std::endl;
#endif

    IsotopeConst::IsotopeData.reserve(4000); // Number of known isotopes
    IsotopeConst::ReadAtomicMass("./data/mass16.txt");
    IsotopeConst::WriteCPPHeaderFile();
    system("pause");
	return 0;
}































