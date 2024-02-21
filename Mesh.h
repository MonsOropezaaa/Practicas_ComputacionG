#pragma once
#include<glew.h>
class Mesh
{
public:
	Mesh();
	void CreateMesh(GLfloat *vertices,unsigned int *indices, unsigned int numOfVertices, unsigned int numberOfIndices);
	void RenderMesh();
	void ClearMesh();
	~Mesh();
private:
	GLuint VAO, VBO, IBO; //ibo index buffer
	//se van a utilizar �ndices, con los indices vamos a reusar 
	GLsizei indexCount;

};
class MeshColor
{
public:
	MeshColor();
	void CreateMeshColor(GLfloat *vertices, unsigned int numOfVertices);
	void RenderMeshColor();
	void ClearMeshColor();
	~MeshColor();
private:
	GLuint VAO, VBO, IBO;
	GLsizei  vertexCount;
};

