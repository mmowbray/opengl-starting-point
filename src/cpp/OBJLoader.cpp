#include <string>
#include <fstream>

#include "OBJLoader.h"

#include "glm/glm.hpp"
#include <string.h>

void OBJLoader::loadOBJ(const std::string &source, std::vector<glm::vec3> & vertices, std::vector<glm::vec3> & normals) {
    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<glm::vec3> temp_vertices;
    std::vector<glm::vec2> temp_uvs;
    std::vector<glm::vec3> temp_normals;

    std::ifstream objFile;
    objFile.open(source);

    if (!objFile.is_open()){
        printf("Cannot open model! Are you in the right path ?\n");
        getchar();
        return;
    }

    std::string line;

    while (std::getline(objFile, line)) {

        if(line.length() > 0) {

            if (strcmp(line.substr(0, 2).c_str(), "v ") == 0){
                glm::vec3 vertex;
                sscanf(line.c_str(), "v %f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
                temp_vertices.push_back(vertex);
            }
            else if (strcmp(line.substr(0, 3).c_str(), "vn ") == 0){
                glm::vec3 normal;
                sscanf(line.c_str(), "vn %f %f %f\n", &normal.x, &normal.y, &normal.z);
                temp_normals.push_back(normal);
            }
            else if (strcmp(line.substr(0, 2).c_str(), "f ") == 0){
                std::string vertex1, vertex2, vertex3;
                unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
                int matches = sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]);
                if (matches != 9){
                    printf("File can't be read by our simple parser :-( Try exporting with other options\n");
                    return;
                }
                vertexIndices.push_back(vertexIndex[0]);
                vertexIndices.push_back(vertexIndex[1]);
                vertexIndices.push_back(vertexIndex[2]);
                normalIndices.push_back(normalIndex[0]);
                normalIndices.push_back(normalIndex[1]);
                normalIndices.push_back(normalIndex[2]);
            }
        }
    }

    objFile.close();

    // For each vertex of each triangle
    for (unsigned int i = 0; i<vertexIndices.size(); i++){

        // Get the indices of its attributes
        unsigned int vertexIndex = vertexIndices[i];
        unsigned int normalIndex = normalIndices[i];

        // Get the attributes thanks to the index
        glm::vec3 vertex = temp_vertices[vertexIndex - 1];
        glm::vec3 normal = temp_normals[normalIndex - 1];

        // Put the attributes in buffers
        vertices.push_back(vertex);
        normals.push_back(normal);
    }
}
