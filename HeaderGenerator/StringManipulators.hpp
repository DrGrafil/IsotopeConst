/// @file StringManipulators.hpp
///
/// @brief Useful string manipulators
/// @author Elliot Grafil (Metex)
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
    void StringToInt(std::string & str);
    void StringToDouble(std::string & str);
    void removeCharsFromString(std::string &str, char* charsToRemove);
} //namespace IsotopeConst

#endif