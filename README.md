# IsotopeConst
IsotopeConst is a header only C/C++ constant library for atomic isotopes. It contains a total of 30,924 constants for 3436 atomic isotopes up to and including Oganesson (element 119) compiled by the [Atomic Mass Data Center](https://www-nds.iaea.org/amdc/). 

## About
This constant library is primarially made for people who want to rapidly do some calculation involving atomic isotopes without having to build a system to read in atomic data.  This library provides access to the current set of isotope constants found in the [2016 Atomic Mass Evaluation](https://doi.org/10.1088/1674-1137/41/3/030003) done by the [Atomic Mass Data Center](https://www-nds.iaea.org/amdc/). This set is recommended by the [International Atomic Energy Agency (IAEA)](https://www.iaea.org/). 

The constants are compiled from the [Atomic Mass Evaluation - AME2016](https://www-nds.iaea.org/amdc/ame2016/mass16.txt). The header file and resulting documentation is generated from this file. The constant library has data on neutron count, proton count, mass number, atomic mass, mass excess and binding energey per nucleon for all known isotopes of elements upto and including Oganesson (element 119).

## Documentation
All constants are fully documented. You can read the documentation [HERE](https://metex.github.io/IsotopeConst/html/modules.html). If you prefer a pdf it can be found [HERE](https://github.com/Metex/IsotopeConst/blob/master/docs/latex/refman.pdf).  

## Setup
IsotopeConst is a header-only library, and therfore does not need to be compiled. All that needs to be done is copy the IsotopeConst folder to your include directories and add `#include "IsotopeConst/IsotopeConst.hpp"`. 

All of the constants are placed under the IsotopeConst namespace. For simple programs you might want to use  `using IsotopeConst` after including the header file. 

## Example Usage
All the constants follow the naming scheme: element name, mass number, property. For example Samarium-135 atomic mass would be:
`Samarium135AtomicMass`

Below is an example of using IsotopeConst to calculate mass excess for Rhodium-106.
```cpp
#include <iostream>
#include "IsotopeConst/IsotopeConst.hpp"

//Calculates the mass excess for Rhodium-106
int main() {
    const double uToMeVPercSquared = 931.4940954;

    double massExcessInu = IsotopeConst::Rhodium106AtomicMass - IsotopeConst::Rhodium106MassNumber;

    std::cout << "The mass excess of Rh-106 is " << massExcessInu << " u or " << massExcessInu * uToMeVPercSquared << " MeV/c^2" << std::endl;
    return 0;
}
```

---
## Release notes

### [IsotopeConst 1.0.0](https://github.com/Metex/IsotopeConst/releases/latest)
#### Features:
- Completed documentation
- Completed final pass for public release.


