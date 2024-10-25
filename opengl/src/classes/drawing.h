#pragma once
#include <GLFW/glfw3.h>
#include "utils.h"
#include <iostream>
#include <cmath>
class drawing {


public:
    int drawcube(float R, float L, float U, float D, float F, float B,utils::Vector3 offset) {

        R += offset.x;
        L += offset.x;

        U += offset.y;
        D += offset.y;

        F += offset.z;
        B += offset.z;
        

        glBegin(GL_QUADS);
        //(LR,UD,FB)
        glColor3f(1, 0, 0);
        //frontface
        glVertex3f(R, U, F);
        glVertex3f(R, D, F);
        glVertex3f(L, D, F);
        glVertex3f(L, U, F);

        glColor3f(1, 1, 0);
        //backface
        glVertex3f(R, U, B);
        glVertex3f(R, D, B);
        glVertex3f(L, D, B);
        glVertex3f(L, U, B);

        glColor3f(0, 0, 1);
        //topface
        glVertex3f(R, U, F);
        glVertex3f(R, U, B);
        glVertex3f(L, U, B);
        glVertex3f(L, U, F);

        glColor3f(0, 1, 0);
        //bottomface
        glVertex3f(R, D, F);
        glVertex3f(R, D, B);
        glVertex3f(L, D, B);
        glVertex3f(L, D, F);

        glColor3f(1, 0, 1);
        //rightface
        glVertex3f(R, U, B);
        glVertex3f(R, D, B);
        glVertex3f(R, D, F);
        glVertex3f(R, U, F);

        glColor3f(0, 1, 1);
        //leftface
        glVertex3f(L, U, B);
        glVertex3f(L, D, B);
        glVertex3f(L, D, F);
        glVertex3f(L, U, F);

        glEnd();
        return(0);
    }

    int drawpyramid(float center,float height,float width, utils::Vector3 offset) {

        
        

        glBegin(GL_TRIANGLES);
        glColor3f(1, 0, 0);
        //(LR,UD,FB)
        glVertex3f(width + offset.x, 0 + offset.y, -width + offset.z);
        glVertex3f(-width + offset.x, 0 + offset.y, -width + offset.z);
        glVertex3f(0 + offset.x, 0 + offset.y, width + offset.z);

        glColor3f(0, 1, 0);
        //(LR,UD,FB)
        glVertex3f(width + offset.x, 0 + offset.y, -width + offset.z);
        glVertex3f(-width + offset.x, 0 + offset.y, -width + offset.z);
        glVertex3f(0 + offset.x,height + offset.y, center + offset.z);

        glColor3f(0, 0, 1);
        //(LR,UD,FB)
        glVertex3f(width + offset.x, 0 + offset.y, -width + offset.z);
        glVertex3f(0 + offset.x, 0 + offset.y, width + offset.z);
        glVertex3f(0 + offset.x,height + offset.y, center + offset.z);

        glColor3f(0, 1, 1);
        //(LR,UD,FB)
        glVertex3f(-width + offset.x, 0 + offset.y, -width + offset.z);
        glVertex3f(0 + offset.x, 0 + offset.y, width + offset.z);
        glVertex3f(0 + offset.x, height + offset.y, center + offset.z);


        glEnd();
        return(0);
    }

    int drawprism(float R, float L, float U, float D, float F, float B,utils::Vector3 offset) {
        R += offset.x;
        L += offset.x;

        U += offset.y;
        D += offset.y;

        F += offset.z;
        B += offset.z;
        glBegin(GL_QUADS);
        glColor3f(0, 1, 0);
        //bottomface
        glVertex3f(R, D, F);
        glVertex3f(R, D, B);
        glVertex3f(L, D, B);
        glVertex3f(L, D, F);

        glColor3f(1, 0, 1);
        //rightface
        glVertex3f(0 + offset.x, U, B);
        glVertex3f(R, D, B);
        glVertex3f(R, D, F);
        glVertex3f(0 + offset.x, U, F);

        glColor3f(0, 1, 1);
        //leftface
        glVertex3f(0 + offset.x, U, B);
        glVertex3f(L, D, B);
        glVertex3f(L, D, F);
        glVertex3f(0 + offset.x, U, F);

        glEnd();

        glBegin(GL_TRIANGLES);

        glColor3f(1, 0, 0);
        //(LR,UD,FB)
        glVertex3f(R , D , F);
        glVertex3f(L , D ,F);
        glVertex3f(0 + offset.x, U, F);

        glColor3f(1, 1, 0);
        //(LR,UD,FB)
        glVertex3f(R, D, B);
        glVertex3f(L, D, B);
        glVertex3f(0 + offset.x, U, B);
        glEnd();

        return(0);
    }


};

