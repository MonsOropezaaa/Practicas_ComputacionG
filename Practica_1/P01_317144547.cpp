#include <stdio.h>
#include <string.h>
#include <glew.h>
#include <glfw3.h>
#include <corecrt_math.h>
#include <cstdlib> 
#include <ctime>
#include <math.h>

//2024
//Dimensiones de la ventana
const int WIDTH = 800, HEIGHT = 600;
GLuint VAO, VBO, EBO, RBO, ABO,AO,G1, G2,G3, G4, G5, O1, O2, O3, O4, O5, O6, S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, shader;

//Vertex Shader
//recibir color, salida Vcolor
static const char* vShader = "						\n\
#version 330										\n\
layout (location =0) in vec3 pos;					\n\
void main()											\n\
{													\n\
gl_Position=vec4(pos.x,pos.y,pos.z,2.0f); 			\n\
}";
//recibir Vcolor y dar de salida color
static const char* fShader = "						\n\
#version 330										\n\
out vec4 color;										\n\
void main()											\n\
{													\n\
	color = vec4(1.0f,0.0f,0.0f,1.0f);	 			\n\
}";




void CrearTriangulo()
{
	GLfloat vertices[] = {

		//LETRA G
		-2.0f, 0.8f, 0.0f,
		-2.0f, -0.8f, 0.0f,
		-1.8f, -0.8f, 0.0f,

		-2.0f, 0.8f, 0.0f,
		-1.8f, -0.8f, 0.0f,
		-1.8f, 0.80f, 0.0f,
		//
		-1.8f, 0.80f, 0.0f,
		-1.2f, 0.8f, 0.0f,
		-1.2, 0.6f, 0.0f,

		-1.8f, 0.80f, 0.0f,
		-1.2, 0.6f, 0.0f,
		-1.8f, 0.6f, 0.0f,
		//
		-1.8f, -0.6f, 0.0f,
		-1.8f, -0.8f, 0.0f, 
		-0.9f, -0.8f, 0.0f,

		-1.8f, -0.6f, 0.0f,
		-0.9f, -0.8f, 0.0f,
		-0.9f, -0.6, 0.0f,
		//

		-1.5f, -.25f,0.0f,
		-1.5f, -0.45f, 0.0f,
		-0.9f, -0.25f, 0.0f,
		
		-0.9f, -0.25f, 0.0f,
		-0.9f, -0.45f, 0.0f, 
		-1.5f, -0.45f, 0.0f,

		//
		-1.1f, -0.25f, 0.0f,
		-1.1f, -0.8f, 0.0f,
		-0.9f, -0.25f, 0.0f,

		-1.1f, -0.8f, 0.0f,
		-0.9f, -0.25f, 0.0f,
		-0.9f, -0.8f, 0.0f,

		//LETRA O

		/*r*/ -0.6f, 0.8f, 0.0f,
		/*s*/ -0.4f, 0.8f, 0.0f,
		/*q*/-0.6f, -0.8f, 0.0f,

		/*s*/ -0.4f, 0.8f, 0.0f,
		/*q*/-0.6f, -0.8f, 0.0f,
		/*t*/ -0.4f, -0.8f, 0.0f,

		/*r*/ -0.6f, 0.8f, 0.0f,
		/*w*/ -0.6f, 0.6f, 0.0f,
		/*u*/  0.4f, 0.8f, 0.0f,

		/*w*/ -0.6f, 0.6f, 0.0f,
		/*u*/  0.4f, 0.8f, 0.0f,
		/*v*/ 0.4f, 0.6f, 0.0f,

		/*q*/-0.6f, -0.8f, 0.0f,
		/*b1*/-0.6f, -0.6f, 0.0f,
		/*a1*/0.4f, -0.6f, 0.0f,

		/*q*/-0.6f, -0.8f, 0.0f,
		/*a1*/0.4f, -0.6f, 0.0f,
		/*z*/0.4f, -0.8f, 0.0f,

		/*u*/  0.4f, 0.8f, 0.0f,
		/*z*/  0.4f, -0.8f, 0.0f,
		/*d1*/ 0.2f, 0.8f, 0.0f,

		/*z*/  0.4f, -0.8f, 0.0f,
		/*d1*/ 0.2f, 0.8f, 0.0f,
		/*c1*/ 0.2f, -0.8f, 0.0f,

	//LETRA  S

		/*f1*/ 0.8f, 0.8f, 0.0f,
		/*g1*/1.8f, 0.8f, 0.0f,
		/*e1*/0.8f, 0.6f, 0.0f,

		/*g1*/1.8f, 0.8f, 0.0f,
		/*e1*/0.8f, 0.6f, 0.0f,
		/*h1*/ 1.8f, 0.6f, 0.0f,

		/*f1*/ 0.8f, 0.8f, 0.0f,
		/*i1*/0.8f, 0.0f, 0.0f,
		/*j1*/ 1.0f, 0.0f, 0.0f,

		/*f1*/ 0.8f, 0.8f, 0.0f,
		/*j1*/ 1.0f, 0.0f, 0.0f,
		/*k1*/ 1.0f, 0.8f, 0.0f,

		/*n1*/0.8f, 0.2f, 0.0f,
		/*i1*/0.8f, 0.0f, 0.0f,
		/*l1*/1.8f, 0.2f, 0.0f,

		/*i1*/0.8f, 0.0f, 0.0f,
		/*l1*/1.8f, 0.2f, 0.0f,
		/*m1*/1.8f, 0.0f, 0.0f,

		/*l1*/1.8f, 0.2f, 0.0f,
		/*q1*/1.6f, 0.2f, 0.0f,
		/*o1*/1.6f, -0.8f, 0.0f,

		/*l1*/1.8f, 0.2f, 0.0f,
		/*o1*/1.6f, -0.8f, 0.0f,
		/*p1*/1.8f, -0.8f, 0.0f,

		/*p1*/1.8f, -0.8f, 0.0f,
		/*s1*/ 0.8f, -0.8f, 0.0f,
		/*r1*/ 0.8f, -0.6f, 0.0f,

		/*p1*/1.8f, -0.8f, 0.0f,
		/*r1*/ 0.8f, -0.6f, 0.0f,
		/*t1*/1.8f, -0.6f, 0.0f


	};
	glGenVertexArrays(1, &VAO); //generar 1 VAO
	glBindVertexArray(VAO);//asignar VAO

	//primer triagulo
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); //pasarle los datos al VBO asignando tamano, los datos y en este caso es estático pues no se modificarán los valores


	//segundo triangulo
	glGenBuffers(2, &EBO);
	glBindBuffer(GL_ARRAY_BUFFER, EBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//tercer triangulo
	glGenBuffers(3, &RBO);
	glBindBuffer(GL_ARRAY_BUFFER, RBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//cuarto triangulo
	glGenBuffers(4, &ABO);
	glBindBuffer(GL_ARRAY_BUFFER, ABO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	
	glGenBuffers(5, &AO);
	glBindBuffer(GL_ARRAY_BUFFER, AO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(6, &G1);
	glBindBuffer(GL_ARRAY_BUFFER, G1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(7, &G2);
	glBindBuffer(GL_ARRAY_BUFFER, G2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(8, &G3);
	glBindBuffer(GL_ARRAY_BUFFER, G3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(9, &G4);
	glBindBuffer(GL_ARRAY_BUFFER, G4);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(10, &G5);
	glBindBuffer(GL_ARRAY_BUFFER, G5);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//LETRA O
	glGenBuffers(11, &O1);
	glBindBuffer(GL_ARRAY_BUFFER, O1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(12, &O2);
	glBindBuffer(GL_ARRAY_BUFFER, O2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(13, &O3);
	glBindBuffer(GL_ARRAY_BUFFER, O3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(14, &O4);
	glBindBuffer(GL_ARRAY_BUFFER, O4);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(15, &O5);
	glBindBuffer(GL_ARRAY_BUFFER, O5);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(16, &O6);
	glBindBuffer(GL_ARRAY_BUFFER, O6);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//LETRA S

	glGenBuffers(17, &S1);
	glBindBuffer(GL_ARRAY_BUFFER, S1);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(18, &S2);
	glBindBuffer(GL_ARRAY_BUFFER, S2);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(14, &S3);
	glBindBuffer(GL_ARRAY_BUFFER, S3);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(15, &S4);
	glBindBuffer(GL_ARRAY_BUFFER, S4);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(16, &S5);
	glBindBuffer(GL_ARRAY_BUFFER, S5);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(17, &S6);
	glBindBuffer(GL_ARRAY_BUFFER, S6);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(18, &S7);
	glBindBuffer(GL_ARRAY_BUFFER, S7);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(19, &S8);
	glBindBuffer(GL_ARRAY_BUFFER, S8);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(20, &S9);
	glBindBuffer(GL_ARRAY_BUFFER, S9);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenBuffers(21, &S0);
	glBindBuffer(GL_ARRAY_BUFFER, S0);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);//Stride en caso de haber datos de color por ejemplo, es saltar cierta cantidad de datos
	glEnableVertexAttribArray(0);
	//agregar valores a vèrtices y luego declarar un nuevo vertexAttribPointer
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType) //Función para agregar los shaders a la tarjeta gráfica
//the Program recibe los datos de theShader


{
	GLuint theShader = glCreateShader(shaderType);//theShader es un shader que se crea de acuerdo al tipo de shader: vertex o fragment
	const GLchar* theCode[1];
	theCode[0] = shaderCode;//shaderCode es el texto que se le pasa a theCode
	GLint codeLength[1];
	codeLength[0] = strlen(shaderCode);//longitud del texto
	glShaderSource(theShader, 1, theCode, codeLength);//Se le asigna al shader el código
	glCompileShader(theShader);//Se comila el shader
	GLint result = 0;
	GLchar eLog[1024] = { 0 };
	//verificaciones y prevención de errores
	glGetShaderiv(theShader, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al compilar el shader %d es: %s \n", shaderType, eLog);
		return;
	}
	glAttachShader(theProgram, theShader);//Si no hubo problemas se asigna el shader a theProgram el cual asigna el código a la tarjeta gráfica
}

void CompileShaders() {
	shader = glCreateProgram(); //se crea un programa
	if (!shader)
	{
		printf("Error creando el shader");
		return;
	}
	AddShader(shader, vShader, GL_VERTEX_SHADER);//Agregar vertex shader
	AddShader(shader, fShader, GL_FRAGMENT_SHADER);//Agregar fragment shader
	//Para terminar de linkear el programa y ver que no tengamos errores
	GLint result = 0;
	GLchar eLog[1024] = { 0 };
	glLinkProgram(shader);//se linkean los shaders a la tarjeta gráfica
	//verificaciones y prevención de errores
	glGetProgramiv(shader, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al linkear es: %s \n", eLog);
		return;
	}
	glValidateProgram(shader);
	glGetProgramiv(shader, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shader, sizeof(eLog), NULL, eLog);
		printf("EL error al validar es: %s \n", eLog);
		return;
	}

}

float generarAleatorio(float min, float max) {
	return min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
}

int main()
{
	//Inicialización de GLFW
	if (!glfwInit())
	{
		printf("Falló inicializar GLFW");
		glfwTerminate();
		return 1;
	}
	//Asignando variables de GLFW y propiedades de ventana
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//para solo usar el core profile de OpenGL y no tener retrocompatibilidad
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//CREAR VENTANA
	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Primer ventana", NULL, NULL);

	if (!mainWindow)
	{
		printf("Fallo en crearse la ventana con GLFW");
		glfwTerminate();
		return 1;
	}
	//Obtener tamaño de Buffer
	int BufferWidth, BufferHeight;
	glfwGetFramebufferSize(mainWindow, &BufferWidth, &BufferHeight);

	//asignar el contexto
	glfwMakeContextCurrent(mainWindow);

	//permitir nuevas extensiones
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("Falló inicialización de GLEW");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	// Asignar valores de la ventana y coordenadas
	//Asignar Viewport
	glViewport(0, 0, BufferWidth, BufferHeight);

	//Crear tríangulo
	CrearTriangulo();
	CompileShaders();
	float rojo = 0.0f;
	float azul = 0.0f;
	float verde = 0.0f;
	float tiempoUltimoCambio = glfwGetTime();
	float intervaloCambio = 2.0f;
	
	//Loop mientras no se cierra la ventana
	while (!glfwWindowShouldClose(mainWindow))
	{
		float tiempoActual = glfwGetTime();
		float tiempoDesdeUltimoCambio = tiempoActual - tiempoUltimoCambio;

		// Si ha pasado el intervalo de cambio de color, actualizar los colores
		if (tiempoDesdeUltimoCambio >= intervaloCambio)
		{
			tiempoUltimoCambio = tiempoActual;

			// Generar valores aleatorios para los componentes de color entre 0 y 1
			rojo = generarAleatorio(0.0f, 1.0f);
			verde = generarAleatorio(0.0f, 1.0f);
			azul = generarAleatorio(0.0f, 1.0f);
		}
		//Recibir eventos del usuario
		glfwPollEvents();
		//Limpiar la ventana
		glClearColor(rojo, verde, azul, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shader);

		glBindVertexArray(VAO);

		//LETRA G
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawArrays(GL_TRIANGLES, 3, 6);
		glDrawArrays(GL_TRIANGLES, 6, 9);
		glDrawArrays(GL_TRIANGLES, 9, 12);
		glDrawArrays(GL_TRIANGLES, 12, 15);
		glDrawArrays(GL_TRIANGLES, 15, 18);
		glDrawArrays(GL_TRIANGLES, 18, 21);
		glDrawArrays(GL_TRIANGLES, 21, 24);
		glDrawArrays(GL_TRIANGLES, 24, 27);
		glDrawArrays(GL_TRIANGLES, 27, 30);

		//LETRA O
		glDrawArrays(GL_TRIANGLES, 30, 33);
		glDrawArrays(GL_TRIANGLES, 33, 36);
		glDrawArrays(GL_TRIANGLES, 36, 39);
		glDrawArrays(GL_TRIANGLES, 39, 42);
		glDrawArrays(GL_TRIANGLES, 42, 45);
		glDrawArrays(GL_TRIANGLES, 45, 48);

		//LETRA S
		glDrawArrays(GL_TRIANGLES, 48, 51);
		glDrawArrays(GL_TRIANGLES, 51, 54);
		glDrawArrays(GL_TRIANGLES, 54, 57);
		glDrawArrays(GL_TRIANGLES, 57, 60);
		glDrawArrays(GL_TRIANGLES, 60, 63);
		glDrawArrays(GL_TRIANGLES, 63, 66);
		glDrawArrays(GL_TRIANGLES, 66, 69);
		glDrawArrays(GL_TRIANGLES, 69, 72);
		glDrawArrays(GL_TRIANGLES, 72, 75);
		glDrawArrays(GL_TRIANGLES, 75, 78);


		glBindVertexArray(0);

		glUseProgram(0);

		glfwSwapBuffers(mainWindow);

	}
	return 0;
}