// 	Unit Tests for EGXPhys
//
//  Created by Elliot Grafil on 7/28/17.
//  Copyright � 2017 Elliot Grafil. All rights reserved.
//

#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

//#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
//#include "catch.hpp"

#define NISTCONST_COMMON_SYMBOLS_NAMES

#define EGXPHYS_GLM // Useing GLM

#include "./3rd Party/glm/glm.hpp"
#include "./3rd Party/glm/gtc/type_ptr.hpp"

#include "../EGXPhys/EGXPhys.hpp"


using namespace EGXPhys;
#include "Astrophysics/AstrophysicsTests.hpp"
#include "Atomic/AtomicTests.hpp"
#include "Kinetics/KineticsTests.hpp"
#include "Optics/OpticsTests.hpp"
#include "Electrodynamics/ElectrodynamicTest.hpp"

using namespace EGXMath;
#include "EGXMath/EGXMathTests.hpp"

int main(int argc, char* argv[]) {
	// global setup...

	int result = Catch::Session().run(argc, argv);

	// global clean-up...
	system("pause");
	return result;
}