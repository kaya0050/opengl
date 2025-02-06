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
	float minDistance = 1;
	float maxDistance = 10;
	bool once = false;
	//std::list<utils::Vector3> positions;

	utils uti = utils();
public:
	std::vector<utils::Vector3> calculatePoints(std::vector<utils::Vector3> offsets) {
		
		for (int i = 0; i < offsets.size(); i++) {
			for (int j = 0; j < offsets.size(); j++) {
				//niet dezelfde index
				if (i != j) {  
					float distance = offsets[i].distanceTo(offsets[j]);
					if (distance < maxDistance && distance > minDistance) {
						std::cout << "\033[" << 32 << "m";
						std::cout << "in range" << std::endl;
					}
					if (distance > maxDistance) {
						std::cout << "\033[" << 31 << "m";
						std::cout << "too far" << std::endl;
						offsets[i].x = ((offsets[j].x + offsets[i].x) / 2);
						offsets[i].y = ((offsets[j].y + offsets[i].y) / 2);
						offsets[i].z = ((offsets[j].z + offsets[i].z) / 2);

					}
					if (distance < minDistance) {
						std::cout << "\033[" << 33 << "m";
						std::cout << "too close" << std::endl;
						offsets[i].x += 1;
						offsets[i].y += 1;
						offsets[i].z += 1;

					}
				}
			}
		}
		return offsets;
	}
	void colision() {

	}
};

