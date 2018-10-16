
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <stdint.h>


#if defined(_WIN32)
#include <experimental/filesystem> // C++-standard header file name  
#include <filesystem> // Microsoft-specific implementation header file name  
using namespace std::experimental::filesystem::v1;

#endif

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Isotope;

bool ReadAtomicMass(std::string FilePath);

bool WriteBinaryFile();

const int MAX_CHARS_PER_LINE = 200;
const int LINES_TILL_DATA = 39;

std::vector<Isotope> IsotopeData;

int main(int argc, char** argv) {
    std::cout << "HELLO" << std::endl;

#if defined(_WIN32)
    std::cout << std::experimental::filesystem::current_path() << std::endl;
#endif

    IsotopeData.reserve(20000);
	//ReadHip("Hip_test.dat");
    ReadAtomicMass("mass16.txt");
	//WriteBinaryFile();
    system("pause");
	return 0;
}


struct Isotope
{	
// File Data structure:
//    a1, i3, i5, i5, i5, 1x, a3, a4, 1x, f13.5, f11.5, f11.3, f9.3, 1x, a2, f11.3, f9.3, 1x, i3, 1x, f12.5, f11.5
//     1,  4,  9, 14, 19, 20, 23, 27, 28,    41,     52,   63,   72, 73, 75,    86,   95, 96, 99,100,   112, 123
                                        //Field		                           Length  End Position
    std::string     S1;                 // Space? 						            1		1		
    int32_t  		NMinusZ;            // Neutrons minus protons					3       4
    int32_t 		N;                  // Neutrons		                            5       9
    int32_t 		Z;                  // Protons									5      14
    int32_t 		A;                  // Atomic Weight							5      19
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

void PrintIsotopeInfo( const Isotope & isotope )
{
    std::cout << "Symbol:" <<isotope.Symbol << " A:" << isotope.A << " Mass:" << isotope.AtomicMassInteger << " " << isotope.AtomicMassMantissa << std::endl;
	/*std::cout 	<< "ID: " << star.ID
				<< " P: " << star.Parallax
				<< " RA: " << star.RA
				<< " DE: " << star.DE
				<< " Mag: " << star.ApparentMagnitude
				<< " BV: " << star.BV 
				<< std::endl; */
}

//https://stackoverflow.com/questions/5891610/how-to-remove-certain-characters-from-a-string-in-c
void removeCharsFromString(std::string &str, char* charsToRemove) {
    for (unsigned int i = 0; i < strlen(charsToRemove); ++i) {
        str.erase(std::remove(str.begin(), str.end(), charsToRemove[i]), str.end());
    }
}

bool ReadAtomicMass(std::string FilePath) {	
    std::cout << "In fucntion readatomic mass" << std::endl;
    //Buffers	
    char buffer[MAX_CHARS_PER_LINE];
    std::vector<std::string> columns; // Holds data in columns
    

  	std::ifstream file;
	file.open( FilePath.c_str() ); // open a file
    if (!file.good()) {
        std::cout << "FILE NOT FOUND" << std::endl;
        return 0; // exit if file not found
    }
    	
    
    
    //Advance pass header:
    for (int i = 1; i <= LINES_TILL_DATA; i++) {
        file.getline(buffer, MAX_CHARS_PER_LINE);
    }
    std::cout << "done";
    while (!file.eof())
  	{
  		
        std::cout << "in";
        //Clears columns data
        columns.clear();
        columns.reserve(24);

  		file.getline( buffer, MAX_CHARS_PER_LINE );
  		
        //Turn into columns
        std::string lineData = std::string(buffer);

        columns.emplace_back(lineData.substr(0, 1));
        columns.emplace_back(lineData.substr(1, 3));
        columns.emplace_back(lineData.substr(4, 5));
        columns.emplace_back(lineData.substr(9, 5));
        columns.emplace_back(lineData.substr(14, 5));
        columns.emplace_back(lineData.substr(19, 1));
        columns.emplace_back(lineData.substr(20, 3));
        columns.emplace_back(lineData.substr(23, 4));
        columns.emplace_back(lineData.substr(27, 1));
        columns.emplace_back(lineData.substr(28, 13));
        columns.emplace_back(lineData.substr(41, 11));
        columns.emplace_back(lineData.substr(52, 11));
        columns.emplace_back(lineData.substr(63, 9));
        columns.emplace_back(lineData.substr(72, 1));
        columns.emplace_back(lineData.substr(73, 2));
        columns.emplace_back(lineData.substr(75, 11));
        columns.emplace_back(lineData.substr(86, 9));
        columns.emplace_back(lineData.substr(95, 1));
        columns.emplace_back(lineData.substr(96, 3));
        columns.emplace_back(lineData.substr(99, 1));
        columns.emplace_back(lineData.substr(100, 12));
        columns.emplace_back(lineData.substr(112, 11));
        
        //Sanatize data:
        for (auto it = columns.begin(); it != columns.end(); it++) {
            char removeCharecters[] = "*#";
            removeCharsFromString(*it, removeCharecters);
        }

        //Generate Isotope from data
        IsotopeData.emplace_back(
        Isotope(
            columns[0],
            std::stoi(columns[1]),
            std::stoi(columns[2]),
            std::stoi(columns[3]),
            std::stoi(columns[4]),
            columns[5],
            columns[6],
            columns[7],
            columns[8],
            std::stod(columns[9]),
            std::stod(columns[10]),
            std::stod(columns[11]),
            std::stod(columns[12]),
            columns[13],
            columns[14],
            std::stod(columns[15]),
            std::stod(columns[16]),
            columns[17],
            std::stoi(columns[18]),
            columns[19],
            std::stod(columns[20]),
            std::stod(columns[21])
        ));
        PrintIsotopeInfo(IsotopeData.back());
	}
    PrintIsotopeInfo(IsotopeData[0] );
    std::cout << "Size of isotope database:" << IsotopeData.size() << std::endl;
  	file.close();
  	
  	return 1;
}



/*
bool WriteBinaryFile()
{
	
    std::ofstream file;
	file.open ("Star.bin", std::ios::out | std::ios::binary);
    if(!file.good())
    {
    	std::cout << "File Write Error";
    }
   // std::cout << sizeof(uint32_t) << " " << sizeof (float) *4 << std::endl;
	for(int i = 0; i < Starlist.size(); ++i )
	{
		
		file.write ((char*)&Starlist[i].ID, sizeof(uint32_t) ) ;
		file.write ((char*)&Starlist[i].Parallax, sizeof (float) );
		file.write ((char*)&Starlist[i].RA, sizeof(float) );
		file.write ((char*)&Starlist[i].DE, sizeof(float) );
		file.write ((char*)&Starlist[i].ApparentMagnitude, sizeof(float) );
		file.write ((char*)&Starlist[i].BV, sizeof(float) );
		
	}    	
    file.close();
	return 1;
}
*/

