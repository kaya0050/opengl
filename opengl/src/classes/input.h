#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

float newrotation = 0.0f;
float newrotation2 = 0.0f;
float newposns = 0.0f;
float newposew = 0.0f;
float newposud = 0.0f;
class input {
    //input
public:
    void inputs()
    {
        if (key == GLFW_KEY_E && action == GLFW_REPEAT || key == GLFW_KEY_E && action == GLFW_PRESS) {
            newrotation = 0.1f;
        }
        else if (key == GLFW_KEY_Q && action == GLFW_REPEAT || key == GLFW_KEY_Q && action == GLFW_PRESS) {
            newrotation = -0.1f;
        }
        else
        {
            newrotation = 0.0f;
        }

        if (key == GLFW_KEY_R && action == GLFW_REPEAT || key == GLFW_KEY_R && action == GLFW_PRESS) {
            newrotation2 = 0.1f;
        }
        else if (key == GLFW_KEY_F && action == GLFW_REPEAT || key == GLFW_KEY_F && action == GLFW_PRESS) {
            newrotation2 = -0.1f;
        }
        else
        {
            newrotation2 = 0.0f;
        }


        if (key == GLFW_KEY_W && action == GLFW_REPEAT || key == GLFW_KEY_W && action == GLFW_PRESS) {
            newposns = 0.005f;
        }
        else if (key == GLFW_KEY_S && action == GLFW_REPEAT || key == GLFW_KEY_S && action == GLFW_PRESS) {
            newposns = -0.005f;
        }
        else
        {
            newposns = 0.0f;
        }

        if (key == GLFW_KEY_A && action == GLFW_REPEAT || key == GLFW_KEY_A && action == GLFW_PRESS) {
            newposew = 0.005f;
        }
        else if (key == GLFW_KEY_D && action == GLFW_REPEAT || key == GLFW_KEY_D && action == GLFW_PRESS) {
            newposew = -0.005f;
        }
        else
        {
            newposew = 0.0f;
        }

        if (key == GLFW_KEY_X && action == GLFW_REPEAT || key == GLFW_KEY_X && action == GLFW_PRESS) {
            newposud = -0.005f;
        }
        else if (key == GLFW_KEY_Z && action == GLFW_REPEAT || key == GLFW_KEY_Z && action == GLFW_PRESS) {
            newposud = 0.005f;
        }
        else
        {
            newposud = 0.0f;
        }

    }
};
