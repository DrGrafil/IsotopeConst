/// @file HeaderGenerator.hpp
///
/// @brief Contains Isotope Structure
/// @author Elliot Grafil 
/// @date 11/1/2018


//=================================
// Header guard
#pragma once
#ifndef ISOTOPE_CONST_ISOTOPE_HPP
#define ISOTOPE_CONST_ISOTOPE_HPP
//=================================
// Included dependencies

//=================================
// Forward declared dependencies
#include <string>
#include <stdint.h>
#include <iostream>
//=================================
//


namespace IsotopeConst
{
    // File Data structure:
    //    a1, i3, i5, i5, i5, 1x, a3, a4, 1x, f13.5, f11.5, f11.3, f9.3, 1x, a2, f11.3, f9.3, 1x, i3, 1x, f12.5, f11.5
    //     1,  4,  9, 14, 19, 20, 23, 27, 28,    41,     52,   63,   72, 73, 75,    86,   95, 96, 99,100,   112, 123
    struct Isotope
    {
        //Field		                                                               Length       End Position
        std::string     S1;                 // Space? 						            1		1		
        int32_t  		NMinusZ;            // Neutrons minus protons					3       4
        int32_t 		N;                  // Neutrons		                            5       9
        int32_t 		Z;                  // Protons									5      14
        int32_t 		A;                  // Mass number  							5      19
        std::string     S2;                 // Space?                                   1      20 
        std::string     Symbol;             // Element Symbol                           3      23
        std::string     O;                  // O? reaction?                             4      27 
        std::string     S3;                 // Space?                                   1      28 
        double          MassExc;            // Mass Excess    keV                      13      41 
        double          MassExcUnc;         // Mass Excess Uncertainty keV             11      52 
        double          BindEPerA;          // BINDING ENERGY per A keV                11      63 
        double          BindEPerAUnc;       // BINDING ENERGY per A Uncertainty keV     9      72 
        std::string     S4;                 // Space?                                   1      73 
        std::string     BetaDecayType;      // Beta Decay                               2      75 
        double          BetaDecayE;         // Beta Decay Energu keV                   11      86 
        double          BetaDecayEUnc;      // Beta Decay Energy uncertainty keV        9      95 
        std::string     S5;                 // Space?                                   1      96
        int32_t 		AtomicMassInteger;  // Integer portion of atomic mass           3      99
        std::string     S6;                 // Space?                                   1     100 
        double          AtomicMassMantissa; // fractional portion of atomic mass x10^6 12     112
        double          AtomicMassUnc;      // Atomic mass uncertainty x10^6           11     123

        Isotope(
            std::string     s1,
            int32_t	        nMinusZ,
            int32_t         n,
            int32_t 		z,
            int32_t 		a,
            std::string     s2,
            std::string     symbol,
            std::string     o,
            std::string     s3,
            double          massExc,
            double          massExcUnc,
            double          bindEPerA,
            double          bindEPerAUnc,
            std::string     s4,
            std::string     betaDecayType,
            double          betaDecayE,
            double          betaDecayEUnc,
            std::string     s5,
            int32_t 		atomicMassInteger,
            std::string     s6,
            double          atomicMassMantissa,
            double          atomicMassUnc
        ):
        S1(s1),
            NMinusZ(nMinusZ),
            N(n),
            Z(z),
            A(a),
            S2(s2),
            Symbol(symbol),
            O(o),
            S3(s3),
            MassExc(massExc),
            MassExcUnc(massExcUnc),
            BindEPerA(bindEPerA),
            BindEPerAUnc(bindEPerAUnc),
            S4(s4),
            BetaDecayType(betaDecayType),
            BetaDecayE(betaDecayE),
            BetaDecayEUnc(betaDecayEUnc),
            S5(s5),
            AtomicMassInteger(atomicMassInteger),
            S6(s6),
            AtomicMassMantissa(atomicMassMantissa),
            AtomicMassUnc(atomicMassUnc)
        {}
    };


    inline void PrintIsotopeInfo(const Isotope & isotope)
    {
        std::cout << "Symbol:" << isotope.Symbol << " A:" << isotope.A << " Mass:" << isotope.AtomicMassInteger << " " << isotope.AtomicMassMantissa << std::endl;
        /*std::cout 	<< "ID: " << star.ID
        << " P: " << star.Parallax
        << " RA: " << star.RA
        << " DE: " << star.DE
        << " Mag: " << star.ApparentMagnitude
        << " BV: " << star.BV
        << std::endl; */
    }
} //namespace IsotopeConst



#endif