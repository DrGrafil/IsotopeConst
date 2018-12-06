/// @file IsotopeDataParser.hpp
///
/// @brief All functions used to parse the isotope data.
/// @author Elliot Grafil 
/// @date 11/1/2018


//=================================
// Header guard
#pragma once
#ifndef ISOTOPE_CONST_ISOTOPE_DATA_PARSER_HPP
#define ISOTOPE_CONST_ISOTOPE_DATA_PARSER_HPP
//=================================
// Included dependencies
#include <string>
#include <vector>
#include "Isotope.hpp"
//=================================
// Forward declared dependencies

//=================================
//


namespace IsotopeConst
{
    extern std::vector<Isotope> IsotopeData;
    bool ReadAtomicMass(std::string FilePath);
    bool ParseLineData(std::string &lineData, std::vector<std::string> &columns);
    bool AddIsotope(std::vector<std::string> &columns);
} //namespace IsotopeConst

#endif