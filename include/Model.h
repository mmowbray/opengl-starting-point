#pragma once

#include<string>
#include <glad/glad.h>
#include <glm/mat4x4.hpp>

class Model{
private:
    GLuint VAO, positionsVBO, normalsVBO;
    unsigned int vertexCount;
    glm::mat4 modelMatrix;
public:
    Model(const std::string & fileName);
    void update();
    void draw();
    glm::mat4& getModelMatrix();
};
