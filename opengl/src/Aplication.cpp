#include <GLFW/glfw3.h>
#pragma region myscripts
#include "classes/drawing.h"
#include "classes/utils.h"
#pragma endregion



#include <iostream>
#include <cmath>

float newrotation = 0.0f;
float newrotation2 = 0.0f;
float newposns = 0.0f;
float newposew = 0.0f;
float newposud = 0.0f;

drawing drawi;

// Function to handle errors
void errorCallback(int error, const char* description) {
    std::cerr << "Error: " << description << std::endl;
}

// Manual replacement for gluPerspective
void setPerspective(float fovY, float aspect, float nearPlane, float farPlane) {
    float fH = tan(fovY / 360.0f * 3.14159f) * nearPlane;
    float fW = fH * aspect;
    glFrustum(-fW, fW, -fH, fH, nearPlane, farPlane);
}

//input
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_E && action == GLFW_REPEAT || key == GLFW_KEY_E && action == GLFW_PRESS) {
        newrotation = 0.1f;
    }
    else if(key == GLFW_KEY_Q && action == GLFW_REPEAT|| key == GLFW_KEY_Q && action == GLFW_PRESS) {
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

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Set error callback
    glfwSetErrorCallback(errorCallback);

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(720, 540, "3D", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);
    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    // Main loop
    while (!glfwWindowShouldClose(window)) {

       
        glfwSetKeyCallback(window, key_callback);

        // Clear the screen and the depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set up the projection
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        setPerspective(60.0f, 800.0f / 600.0f, 0.1f, 100.0f); 



       

        // Set up the model view
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        static float posns = 0.0f;
        static float posew = 0.0f;
        static float posud = 0.0f;
        posns += newposns;
        posew += newposew;
        posud += newposud;

        glTranslatef(posew, posud, posns);
        
        static float rotation = 0.0f;
        static float rotation2 = 0.0f;
        glRotatef(rotation, 0.0f, 0.1f, 0.0f);
        glRotatef(rotation2, 0.1f, 0.0f, 0.0f);
        rotation += newrotation; 
        rotation2 += newrotation2; 


        utils::Vector3 offset = utils::Vector3();
        offset.x = 0;
        offset.y = 0;
        offset.z = -5;

        drawi.drawpyramid(-0.125,0.7,0.9,offset);
        drawi.drawcube(0.5, -0.5, 0.5, -0.5, 0.5, -0.5,offset);
        drawi.drawprism(0.5, -0.5, 0.5, -0.5, 0.5, -0.5,offset);

        glfwSwapBuffers(window);


        glfwPollEvents();
    }


    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
