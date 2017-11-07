#pragma once

#include<string>
#include <GL/glew.h>
#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_mat4x4.hpp>

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
