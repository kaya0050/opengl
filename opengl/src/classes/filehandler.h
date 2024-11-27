#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "utils.h"
using namespace std;
class filehandler
{
public:
	int pointcount;
	vector<string> points;
	vector<utils::Vector3> vecpoints;
	void writefile() {

		ofstream MyWriteFile("3dmodel.txt");

#pragma region demo write
		/*
		MyWriteFile << "0" << endl;
		MyWriteFile << "1" << endl;
		MyWriteFile << "0" << endl;

		MyWriteFile << "1" << endl;
		MyWriteFile << "0" << endl;
		MyWriteFile << "-1" << endl;

		MyWriteFile << "-1" << endl;
		MyWriteFile << "0" << endl;
		MyWriteFile << "-1" << endl;


		MyWriteFile << "0" << endl;
		MyWriteFile << "1" << endl;
		MyWriteFile << "0" << endl;

		MyWriteFile << "1" << endl;
		MyWriteFile << "0" << endl;
		MyWriteFile << "1" << endl;

		MyWriteFile << "-1" << endl;
		MyWriteFile << "0" << endl;
		MyWriteFile << "1" << endl;


		MyWriteFile << "0" << endl;
		MyWriteFile << "1" << endl;
		MyWriteFile << "0" << endl;

		MyWriteFile << "1" << endl;
		MyWriteFile << "0" << endl;
		MyWriteFile << "1" << endl;

		MyWriteFile << "1" << endl;
		MyWriteFile << "0" << endl;
		MyWriteFile << "-1" << endl;


		MyWriteFile << "0" << endl;
		MyWriteFile << "1" << endl;
		MyWriteFile << "0" << endl;

		MyWriteFile << "-1" << endl;
		MyWriteFile << "0" << endl;
		MyWriteFile << "1" << endl;

		MyWriteFile << "-1" << endl;
		MyWriteFile << "0" << endl;
		MyWriteFile << "-1" << endl;



		MyWriteFile << "-1" << endl;
		MyWriteFile << "0" << endl;
		MyWriteFile << "1" << endl;

		MyWriteFile << "1" << endl;
		MyWriteFile << "0" << endl;
		MyWriteFile << "1" << endl;

		MyWriteFile << "-1" << endl;
		MyWriteFile << "0" << endl;
		MyWriteFile << "-1" << endl;


		MyWriteFile << "1" << endl;
		MyWriteFile << "0" << endl;
		MyWriteFile << "1" << endl;

		MyWriteFile << "-1" << endl;
		MyWriteFile << "0" << endl;
		MyWriteFile << "-1" << endl;

		MyWriteFile << "1" << endl;
		MyWriteFile << "0" << endl;
		MyWriteFile << "-1" << endl;
		*/
#pragma endregion

		MyWriteFile.close();

	}

	void readline(string file) {

		string myText;
		
		ifstream MyReadFile(file);

		if (!MyReadFile.is_open()) {
			cout << "can not open file" << endl;

		}

		while (getline (MyReadFile, myText)) {
			points.push_back(myText);
		}

		for (size_t i = 0; i < points.size(); i++)
		{
			if (pointcount == 0) {
				utils::Vector3 vecie;
			}
			if (pointcount == 3) {
				pointcount = 0;
			}
			cout << points[i] << endl;

			pointcount += 1;
		}

		MyReadFile.close();

	}
};