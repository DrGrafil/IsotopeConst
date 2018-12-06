#include "HeaderGenerator.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>

#include "IsotopeDataParser.hpp"
#include "AtomicName/AtomicNumberToNameAndSymbol.hpp"

namespace IsotopeConst
{
    const int AtomZMax = 119;


    bool WriteCPPHeaderFile() {
        std::vector<std::vector<Isotope*>> isotopeTable;
        std::ofstream file;

        file.open("IsotopeConst.hpp", std::ios::out);
        if (!file.good())
        {
            std::cout << "File Write Error";
        }

        PopulateIsotopeTable(isotopeTable);
        CreatePreamble(file);
        CreateMacros(file);
        CreateDoxygenGroups(file, isotopeTable);
        CreateConstantGroup(file, isotopeTable);
        CreateFooter(file);

        return true;
    }

    bool PopulateIsotopeTable(std::vector<std::vector<Isotope*>> &isotopeTable) {
        isotopeTable.clear();
        isotopeTable.resize(200);

        for (auto it = IsotopeData.begin(); it != IsotopeData.end(); it++) {
            isotopeTable[it->Z].emplace_back(&(*it));
        }
        return true;
    }


    void CreatePreamble(std::ofstream &file) {
        file << "/******************************************************************************" << std::endl;
        file << "* IsotopeConst 1.0.1" << std::endl;
        file << "* A constants library for physics and chemistry containing data for all known" << std::endl;
        file << "* Atomic Isotopes." << std::endl;
        file << "*" << std::endl;
        file << "* Based off of 2016 Atomic Mass Evaluation by the Atomic Mass Data Center" << std::endl;
        file << "*" << std::endl;
        file << "* See http://amdc.in2p3.fr/web/masseval.html or https://www-nds.iaea.org/amdc/" << std::endl;
        file << "* For article:" << std::endl;
        file << "* https://doi.org/10.1088/1674-1137/41/3/030003" << std::endl;
        file << "*------------------------------------------------------------------------" << std::endl;
        file << "* Copyright (c) 11/1/2018 Elliot M. Grafil" << std::endl;
        file << "*" << std::endl;
        file << "*                       Distributed under the MIT License" << std::endl;
        file << "*" << std::endl;
        file << "* Permission is hereby granted, free of charge, to any person obtaining a copy" << std::endl;
        file << "* of this software and associated documentation files (the \"Software\"), to deal" << std::endl;
        file << "* in the Software without restriction, including without limitation the rights" << std::endl;
        file << "* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell" << std::endl;
        file << "* copies of the Software, and to permit persons to whom the Software is" << std::endl;
        file << "* furnished to do so, subject to the following conditions:" << std::endl;
        file << "*" << std::endl;
        file << "* The above copyright notice and this permission notice shall be included in all" << std::endl;
        file << "* copies or substantial portions of the Software." << std::endl;
        file << "*" << std::endl;
        file << "* THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR" << std::endl;
        file << "* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY," << std::endl;
        file << "* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE" << std::endl;
        file << "* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER" << std::endl;
        file << "* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM," << std::endl;
        file << "* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE" << std::endl;
        file << "* SOFTWARE." << std::endl;
        file << "********************************************************************************/" << std::endl;
        file << std::endl;
        file << std::endl;
        file << "/// @file IsotopeConst.hpp" << std::endl;
        file << "/// @brief Constants library of atomic isotope data from 2016 Atomic Mass Evaluation by" << std::endl;
        file << "/// the Atomic Mass Data Center" << std::endl;
        file << "/// " << std::endl;
        file << "/// IsotopeConst contains a total of 30,924 constants for 3436 Isotopes up to and including Oganesson (119)" << std::endl; // 9* 3436 isotopes
        file << "/// This library provides access to the current set of constants in the 2016 Atomic Mass Evaluation." << std::endl;
        file << "/// Isotope data on neutron count, proton count, mass number, atomic mass, mass excess and " << std::endl;
        file << "/// binding energy per nucleon is constained within along with uncertainties. Note that data is not" << std::endl;
        file << "/// a one to one conversion found in the Atomic Mass Evaluation due to numbers being rounded" << std::endl;
        file << "/// due to floating point conversion." << std::endl;
        file << "///" << std::endl;
        file << "/// See https://doi.org/10.1088/1674-1137/41/3/030003" << std::endl;
        file << "///" << std::endl;
        file << "/// @author Elliot Grafil " << std::endl;
        file << "/// @date 11/1/18" << std::endl;
        file << "/// @version 1.0.1" << std::endl;
        file << std::endl;
        file << std::endl;
        file << "//=================================" << std::endl;
        file << "// Header guard" << std::endl;
        file << "#pragma once" << std::endl;
        file << "#ifndef ISOTOPE_CONST_HPP" << std::endl;
        file << "#define ISOTOPE_CONST_HPP" << std::endl;
        file << std::endl;
    }


    void CreateMacros(std::ofstream &file) {

        file << "//=================================" << std::endl;
        file << "// MACRO Definitions" << std::endl;
        file << std::endl;
        file << "/// @defgroup IsotopeConst-Macros Macros" << std::endl;
        file << "/// @ingroup IsotopeConst" << std::endl;
        file << std::endl;
        file << "/// @addtogroup IsotopeConst-Macros Macros" << std::endl;
        file << "/// @{" << std::endl;
        file << std::endl;
        file << "/**" << std::endl;
        file << "*   @def ISOTOPECONST_INT" << std::endl;
        file << "*   @brief Changes int constant variable definition depending upon what version of C/C++ is used to compile the code." << std::endl;
        file << "*/" << std::endl;
        file << std::endl;
        file << "/**" << std::endl;
        file << "*   @def ISOTOPECONST_DOUBLE" << std::endl;
        file << "*   @brief Changes double constant variable definition depending upon what version of C/C++ is used to compile the code." << std::endl;
        file << "*/" << std::endl;
        file << std::endl;
        file << "#ifdef __cplusplus  //Check if C++" << std::endl;
        file << "   #ifdef ISOTOPECONST_PRECXX11" << std::endl;
        file << "       #define ISOTOPECONST_INT static const int" << std::endl;
        file << "       #define ISOTOPECONST_DOUBLE static const double" << std::endl;
        file << "   #else" << std::endl;
        file << "       #define ISOTOPECONST_INT static constexpr int" << std::endl;
        file << "       #define ISOTOPECONST_DOUBLE static constexpr double" << std::endl;
        file << "   #endif" << std::endl;
        file << "#else   //For C" << std::endl;
        file << "   #define ISOTOPECONST_INT static const int" << std::endl;
        file << "   #define ISOTOPECONST_DOUBLE static const double" << std::endl;
        file << "#endif" << std::endl;
        file << std::endl;
        file << "/// @}" << std::endl;
        file << std::endl;
    }




    void CreateDoxygenGroups(std::ofstream &file, std::vector<std::vector<Isotope*>> &isotopeTable) {
        file << "//=================================" << std::endl;
        file << "// Document Groupings" << std::endl;
        file << std::endl;
        file << "/// @defgroup IsotopeConst Isotope Constants" << std::endl;
        file << "/// @brief Constants library of atomic isotope data from Atomic Mass Data Center." << std::endl;
        file << "///" << std::endl;
        file << "/// Constants are from 2016 Atomic Mass Evaluation:" << std::endl;
        file << "///" << std::endl;
        file << "/// https://doi.org/10.1088/1674-1137/41/3/030003" << std::endl;
        file << std::endl;


        for (int Z = 0; Z < AtomZMax; Z++) {

            auto name = atomicNameSymbols[Z];

            file << std::endl;
            file << "/// @defgroup IsotopeConst-" << name.first << " " << name.first << std::endl;
            file << "/// @ingroup IsotopeConst" << std::endl;
            file << std::endl;

            //Isotopes
            for (std::vector<Isotope*>::iterator it = (isotopeTable[Z]).begin(); it != (isotopeTable[Z]).end(); it++) {

                file << "///     @defgroup IsotopeConst-" << name.first << "-" << name.second << (**it).A << " " << name.first << " " << (**it).A << std::endl;
                file << "///     @ingroup IsotopeConst-" << name.first << std::endl;
                file << std::endl;
            }

        }
    }




    void CreateConstantGroup(std::ofstream &file, std::vector<std::vector<Isotope*>> &isotopeTable) {

        file << "//=================================" << std::endl;
        file << "// Constant Definitions" << std::endl;
        file << std::endl;
        file << "namespace IsotopeConst" << std::endl;
        file << "{" << std::endl;
        file << std::endl;
        //Iterate over all proton numbers
        for (int Z = 0; Z < AtomZMax; Z++) {
            auto name = atomicNameSymbols[Z];


            //Isotopes
            for (auto it = isotopeTable[Z].begin(); it != isotopeTable[Z].end(); it++) {
                file << "   /// @addtogroup IsotopeConst-" << name.first << "-" << name.second << (**it).A << std::endl;
                file << "   /// @{" << std::endl;
                CreateConstant(file, **it, name.first);
                file << "   /// @}" << std::endl;
                file << std::endl;

            }
        }


    }

    void CreateConstant(std::ofstream &file, Isotope &isotope, std::string &constName) {
        int constPad = 30;
        int namePad = 35;
        int spacePad = 20;
        int perc = 15; // double percision

        double AtomicMass = isotope.AtomicMassInteger + (isotope.AtomicMassMantissa * 1e-6);
        double AtomicMassUnc = isotope.AtomicMassUnc * 1e-6;
        file << std::left << std::setw(constPad) << "   ISOTOPECONST_INT    " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "Neutrons = ") << std::right << std::setw(spacePad) << isotope.N <<                                             ";           " << "/**< \\f$ N \\f$ Neutrons in " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << ". */" << std::endl;
        file << std::left << std::setw(constPad) << "   ISOTOPECONST_INT    " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "Protons = ") << std::right << std::setw(spacePad) << isotope.Z <<                                              ";           " << "/**< \\f$ Z \\f$ Protons in " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << ". */" << std::endl;
        file << std::left << std::setw(constPad) << "   ISOTOPECONST_INT    " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "MassNumber = ") << std::right << std::setw(spacePad) << isotope.A <<                                           ";           " << "/**< \\f$ A \\f$ Mass number of " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << ". */" << std::endl;
        file << std::left << std::setw(constPad) << "   ISOTOPECONST_DOUBLE " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "MassExc = ") << std::right << std::setw(spacePad) << std::setprecision(perc) << isotope.MassExc <<             ";           " << "/**< \\f$ ME (keV) \\f$ Mass excess of " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << " in keV. */" << std::endl;
        file << std::left << std::setw(constPad) << "   ISOTOPECONST_DOUBLE " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "MassExcUnc = ") << std::right << std::setw(spacePad) << std::setprecision(perc) << isotope.MassExcUnc <<       ";           " << "/**< \\f$ \\Delta ME\\ (keV) \\f$ Uncertainty in mass excess of " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << " in keV. */" << std::endl;
        file << std::left << std::setw(constPad) << "   ISOTOPECONST_DOUBLE " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "BindEPerA = ") << std::right << std::setw(spacePad) << std::setprecision(perc) << isotope.BindEPerA <<         ";           " << "/**< \\f$ BE/A\\ (keV) \\f$ Binding energy per nucleon of " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << " in keV. */" << std::endl;
        file << std::left << std::setw(constPad) << "   ISOTOPECONST_DOUBLE " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "BindEPerAUnc = ") << std::right << std::setw(spacePad) << std::setprecision(perc) << isotope.BindEPerAUnc <<   ";           " << "/**< \\f$ \\Delta BE/A\\ (keV) \\f$ Uncertainty in binding energy per A of " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << " in keV. */" << std::endl;
        file << std::left << std::setw(constPad) << "   ISOTOPECONST_DOUBLE " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "AtomicMass = ") << std::right << std::setw(spacePad) << std::setprecision(perc) << AtomicMass <<               ";           " << "/**< \\f$ m_a\\ (u) \\f$ Atomic mass of " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << " in unified atomic mass units. */" << std::endl;
        file << std::left << std::setw(constPad) << "   ISOTOPECONST_DOUBLE " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "AtomicMassUnc = ") << std::right << std::setw(spacePad) << std::setprecision(perc) << AtomicMassUnc <<         ";           " << "/**< \\f$ \\Delta m_a\\ (u) \\f$ Uncertainty in atomic mass of " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << " in unified atomic mass units. */" << std::endl;

    }


    void CreateFooter(std::ofstream &file) {
        file << "} //namespace IsotopeConst" << std::endl;
        file << "#endif" << std::endl;
        file << std::endl;
    }
}
