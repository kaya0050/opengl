#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#pragma region myscripts
#include "classes/drawing.h"
#include "classes/utils.h"
#include "classes/physics.h"
#include "classes/filehandler.h"
#include "classes/entityobject.h"
#pragma endregion

float newrotation = 0.0f;
float newrotation2 = 0.0f;
float newposns = 0.0f;
float newposew = 0.0f;
float newposud = 0.0f;

bool once = false;

drawing drawi;
utils uti;
physics phy;
filehandler files;

utils::Vector3 entitypos;

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
        newrotation = 1;
    }
    else if(key == GLFW_KEY_Q && action == GLFW_REPEAT|| key == GLFW_KEY_Q && action == GLFW_PRESS) {
        newrotation = -1;
    }
    else
    {
        newrotation = 0.0f;
    }

    if (key == GLFW_KEY_R && action == GLFW_REPEAT || key == GLFW_KEY_R && action == GLFW_PRESS) {
        newrotation2 = 1;
    }
    else if (key == GLFW_KEY_F && action == GLFW_REPEAT || key == GLFW_KEY_F && action == GLFW_PRESS) {
        newrotation2 = -1;
    }
    else
    {
        newrotation2 = 0.0f;
    }


    if (key == GLFW_KEY_W && action == GLFW_REPEAT || key == GLFW_KEY_W && action == GLFW_PRESS) {
        newposns = 0.05f;
    }
    else if (key == GLFW_KEY_S && action == GLFW_REPEAT || key == GLFW_KEY_S && action == GLFW_PRESS) {
        newposns = -0.05f;
    }
    else
    {
        newposns = 0.0f;
    }

    if (key == GLFW_KEY_A && action == GLFW_REPEAT || key == GLFW_KEY_A && action == GLFW_PRESS) {
        newposew = 0.05f;
    }
    else if (key == GLFW_KEY_D && action == GLFW_REPEAT || key == GLFW_KEY_D && action == GLFW_PRESS) {
        newposew = -0.05f;
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
    GLFWwindow* window = glfwCreateWindow(1280, 800, "3D", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_LOCK_KEY_MODS, GLFW_TRUE);

    // Enable depth testing
    glEnable(GL_DEPTH_TEST);

    std::vector<utils::Vector3> offsets(1000);
    for (int i = 0; i < 1000; i++) {
        offsets[i].x = uti.randomFloat(-50.0f, 50.0f);
        offsets[i].y = uti.randomFloat(-50.0f, 50.0f);
        offsets[i].z = uti.randomFloat(-50.0f, 50.0f);
    }
    std::vector<utils::Vector3> offsetsphy(2);

    for (int i = 0; i < 2; i++) {
        offsetsphy[i].x = uti.randomFloat(-10, 10);
        offsetsphy[i].y = uti.randomFloat(-10, 10);
        offsetsphy[i].z = uti.randomFloat(-10, 10);
    }
    //fh.writefile();
    
    entityobject entity(entitypos);

    fh.readline("3dmodel.txt");
    //Main loop
    while (!glfwWindowShouldClose(window)) 
    {
        
        glfwPollEvents();
        glfwSetKeyCallback(window, key_callback);

        // Clear the screen and the depth buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Set up the projection
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        setPerspective(50.0f, 1280.0f / 800.0f, 0.1f, 1000.0f); 


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

        entitypos.x += 000.1f;

        //rotation += 0.001f;
        //rotation2 += 0.001f;
        //phy.Update(offsetsphy);

        drawi.drawcube(0.5f, -0.5f, 0.5f, -0.5f, 0.5f, -0.5f, offsetsphy[0]);
        drawi.drawcube(0.5f, -0.5f, 0.5f, -0.5f, 0.5f, -0.5f, offsetsphy[1]);

        drawi.drawfromfile(offsets[0]);

 

        entity.drawentity();

        for (const auto& offset : offsets) {
            drawi.drawcube(0.5f, -0.5f, 0.5f, -0.5f, 0.5f, -0.5f, offset);
        }
        

        //drawi.drawpyramid(0,1,1,offset);
        //drawi.drawcube(0.5, -0.5, 0.5, -0.5, 0.5, -0.5,offset);

        //drawi.drawprism(0.5, -0.5, 0.5, -0.5, 0.5, -0.5,offset);
        glfwSwapBuffers(window);


        
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
int test() {

    return 0;
}