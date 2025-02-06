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
	bool usebackculling = false;
	void drawentity() {

		if (usebackculling) {
			
			drawen.drawfromfile(position);
		}
		else
		{
			glDisable(GL_CULL_FACE);
			drawen.drawfromfile(position);
			glEnable(GL_CULL_FACE);
		}
		
		//drawen.drawfromfile(position);
		
	}
	entityobject(utils::Vector3 position) {

		this->position = position;
		
	}
	
};