#include "HeaderGenerator.hpp"

#include <iostream>
#include <fstream>
#include <iomanip>

#include "IsotopeDataParser.hpp"
#include "AtomicName/AtomicNumberToNameAndSymbol.hpp"

namespace IsotopeConst
{
    const int AtomZMax = 110;


    bool WriteCPPHeaderFile() {
        std::vector<std::vector<Isotope*>> isotopeTable;
        std::ofstream file;

        file.open("Atom.hpp", std::ios::out);
        if (!file.good())
        {
            std::cout << "File Write Error";
        }

        file << "#ifdef __cplusplus  //Check if C++" << std::endl;
        file << "   #ifdef ATOMMASSCONST_PRECXX11" << std::endl;
        file << "       #define ATOMMASSCONST_INT static const int" << std::endl;
        file << "       #define ATOMMASSCONST_DOUBLE static const double" << std::endl;
        file << "   #else" << std::endl;
        file << "       #define ATOMMASSCONST_INT static constexpr int" << std::endl;
        file << "       #define ATOMMASSCONST_DOUBLE static constexpr double" << std::endl;
        file << "   #endif" << std::endl;
        file << "#else   //For C" << std::endl;
        file << "   #define ATOMMASSCONST_INT static const int" << std::endl;
        file << "   #define ATOMMASSCONST_DOUBLE static const double" << std::endl;
        file << "#endif" << std::endl;



        CreateIsotopeTable(isotopeTable);
        CreateDoxygenGroups(file, isotopeTable);
        CreateConstantGroup(file, isotopeTable);


        return true;
    }

    bool CreateIsotopeTable(std::vector<std::vector<Isotope*>> &isotopeTable) {
        isotopeTable.clear();
        isotopeTable.resize(200);

        for (auto it = IsotopeData.begin(); it != IsotopeData.end(); it++) {
            isotopeTable[it->Z].emplace_back(&(*it));
        }
        return true;
    }

    void CreateDoxygenGroups(std::ofstream &file, std::vector<std::vector<Isotope*>> &isotopeTable) {

        for (int Z = 0; Z < AtomZMax; Z++) {

            auto name = atomicNameSymbols[Z];

            file << std::endl;
            file << "/// @defgroup AtomMassConst-" << name.first << " " << name.first << std::endl;
            file << "/// @ingroup AtomMassConst" << std::endl;
            file << std::endl;

            //Isotopes
            for (std::vector<Isotope*>::iterator it = (isotopeTable[Z]).begin(); it != (isotopeTable[Z]).end(); it++) {

                file << "///     @defgroup AtomMassConst-" << name.first << "-" << name.second << (**it).A << " " << name.first << " " << (**it).A << std::endl;
                file << "///     @ingroup AtomMassConst-" << name.first << std::endl;
                file << std::endl;
            }

        }
    }




    void CreateConstantGroup(std::ofstream &file, std::vector<std::vector<Isotope*>> &isotopeTable) {
        //Iterate over all proton numbers
        for (int Z = 0; Z < AtomZMax; Z++) {
            auto name = atomicNameSymbols[Z];


            //Isotopes
            for (auto it = isotopeTable[Z].begin(); it != isotopeTable[Z].end(); it++) {
                file << "   /// @addtogroup AtomMassConst-" << name.first << "-" << name.second << (**it).A << std::endl;
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
        file << std::left << std::setw(constPad) << "   ATOMMASSCONST_INT    " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "Neutrons = ") << std::right << std::setw(spacePad) << isotope.N << ";           " << "/**< \f$ \f$ Neutrons in " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << ". */" << std::endl;
        file << std::left << std::setw(constPad) << "   ATOMMASSCONST_INT    " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "Protons = ") << std::right << std::setw(spacePad) << isotope.Z << ";           " << "/**< \f$ \f$ Protons in " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << ". */" << std::endl;
        file << std::left << std::setw(constPad) << "   ATOMMASSCONST_INT    " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "AtomicWeight = ") << std::right << std::setw(spacePad) << isotope.A << ";           " << "/**< \f$ \f$ Atomic weight of " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << ". */" << std::endl;
        file << std::left << std::setw(constPad) << "   ATOMMASSCONST_DOUBLE " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "MassExc = ") << std::right << std::setw(spacePad) << std::setprecision(perc) << isotope.MassExc << ";           " << "/**< \f$ \f$ Mass excess of " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << " in keV. */" << std::endl;
        file << std::left << std::setw(constPad) << "   ATOMMASSCONST_DOUBLE " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "MassExcUnc = ") << std::right << std::setw(spacePad) << std::setprecision(perc) << isotope.MassExcUnc << ";           " << "/**< \f$ \f$ Uncertainty in mass excess of " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << " in keV. */" << std::endl;
        file << std::left << std::setw(constPad) << "   ATOMMASSCONST_DOUBLE " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "BindEPerA = ") << std::right << std::setw(spacePad) << std::setprecision(perc) << isotope.BindEPerA << ";           " << "/**< \f$ \f$ Binding energy per A of " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << " in keV. */" << std::endl;
        file << std::left << std::setw(constPad) << "   ATOMMASSCONST_DOUBLE " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "BindEPerAUnc = ") << std::right << std::setw(spacePad) << std::setprecision(perc) << isotope.BindEPerAUnc << ";           " << "/**< \f$ \f$ Uncertainty in binding energy per A of " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << " in keV. */" << std::endl;
        file << std::left << std::setw(constPad) << "   ATOMMASSCONST_DOUBLE " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "AtomicMass = ") << std::right << std::setw(spacePad) << std::setprecision(perc) << AtomicMass << ";           " << "/**< \f$ \f$ Atomic mass of " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << " in amu. */" << std::endl;
        file << std::left << std::setw(constPad) << "   ATOMMASSCONST_DOUBLE " << std::setw(namePad) << (constName + std::to_string(isotope.A) + "AtomicMassUnc = ") << std::right << std::setw(spacePad) << std::setprecision(perc) << AtomicMassUnc << ";           " << "/**< \f$ \f$ Uncertainty in atomic mass of " << atomicNameSymbols[isotope.Z].first << "-" << isotope.A << " in amu. */" << std::endl;

    }
}
