//Práctica 2 semestre 2024-1: índices, mesh, proyecciones, transformaciones geométricas
#include <stdio.h>
#include <string.h>
#include<cmath>
#include<vector>
#include <glew.h>
#include <glfw3.h>
//glm
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>
//clases para dar orden y limpieza al código
#include"Mesh.h"
#include"Shader.h"
#include"Window.h"
//Dimensiones de la ventana
const float toRadians = 3.14159265f / 180.0; //grados a radianes
Window mainWindow;


std::vector<Mesh*> meshList;
std::vector<MeshColor*> meshColorList;
std::vector<Shader>shaderList;
//Vertex Shader
static const char* vShader = "shaders/shader.vert";
static const char* fShader = "shaders/shader.frag";
static const char* vShaderColor = "shaders/shadercolor.vert";
static const char* fShaderColor = "shaders/shadercolor.frag";
//shaders nuevos se crearían acá


float angulo = 0.0f;

//color café: 0.478, 0.255, 0.067

//Pirámide triangular regular
void CreaPiramide()
{
	unsigned int indices[] = {
		0,1,2,
		1,3,2,
		3,0,2,
		1,0,3

	};
	GLfloat vertices[] = {
		-0.5f, -0.5f,0.0f,	//0
		0.5f,-0.5f,0.0f,	//1
		0.0f,0.5f, -0.25f,	//2
		0.0f,-0.5f,-0.5f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices, indices, 12, 12);
	meshList.push_back(obj1);
}
//Vértices de un cubo
void CrearCubo()
{
	unsigned int cubo_indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};

	GLfloat cubo_vertices[] = {
		// front
		-0.5f, -0.5f,  0.5f,
		0.5f, -0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		// back
		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f
	};
	Mesh* cubo = new Mesh();
	cubo->CreateMesh(cubo_vertices, cubo_indices, 24, 36);
	meshList.push_back(cubo);
}

void CrearLetrasyFiguras()
{

	GLfloat vertices_letras[] = {
		//X			Y			Z			R		G		B
		-1.0f,	-1.0f,		0.5f,			0.0f,	0.0f,	1.0f,
		1.0f,	-1.0f,		0.5f,			0.0f,	0.0f,	1.0f,
		1.0f,	1.0f,		0.5f,			0.0f,	0.0f,	1.0f,
		/*1.0f,	1.0f,		0.5f,			1.0f,	0.0f,	0.0f,
		-1.0f,  1.0f,		0.5f,			1.0f,	0.0f,	0.0f,
		-1.0f,	-1.0f,		0.5f,			1.0f,	0.0f,	0.0f,*/

	};
	MeshColor* letras = new MeshColor();
	letras->CreateMeshColor(vertices_letras, 18);
	meshColorList.push_back(letras);

	GLfloat vertices_trianguloazul[] = {
		//X			Y			Z			R		G		B
		-1.0f,	-1.0f,		0.5f,			0.0f,	0.0f,	1.0f,
		1.0f,	-1.0f,		0.5f,			0.0f,	0.0f,	1.0f,
		0.0f,	1.0f,		0.5f,			0.0f,	0.0f,	1.0f,
	};
	MeshColor* trianguloazul = new MeshColor();
	trianguloazul->CreateMeshColor(vertices_trianguloazul, 18);
	meshColorList.push_back(trianguloazul);

	GLfloat vertices_triangulorojo[] = {
		//X			Y			Z			R		G		B
		-1.0f,	-1.0f,		0.5f,			1.0f,	0.0f,	0.0f,
		1.0f,	-1.0f,		0.5f,			1.0f,	0.0f,	0.0f,
		0.0f,	 1.0f,		0.5f,			1.0f,	0.0f,	0.0f
	};

	MeshColor* triangulorojo = new MeshColor();
	triangulorojo->CreateMeshColor(vertices_triangulorojo, 18);
	meshColorList.push_back(triangulorojo);

	GLfloat vertices_trianguloverde[] = {
		//X			Y			Z			R		G		B
		-1.0f,	-1.0f,		0.5f,			0.0f,	0.5f,	0.0f,
		1.0f,	-1.0f,		0.5f,			0.0f,	0.5f,	0.0f,
		0.0f,	1.0f,		0.5f,			0.0f,	0.5f,	0.0f,
	};
	MeshColor* trianguloverde = new MeshColor();
	trianguloverde->CreateMeshColor(vertices_trianguloverde, 18);
	meshColorList.push_back(trianguloverde);

	GLfloat vertices_cuadradoverde[] = {
		//X			Y			Z			R		G		B
	-0.5f,	-0.5f,		0.5f,			0.0f,	1.0f,	0.0f,
	0.5f,	-0.5f,		0.5f,			0.0f,	1.0f,	0.0f,
	0.5f,	0.5f,		0.5f,			0.0f,	1.0f,	0.0f,
	-0.5f,	-0.5f,		0.5f,			0.0f,	1.0f,	0.0f,
	0.5f,	0.5f,		0.5f,			0.0f,	1.0f,	0.0f,
	-0.5f,	0.5f,		0.5f,			0.0f,	1.0f,	0.0f,

	};
	MeshColor* cuadradoverde = new MeshColor();
	cuadradoverde->CreateMeshColor(vertices_cuadradoverde, 36);
	meshColorList.push_back(cuadradoverde);


	GLfloat vertices_cuadradorojo[] = {
		//X			Y			Z			R		G		B
	-0.5f,	-0.5f,		0.5f,			1.0f,	0.0f,	0.0f,
	0.5f,	-0.5f,		0.5f,			1.0f,	0.0f,	0.0f,
	0.5f,	0.5f,		0.5f,			1.0f,	0.0f,	0.0f,
	-0.5f,	-0.5f,		0.5f,			1.0f,	0.0f,	0.0f,
	0.5f,	0.5f,		0.5f,			1.0f,	0.0f,	0.0f,
	-0.5f,	0.5f,		0.5f,			1.0f,	0.0f,	0.0f,
	};
	MeshColor* cuadradorojo = new MeshColor();
	cuadradorojo->CreateMeshColor(vertices_cuadradorojo, 36);
	meshColorList.push_back(cuadradorojo);

	GLfloat vertices_cuadradocafe[] = {
		//X			Y			Z			R		G		B
	-0.5f,	-0.5f,		0.5f,			0.478, 0.255, 0.067,
	0.5f,	-0.5f,		0.5f,			0.478, 0.255, 0.067,
	0.5f,	0.5f,		0.5f,			0.478, 0.255, 0.067,
	-0.5f,	-0.5f,		0.5f,			0.478, 0.255, 0.067,
	0.5f,	0.5f,		0.5f,			0.478, 0.255, 0.067,
	-0.5f,	0.5f,		0.5f,			0.478, 0.255, 0.067,
	};
	MeshColor* cuadradocafe = new MeshColor();
	cuadradocafe->CreateMeshColor(vertices_cuadradocafe, 36);
	meshColorList.push_back(cuadradocafe);

}


void CreateShaders()
{
	Shader* shader1 = new Shader(); //shader para usar índices: objetos: cubo y  pirámide
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);

	Shader* shader2 = new Shader();//shader para usar color como parte del VAO: letras 
	shader2->CreateFromFiles(vShaderColor, fShaderColor);
	shaderList.push_back(*shader2);
}



int main()
{
	mainWindow = Window(800, 600);
	mainWindow.Initialise();
	CreaPiramide(); //índice 0 en MeshList
	CrearCubo();//índice 1 en MeshList
	CrearLetrasyFiguras(); //usa MeshColor, índices en MeshColorList
	CreateShaders();
	GLuint uniformProjection = 0;
	GLuint uniformModel = 0;
	//Projection: Matriz de Dimensión 4x4 para indicar si vemos en 2D( orthogonal) o en 3D) perspectiva
	glm::mat4 projection = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, 0.1f, 100.0f);
	//glm::mat4 projection = glm::perspective(glm::radians(60.0f)	,mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);

	//Model: Matriz de Dimensión 4x4 en la cual se almacena la multiplicación de las transformaciones geométricas.
	glm::mat4 model(1.0); //fuera del while se usa para inicializar la matriz con una identidad


	while (!mainWindow.getShouldClose())
	{
		//Recibir eventos del usuario
		glfwPollEvents();
		//Limpiar la ventana
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se agrega limpiar el buffer de profundidad
	
		shaderList[1].useShader();
		uniformModel = shaderList[1].getModelLocation();
		uniformProjection = shaderList[1].getProjectLocation();

		glm::mat4 model_cuadradorojo(1.0);
		model_cuadradorojo = glm::translate(model_cuadradorojo, glm::vec3(0.0f, -0.5f, -4.0f));
	    model_cuadradorojo = glm::rotate(model_cuadradorojo, angulo, glm::vec3(1.0f, 0.0f, 0.0f));
		model_cuadradorojo = glm::scale(model_cuadradorojo, glm::vec3(.91f, 1.4f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model_cuadradorojo));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[5]->RenderMeshColor();



		//cuadrado verde (ventanas y puerta)
		shaderList[1].useShader();
		uniformModel = shaderList[1].getModelLocation();
		uniformProjection = shaderList[1].getProjectLocation();

		glm::mat4 model_cuadradoverde(1.0);
		model_cuadradoverde = glm::translate(model_cuadradoverde, glm::vec3(0.0f, -0.7f, -3.5f));
		model_cuadradoverde = glm::scale(model_cuadradoverde, glm::vec3(0.4f, 0.55f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model_cuadradoverde));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[4]->RenderMeshColor();

		//////

		glm::mat4 model_cuadradoverde2(1.0);
		model_cuadradoverde2 = glm::translate(model_cuadradoverde2, glm::vec3(-0.25f, -0.1f, -3.5f));
		model_cuadradoverde2 = glm::scale(model_cuadradoverde2, glm::vec3(0.3f, 0.35f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model_cuadradoverde2));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[4]->RenderMeshColor();

		/////


		glm::mat4 model_cuadradoverde3(1.0);
		model_cuadradoverde3 = glm::translate(model_cuadradoverde3, glm::vec3(0.25f, -0.1f, -3.5f));
		model_cuadradoverde3 = glm::scale(model_cuadradoverde3, glm::vec3(0.3f, 0.35f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model_cuadradoverde3));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[4]->RenderMeshColor();

		//

	 //triángulo azul (techo)
		

		glm::mat4 model_trianguloazul(1.0);
		model_trianguloazul = glm::translate(model_trianguloazul, glm::vec3(0.0f, 0.5f, -4.0f));
		model_trianguloazul = glm::scale(model_trianguloazul, glm::vec3(0.6f, 0.35f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model_trianguloazul));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[1]->RenderMeshColor();

		// cuadrado cafe (arboles-tronco)
			//arbol uno
		
		glm::mat4 model_cuadradocafe1(1.0);
		model_cuadradocafe1 = glm::translate(model_cuadradocafe1, glm::vec3(-0.75f, -0.9f, -4.0f));
		model_cuadradocafe1 = glm::scale(model_cuadradocafe1, glm::vec3(.2f, .3f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model_cuadradocafe1));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[6]->RenderMeshColor();

		//arbol dos

		glm::mat4 model_cuadradocafe2(1.0);
		model_cuadradocafe2 = glm::translate(model_cuadradocafe2, glm::vec3(0.75f, -0.9f, -4.0f));
		model_cuadradocafe2 = glm::scale(model_cuadradocafe2, glm::vec3(.2f, .3f, 0.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model_cuadradocafe2));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[6]->RenderMeshColor();

		//triangulo verde (pinos)
		//pino uno
	
		glm::mat4 model_trianguloverde1(1.0);
		model_trianguloverde1 = glm::translate(model_trianguloverde1, glm::vec3(-0.75f, -0.4f, -3.0f));
		model_trianguloverde1 = glm::scale(model_trianguloverde1, glm::vec3(0.2f, 0.4f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model_trianguloverde1));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[3]->RenderMeshColor();

	//

		glm::mat4 model_trianguloverde2(1.0);
		model_trianguloverde2 = glm::translate(model_trianguloverde2, glm::vec3(0.75f, -0.4f, -3.0f));
		model_trianguloverde2 = glm::scale(model_trianguloverde2, glm::vec3(0.2f, 0.4f, 0.5f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model_trianguloverde2));
		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		meshColorList[3]->RenderMeshColor();


		glUseProgram(0);
		mainWindow.swapBuffers();

	}
	return 0;
}