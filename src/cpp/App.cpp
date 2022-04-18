#include "App.h"

#include <fstream>
#include <format>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GLSLProgram.h>
#include <Model.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

GLSLProgram *shader;
Model *cube;


void framebuffer_size_callback(GLFWwindow*, int new_screen_width, int new_screen_height)
{
    glViewport(0, 0, new_screen_width, new_screen_height);
}

GLSLProgram* setupShader(const char* shaderVSSource, const char* shaderFSSource)
{
    GLSLProgram* shaderProgram = new GLSLProgram();

    if(!shaderProgram->compileShaderFromFile(shaderVSSource, GL_VERTEX_SHADER))
    {
        cout << "Vertex shader failed to compile!" <<  shaderProgram->log().c_str() << endl;
        delete shaderProgram;
        return NULL;
    }

    if (!shaderProgram->compileShaderFromFile(shaderFSSource, GL_FRAGMENT_SHADER))
    {
        cout << "Fragment shader failed to compile! " <<  shaderProgram->log().c_str() << endl; 
        delete shaderProgram;
        return NULL;
    }

    if (!shaderProgram->link())
    {
        std::cout << "Shader program failed to link! " << shaderProgram->log().c_str() << endl;
        delete shaderProgram;
        return NULL;
    }

    shaderProgram->printActiveUniforms();
    shaderProgram->printActiveAttribs();

    return shaderProgram;
}

int main()
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    window = glfwCreateWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }  

    shader = setupShader("src/glsl/cube.vs", "src/glsl/cube.fs");
    if(shader == NULL)
        return -1;
    cube = new Model("assets/models/cube.obj");

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        shader->use();
        cube->draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}
