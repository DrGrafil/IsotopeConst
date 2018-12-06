/// @file HeaderGenerator.hpp
///
/// @brief Generates all the IsotopeConst Header File.
/// @author Elliot Grafil 
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
    bool PopulateIsotopeTable(std::vector<std::vector<Isotope*>> &isotopeTable);

    void CreatePreamble(std::ofstream &file);
    void CreateMacros(std::ofstream &file);
    void CreateDoxygenGroups(std::ofstream &file, std::vector<std::vector<Isotope*>> &isotopeTable);
    void CreateConstantGroup(std::ofstream &file, std::vector<std::vector<Isotope*>> &isotopeTable);
    void CreateConstant(std::ofstream &file, Isotope &isotope, std::string &constName);
    void CreateFooter(std::ofstream &file);
} //namespace IsotopeConst

#endif