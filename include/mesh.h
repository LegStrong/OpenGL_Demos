#ifndef _BENGINE_MESH_H_
#define _BENGINE_MESH_H_

#include <glm/vec3.hpp>
#include <vector>


namespace BEngine {
class Mesh{
    public:
        Mesh();
        void SetVetices(std::vector<glm::vec3> vertices);

};

}

#endif
