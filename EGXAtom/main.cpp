#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstring>
#include <stdint.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Isotope;

bool ReadAtomicMass(std::string FilePath);

bool ReadHip( std::string FilePath );
bool WriteBinaryFile();
bool ReadBinaryFile();

const int MAX_CHARS_PER_LINE = 124;
const int MAX_TOKENS_PER_LINE = 124;
const char* const DELIMITER = "|";

std::vector<Isotope> IsotopeData;

int main(int argc, char** argv) {
	
	std::cout << std::ios::binary << std::endl;
    IsotopeData.reserve(2000000);
	//ReadHip("Hip_test.dat");
	ReadHip("hip_main.dat");
	WriteBinaryFile();
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
        
        
        
        
        
        
        int32_t id = 0(), float parallax = 0.0, float rightAscension = 0.0, float Declination = 0.0, float apparentMagnitude = 0.0, float bv = 0.0) :
		ID( id ),
		Parallax( parallax ),
		RA( rightAscension ),
		DE( Declination ),
        ApparentMagnitude(apparentMagnitude),
		BV( bv )
	{}
};

void PrintStarInfo( const Star & star )
{
	std::cout 	<< "ID: " << star.ID
				<< " P: " << star.Parallax
				<< " RA: " << star.RA
				<< " DE: " << star.DE
				<< " Mag: " << star.ApparentMagnitude
				<< " BV: " << star.BV 
				<< std::endl;
}

bool ReadHip( std::string FilePath )
{	
  	std::ifstream file;
	file.open( FilePath.c_str() ); // open a file
  	if ( !file.good() ) 
    	return 0; // exit if file not found
    std::cout << Starlist.size() << std::endl;	
    while (!file.eof())
  	{
  		//Buffers	
  		char buffer[MAX_CHARS_PER_LINE];
  		const char* token[MAX_TOKENS_PER_LINE] = {};
  		
  		file.getline( buffer, MAX_CHARS_PER_LINE );
  		
  		int i = 0;
  		token[i] = std::strtok( buffer, DELIMITER );
  		
  		if( token[0] ) // something in line
  		{
  			for(i = 1; i < MAX_TOKENS_PER_LINE; ++i)
  			{
  				token[i] = strtok( 0, DELIMITER );
  				if( !token[i] ) break;
  			}
  		}

  		if( atof( token[5] ) > 0 ) // parallax input isnt bad
  		{
  			
  			
  			Starlist.emplace_back( 	atol( token[1] ), //id
		  							atof( token[11] ), //paralax
									atof( token[8] ), // RA
									atof( token[9] ), //DE
									atof( token[5] ), // Magnitude
									atof( token[37] ) // BV
									);
		
		//PrintStarInfo( Starlist.back() );
		}
	}
	PrintStarInfo( Starlist[0] );
  	file.close();
  	
  	return 1;
}


bool ReadTyc( std::string FilePath)
{
	
}


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

bool ReadBinaryFile()
{
	
    std::ifstream file;
	file.open ("Star.bin", std::ios::in | std::ios::binary);
	if(!file.good())
    {
    	std::cout << "File Read Error" << std::cout;
    }
    /*
	for(int i = 0; i < Starlist.size(); ++i )
	{
		
		file.write ((char*)&Starlist[i].ID, sizeof(int32_t) ) ;
		file.write ((char*)&Starlist[i].Parallax, sizeof (float) );
		file.write ((char*)&Starlist[i].RA, sizeof(double) );
		file.write ((char*)&Starlist[i].DE, sizeof(double) );
		file.write ((char*)&Starlist[i].Magnitude, sizeof(float) );
		
	}   
	*/ 	
    file.close();
	return 1;
}

