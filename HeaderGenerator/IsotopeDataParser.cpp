#include "IsotopeDataParser.hpp"

#include <iostream>
#include <fstream>

#include "StringManipulators.hpp"

namespace IsotopeConst
{
    const int MAX_CHARS_PER_LINE = 200;
    const int LINES_TILL_DATA = 39;

    std::vector<Isotope> IsotopeData;

    bool ReadAtomicMass(std::string FilePath) {
        std::cout << "In fucntion readatomic mass" << std::endl;
        //Buffers	
        char buffer[MAX_CHARS_PER_LINE];
        std::vector<std::string> columns; // Holds data in columns


        std::ifstream file;
        file.open(FilePath.c_str()); // open a file
        if (!file.good()) {
            std::cout << "FILE NOT FOUND" << std::endl;
            return 0; // exit if file not found
        }



        //Advance pass header:
        for (int i = 1; i <= LINES_TILL_DATA; i++) {
            file.getline(buffer, MAX_CHARS_PER_LINE);
        }

        while (!file.eof())
        {

            //Clears columns data
            columns.clear();
            columns.reserve(24);

            file.getline(buffer, MAX_CHARS_PER_LINE);

            //Turn into columns
            std::string lineData = std::string(buffer);

            if (ParseLineData(lineData, columns)) {
                AddIsotope(columns);
            }

        }
        PrintIsotopeInfo(IsotopeData[0]);
        std::cout << "Size of isotope database:" << IsotopeData.size() << std::endl;
        file.close();

        return 1;
    }

    bool ParseLineData(std::string &lineData, std::vector<std::string> &columns) {
        if (!lineData.empty()) {
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
                char removeCharecters[] = "*# ";
                removeCharsFromString(*it, removeCharecters);
            }
            return true;
        }
        return false;
    }

    bool AddIsotope(std::vector<std::string> &columns) {
        //Generate Isotope from data
        IsotopeData.emplace_back(
            Isotope(
                columns[0],
                StringToInt(columns[1]),
                StringToInt(columns[2]),
                StringToInt(columns[3]),
                StringToInt(columns[4]),
                columns[5],
                columns[6],
                columns[7],
                columns[8],
                StringToDouble(columns[9]),
                StringToDouble(columns[10]),
                StringToDouble(columns[11]),
                StringToDouble(columns[12]),
                columns[13],
                columns[14],
                StringToDouble(columns[15]),
                StringToDouble(columns[16]),
                columns[17],
                StringToInt(columns[18]),
                columns[19],
                StringToDouble(columns[20]),
                StringToDouble(columns[21])
            ));
        //PrintIsotopeInfo(IsotopeData.back());
        return true;
    }
}