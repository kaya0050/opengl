#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include <list>
#pragma region myscripts
#include "drawing.h"
#include "utils.h"
#pragma endregion
class physics
{
	float minDistance = 0.1f;
	float maxDistance = 10;
	bool once = false;
	//std::list<utils::Vector3> positions;

	utils uti = utils();
public:
	void calculatePoints(std::vector<utils::Vector3> offsets) {
		
		for (int i = 0; i < offsets.size(); i++) {
			for (int j = 0; j < offsets.size(); j++) {
				//niet dezelfde index
				if (i != j) {  
					float distance = offsets[i].distanceTo(offsets[j]);
					if (distance < maxDistance && distance > minDistance) {
						std::cout << "\033[" << 32 << "m";
						std::cout << "in range" << std::endl;
					}
					else if (distance > maxDistance) {
						std::cout << "\033[" << 31 << "m";
						std::cout << "too far" << std::endl;
						
					}
					else if (distance < minDistance) {
						std::cout << "\033[" << 33 << "m";
						std::cout << "too close" << std::endl;
					}
				}
			}
		}		
	}
	void colision() {

	}
};

