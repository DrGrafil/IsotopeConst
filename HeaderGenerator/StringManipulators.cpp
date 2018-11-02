#include "StringManipulators.hpp"

#include <algorithm>

namespace IsotopeConst
{
    int StringToInt(std::string & str) {
        if (!str.empty()) {
            return std::stoi(str);
        }
        return -1;
    }

    double StringToDouble(std::string & str) {
        if (!str.empty()) {
            return std::stod(str);
        }
        return -1.0;
    }

    //https://stackoverflow.com/questions/5891610/how-to-remove-certain-characters-from-a-string-in-c
    void removeCharsFromString(std::string &str, char* charsToRemove) {
        for (unsigned int i = 0; i < strlen(charsToRemove); ++i) {
            str.erase(std::remove(str.begin(), str.end(), charsToRemove[i]), str.end());
        }
    }

} //namespace IsotopeConst