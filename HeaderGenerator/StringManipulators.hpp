/// @file StringManipulators.hpp
///
/// @brief Useful string manipulators
/// @author Elliot Grafil 
/// @date 11/1/2018


//=================================
// Header guard
#pragma once
#ifndef ISOTOPE_CONST_STRING_MANIPULATORS_HPP
#define ISOTOPE_CONST_STRING_MANIPULATORS_HPP
//=================================
// Included dependencies
#include <string>
//=================================
// Forward declared dependencies

//=================================
//


namespace IsotopeConst
{
    int StringToInt(std::string & str);
    double StringToDouble(std::string & str);
    void removeCharsFromString(std::string &str, char* charsToRemove);
} //namespace IsotopeConst

#endif