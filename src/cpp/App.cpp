#include "App.h"

#include <fstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLSLProgram.h>
#include <Model.h>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

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
        printf("Vertex shader failed to compile! %s\n", shaderProgram->log().c_str());
        delete shaderProgram;
        exit(1);
    }

    if (!shaderProgram->compileShaderFromFile(shaderFSSource, GL_FRAGMENT_SHADER))
    {
        printf("Fragment shader failed to compile! %s\n", shaderProgram->log().c_str());
        delete shaderProgram;
        exit(1);
    }

    if (!shaderProgram->link())
    {
        printf("Shader program failed to link! %s\n", shaderProgram->log().c_str());
        delete shaderProgram;
        exit(1);
    }

    shaderProgram->printActiveUniforms();
    shaderProgram->printActiveAttribs();

    return shaderProgram;
}

int main()
{
    GLFWwindow* window;

    if (!glfwInit())
        exit(1);

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
        exit(1);
    }

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK)
        exit(1);

    shader = setupShader("src/glsl/cube.vs", "src/glsl/cube.fs");
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

    exit(0);
}
