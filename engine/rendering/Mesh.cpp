#include <glad/glad.h> // holds all OpenGL type declarations

#include "Mesh.h"

namespace PalmEngine
{
    Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, const Material material)
    {
        mVertices = vertices;
        mIndices = indices;
        mMaterial = material;

        // Set the vertex buffers and its attribute pointers
        SetupMesh();
    }

    void Mesh::Draw(Shader& _shader)
    {
        glActiveTexture(GL_TEXTURE0 + 0);
        // Set the sampler to the correct texture unit
        glUniform1i(glGetUniformLocation(_shader.mID, "texture_albedo"), 0);
        // Bind the texture
        glBindTexture(GL_TEXTURE_2D, mMaterial.mAlbedoTexture.mID);

        glActiveTexture(GL_TEXTURE0 + 1);
        // Set the sampler to the correct texture unit
        glUniform1i(glGetUniformLocation(_shader.mID, "texture_normal"), 1);
        // Bind the texture
        glBindTexture(GL_TEXTURE_2D, mMaterial.mNormalTexture.mID);

        // Draw mesh
        glBindVertexArray(mVAO);
        glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(mIndices.size()), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        // Always good practice to set everything back to defaults once configured.
        glActiveTexture(GL_TEXTURE0);
    }

    void Mesh::SetupMesh()
    {
        // Create buffers/arrays
        glGenVertexArrays(1, &mVAO);
        glGenBuffers(1, &_VBO);
        glGenBuffers(1, &_EBO);

        glBindVertexArray(mVAO);
        // Load data into vertex buffers
        glBindBuffer(GL_ARRAY_BUFFER, _VBO);
        // A great thing about structs is that their memory layout is sequential for all its items.
        // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
        // Again translates to 3/2 floats which translates to a byte array.
        glBufferData(GL_ARRAY_BUFFER, mVertices.size() * sizeof(Vertex), &mVertices[0], GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, mIndices.size() * sizeof(unsigned int), &mIndices[0], GL_STATIC_DRAW);

        // Set the vertex attribute pointers
        // Vertex Positions
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        // Vertex normals
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, mNormal));
        // Vertex texture coords
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, mTexCoords));
        // Vertex tangent
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, mTangent));
        // Vertex bitangent
        glEnableVertexAttribArray(4);
        glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, mBitangent));
        // IDs
        glEnableVertexAttribArray(5);
        glVertexAttribIPointer(5, 4, GL_INT, sizeof(Vertex), (void*)offsetof(Vertex, mBoneIDs));

        // Weights
        glEnableVertexAttribArray(6);
        glVertexAttribPointer(6, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, mWeights));
        glBindVertexArray(0);
    }
}