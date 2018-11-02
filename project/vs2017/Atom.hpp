#ifdef __cplusplus  //Check if C++
   #ifdef ATOMMASSCONST_PRECXX11
       #define ATOMMASSCONST_INT static const int
       #define ATOMMASSCONST_DOUBLE static const double
   #else
       #define ATOMMASSCONST_INT static constexpr int
       #define ATOMMASSCONST_DOUBLE static constexpr double
   #endif
#else   //For C
   #define ATOMMASSCONST_INT static const int
   #define ATOMMASSCONST_DOUBLE static const double
#endif

/// @defgroup AtomMassConst-Neutron Neutron
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Hydrogen Hydrogen
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Helium Helium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Lithium Lithium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Beryllium Beryllium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Boron Boron
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Carbon Carbon
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Nitrogen Nitrogen
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Oxygen Oxygen
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Fluorine Fluorine
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Neon Neon
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Sodium Sodium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Magnesium Magnesium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Aluminum Aluminum
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Silicon Silicon
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Phosphorus Phosphorus
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Sulfur Sulfur
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Chlorine Chlorine
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Argon Argon
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Potassium Potassium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Calcium Calcium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Scandium Scandium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Titanium Titanium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Vanadium Vanadium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Chromium Chromium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Manganese Manganese
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Iron Iron
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Cobalt Cobalt
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Nickel Nickel
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Copper Copper
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Zinc Zinc
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Gallium Gallium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Germanium Germanium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Arsenic Arsenic
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Selenium Selenium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Bromine Bromine
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Krypton Krypton
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Rubidium Rubidium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Strontium Strontium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Yttrium Yttrium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Zirconium Zirconium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Niobium Niobium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Molybdenum Molybdenum
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Technetium Technetium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Ruthenium Ruthenium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Rhodium Rhodium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Palladium Palladium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Silver Silver
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Cadmium Cadmium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Indium Indium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Tin Tin
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Antimony Antimony
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Tellurium Tellurium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Iodine Iodine
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Xenon Xenon
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Cesium Cesium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Barium Barium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Lanthanum Lanthanum
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Cerium Cerium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Praseodymium Praseodymium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Neodymium Neodymium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Promethium Promethium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Samarium Samarium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Europium Europium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Gadolinium Gadolinium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Terbium Terbium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Dysprosium Dysprosium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Holmium Holmium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Erbium Erbium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Thulium Thulium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Ytterbium Ytterbium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Lutetium Lutetium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Hafnium Hafnium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Tantalum Tantalum
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Tungsten Tungsten
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Rhenium Rhenium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Osmium Osmium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Iridium Iridium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Platinum Platinum
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Gold Gold
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Mercury Mercury
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Thallium Thallium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Lead Lead
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Bismuth Bismuth
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Polonium Polonium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Astatine Astatine
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Radon Radon
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Francium Francium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Radium Radium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Actinium Actinium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Thorium Thorium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Protactinium Protactinium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Uranium Uranium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Neptunium Neptunium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Plutonium Plutonium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Americium Americium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Curium Curium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Berkelium Berkelium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Californium Californium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Einsteinium Einsteinium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Fermium Fermium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Mendelevium Mendelevium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Nobelium Nobelium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Lawrencium Lawrencium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Rutherfordium Rutherfordium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Dubnium Dubnium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Seaborgium Seaborgium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Bohrium Bohrium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Hassium Hassium
/// @ingroup AtomMassConst


/// @defgroup AtomMassConst-Meitnerium Meitnerium
/// @ingroup AtomMassConst

