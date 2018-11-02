/// @file HeaderGenerator.hpp
///
/// @brief Generates all the IsotopeConst Header File.
/// @author Elliot Grafil (Metex)
/// @date 11/1/2018


//=================================
// Header guard
#pragma once
#ifndef ISOTOPE_CONST_HEADER_GENERATOR_HPP
#define ISOTOPE_CONST_HEADER_GENERATOR_HPP
//=================================
// Included dependencies
#include <vector>
#include "Isotope.hpp"
//=================================
// Forward declared dependencies

//=================================
//


namespace IsotopeConst
{
    bool WriteCPPHeaderFile();
    bool CreateIsotopeTable(std::vector<std::vector<Isotope*>> &isotopeTable);

    void CreateDoxygenGroups(std::ofstream &file, std::vector<std::vector<Isotope*>> &isotopeTable);
    void CreateConstantGroup(std::ofstream &file, std::vector<std::vector<Isotope*>> &isotopeTable);
    void CreateConstant(std::ofstream &file, Isotope &isotope, std::string &constName);
} //namespace IsotopeConst

#endif