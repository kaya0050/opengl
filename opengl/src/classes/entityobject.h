#pragma once
#pragma region myscripts
#include "drawing.h"
#include "utils.h"
#include "physics.h"
#include "filehandler.h"
#pragma endregion
class entityobject
{
	drawing drawen;
	
public:
	utils::Vector3 position;
	int size = 1;
	bool alive = true;
	void drawentity() {
		
		glRotatef(0.0001f, 0.0f, 0.1f, 0.0f);
		glRotatef(0.0001f, 0.1f, 0.0f, 0.0f);
		drawen.drawfromfile(position);
	}
	entityobject(utils::Vector3 position) {

		this->position = position;
		
	}
	
};