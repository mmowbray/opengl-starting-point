#pragma once

#include <glm/vec3.hpp>

class OBJLoader {

public:
    static void loadOBJ(const std::string &source, std::vector<glm::vec3> & vertices, std::vector<glm::vec3> & normals);

};
