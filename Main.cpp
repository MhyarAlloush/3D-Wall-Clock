// GLProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <learnopengl/shader_m.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "Polygon.cpp"

using namespace glm;

int width = 800;
int height = 800;

vec3 cameraPos = vec3(5.0f, 0.0f, 0.0f);    
vec3 cameraFront = vec3(-1.0f, 0.0f, 0.0f); 
vec3 cameraUp = vec3(0.0f, 1.0f, 0.0f);

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
    const float cameraSpeed = 0.005f; 
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        cameraPos += cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        cameraPos -= cameraSpeed * cameraFront;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        cameraPos -= normalize(cross(cameraFront, cameraUp)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        cameraPos += normalize(cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		cameraPos += cross(cameraFront,normalize(cross(cameraFront, cameraUp))) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		cameraPos -= cross(cameraFront, normalize(cross(cameraFront, cameraUp))) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		mat4 rotationMatrix = glm::rotate(mat4(1.0f), 0.001f, vec3(0.0f, 1.0f, 0.0f));
		vec4 rotatedVectorHomogeneous = rotationMatrix * vec4(cameraFront, 1.0f);
		cameraFront = vec3(rotatedVectorHomogeneous);
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		mat4 rotationMatrix = glm::rotate(mat4(1.0f), 0.001f, vec3(0.0f, -1.0f, 0.0f));
		vec4 rotatedVectorHomogeneous = rotationMatrix * vec4(cameraFront, 1.0f);
		cameraFront = vec3(rotatedVectorHomogeneous);
	}
}


int main()
{

	glfwInit();
	GLFWwindow* window = glfwCreateWindow(width, height, "Lecture 3", NULL, NULL);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	glEnable(GL_DEPTH_TEST);

	Shader ourShader("./shaders/vs/L3.vs", "./shaders/fs/L3.fs");



	//1-->6 صندوق الساعة
	std::vector<vec3> vertices1 = {};
	vertices1.push_back(vec3(0.5f, -0.75f, -0.5));
	vertices1.push_back(vec3(0.5f, -0.75f, 0.5));
	vertices1.push_back(vec3(0.5f, 0.75f, 0.5f));
	vertices1.push_back(vec3(0.5f, 0.75f, -0.5f));
	Polygon Polygon1 = Polygon(vertices1, vec3(0.20f, 0.15f, 0.10f));

	std::vector<vec3> vertices2 = {};
	vertices2.push_back(vec3(0.0f, -0.75f, -0.5));
	vertices2.push_back(vec3(0.0f, -0.75f, 0.5));
	vertices2.push_back(vec3(0.0f, 0.75f, 0.5f));
	vertices2.push_back(vec3(0.0f, 0.75f, -0.5f));
	Polygon Polygon2 = Polygon(vertices2, vec3(0.20f, 0.15f, 0.10f));

	std::vector<vec3> vertices3 = {};
	vertices3.push_back(vec3(0.0f, 0.75f, -0.5f));
	vertices3.push_back(vec3(0.5f, 0.75f, -0.5f));
	vertices3.push_back(vec3(0.5f, -0.75f, -0.5f));
	vertices3.push_back(vec3(0.0f, -0.75f, -0.5f));
	Polygon Polygon3 = Polygon(vertices3, vec3(0.20f, 0.15f, 0.10f));

	std::vector<vec3> vertices4 = {};
	vertices4.push_back(vec3(0.0f, 0.75f, 0.5f));
	vertices4.push_back(vec3(0.5f, 0.75f, 0.5f));
	vertices4.push_back(vec3(0.5f, -0.75f, 0.5f));
	vertices4.push_back(vec3(0.0f, -0.75f, 0.5f));
	Polygon Polygon4 = Polygon(vertices4, vec3(0.20f, 0.15f, 0.10f));

	std::vector<vec3> vertices5 = {};
	vertices5.push_back(vec3(0.0f, 0.75f, -0.5f));
	vertices5.push_back(vec3(0.5f, 0.75f, -0.5f));
	vertices5.push_back(vec3(0.5f, 0.75f, 0.5f));
	vertices5.push_back(vec3(0.0f, 0.75f, 0.5f));
	Polygon Polygon5 = Polygon(vertices5, vec3(0.20f, 0.15f, 0.10f));

	std::vector<vec3> vertices6 = {};
	vertices6.push_back(vec3(0.0f, -0.75f, -0.5f));
	vertices6.push_back(vec3(0.5f, -0.75f, -0.5f));
	vertices6.push_back(vec3(0.5f, -0.75f, 0.5f));
	vertices6.push_back(vec3(0.0f, -0.75f, 0.5f));
	Polygon Polygon6 = Polygon(vertices6, vec3(0.20f, 0.15f, 0.10f));

	//مربع الساعة
	std::vector<vec3> vertices7 = {};
	vertices7.push_back(vec3(0.501f, -0.10f, -0.40f));
	vertices7.push_back(vec3(0.501f, -0.10f, 0.40f));
	vertices7.push_back(vec3(0.501f, 0.70f, 0.40f));
	vertices7.push_back(vec3(0.501f, 0.70f, -0.40f));
	Polygon Polygon7 = Polygon(vertices7, vec3(1.0f, 1.0f, 1.0f));

	//مركز الساعة
	std::vector<vec3> vertices8 = {};
	vertices8.push_back(vec3(0.502f, 0.32f, -0.02f));
	vertices8.push_back(vec3(0.502f, 0.32f, 0.02f));
	vertices8.push_back(vec3(0.502f, 0.28f, 0.02f));
	vertices8.push_back(vec3(0.502f, 0.28f, -0.02f));
	Polygon Polygon8 = Polygon(vertices8, vec3(0.0f, 0.0f, 0.0f));

	//عقرب الساعات 
	std::vector<vec3> vertices9 = {};
	vertices9.push_back(vec3(0.5021f, 0.30f, 0.02f));
	vertices9.push_back(vec3(0.5021f, 0.30f, -0.02f));
	vertices9.push_back(vec3(0.5021f, 0.34f, -0.15f));
	vertices9.push_back(vec3(0.5021f, 0.35f, -0.15f));
	Polygon Polygon9 = Polygon(vertices9, vec3(0.0f, 0.0f, 0.0f));
	//عقرب الدقائق
	std::vector<vec3> vertices10 = {};
	vertices10.push_back(vec3(0.503f, 0.30f, 0.02f));
	vertices10.push_back(vec3(0.503f, 0.30f, -0.02f));
	vertices10.push_back(vec3(0.503f, 0.41f, 0.20f));
	vertices10.push_back(vec3(0.503f, 0.40f, 0.20f));
	Polygon Polygon10 = Polygon(vertices10, vec3(0.0f, 0.0f, 0.0f));
	//عقرب الثواني
	std::vector<vec3> vertices25 = {};
	vertices25.push_back(vec3(0.504f, 0.30f, 0.01f));
	vertices25.push_back(vec3(0.504f, 0.30f, -0.01f));
	vertices25.push_back(vec3(0.504f, 0.55f, 0.00f));
	vertices25.push_back(vec3(0.504f, 0.55f, 0.01f));
	Polygon Polygon25 = Polygon(vertices25, vec3(1.0f, 0.0f, 0.0f));


	//12
	std::vector<vec3> vertices11 = {};
	vertices11.push_back(vec3(0.512f, 0.70f, -0.02f));
	vertices11.push_back(vec3(0.512f, 0.70f, 0.02f));
	vertices11.push_back(vec3(0.512f, 0.63f, 0.02f));
	vertices11.push_back(vec3(0.512f, 0.63f, -0.02f));
	Polygon Polygon11 = Polygon(vertices11, vec3(0.0f, 0.0f, 0.0f));
	//6
	std::vector<vec3> vertices12 = {};
	vertices12.push_back(vec3(0.512f, -0.03f, -0.02f));
	vertices12.push_back(vec3(0.512f, -0.03f, 0.02f));
	vertices12.push_back(vec3(0.512f, -0.10f, 0.02f));
	vertices12.push_back(vec3(0.512f, -0.10f, -0.02f));
	Polygon Polygon12 = Polygon(vertices12, vec3(0.0f, 0.0f, 0.0f));
	//11
	std::vector<vec3> vertices13 = {};
	vertices13.push_back(vec3(0.512f, 0.70f, 0.24f));
	vertices13.push_back(vec3(0.512f, 0.70f, 0.22f));
	vertices13.push_back(vec3(0.512f, 0.65f, 0.22f));
	vertices13.push_back(vec3(0.512f, 0.65f, 0.24f));
	Polygon Polygon13 = Polygon(vertices13, vec3(0.0f, 0.0f, 0.0f));
	//1
	std::vector<vec3> vertices14 = {};
	vertices14.push_back(vec3(0.512f, 0.70f, -0.24f));
	vertices14.push_back(vec3(0.512f, 0.70f, -0.22f));
	vertices14.push_back(vec3(0.512f, 0.65f, -0.22f));
	vertices14.push_back(vec3(0.512f, 0.65f, -0.24f));
	Polygon Polygon14 = Polygon(vertices14, vec3(0.0f, 0.0f, 0.0f));


	//7
	std::vector<vec3> vertices15 = {};
	vertices15.push_back(vec3(0.512f, -0.05f, 0.24f));
	vertices15.push_back(vec3(0.512f, -0.05f, 0.22f));
	vertices15.push_back(vec3(0.512f, -0.10f, 0.22f));
	vertices15.push_back(vec3(0.512f, -0.10f, 0.24f));
	Polygon Polygon15 = Polygon(vertices15, vec3(0.0f, 0.0f, 0.0f));
	//5
	std::vector<vec3> vertices16 = {};
	vertices16.push_back(vec3(0.512f, -0.05f, -0.24f));
	vertices16.push_back(vec3(0.512f, -0.05f, -0.22f));
	vertices16.push_back(vec3(0.512f, -0.10f, -0.22f));
	vertices16.push_back(vec3(0.512f, -0.10f, -0.24f));
	Polygon Polygon16 = Polygon(vertices16, vec3(0.0f, 0.0f, 0.0f));

	//3
	std::vector<vec3> vertices17 = {};
	vertices17.push_back(vec3(0.512f, 0.32f, -0.40f));
	vertices17.push_back(vec3(0.512f, 0.32f, -0.33f));
	vertices17.push_back(vec3(0.512f, 0.28f, -0.33f));
	vertices17.push_back(vec3(0.512f, 0.28f, -0.40f));
	Polygon Polygon17 = Polygon(vertices17, vec3(0.0f, 0.0f, 0.0f));

	//2
	std::vector<vec3> vertices18 = {};
	vertices18.push_back(vec3(0.512f, 0.54f, -0.40f));
	vertices18.push_back(vec3(0.512f, 0.54f, -0.35f));
	vertices18.push_back(vec3(0.512f, 0.52f, -0.35f));
	vertices18.push_back(vec3(0.512f, 0.52f, -0.40f));
	Polygon Polygon18 = Polygon(vertices18, vec3(0.0f, 0.0f, 0.0f));
	//4
	std::vector<vec3> vertices19 = {};
	vertices19.push_back(vec3(0.512f, 0.08f, -0.40f));
	vertices19.push_back(vec3(0.512f, 0.08f, -0.35f));
	vertices19.push_back(vec3(0.512f, 0.06f, -0.35f));
	vertices19.push_back(vec3(0.512f, 0.06f, -0.40f));
	Polygon Polygon19 = Polygon(vertices19, vec3(0.0f, 0.0f, 0.0f));

	//9
	std::vector<vec3> vertices20 = {};
	vertices20.push_back(vec3(0.512f, 0.32f, 0.40f));
	vertices20.push_back(vec3(0.512f, 0.32f, 0.33f));
	vertices20.push_back(vec3(0.512f, 0.28f, 0.33f));
	vertices20.push_back(vec3(0.512f, 0.28f, 0.40f));
	Polygon Polygon20 = Polygon(vertices20, vec3(0.0f, 0.0f, 0.0f));

	//10
	std::vector<vec3> vertices21 = {};
	vertices21.push_back(vec3(0.512f, 0.54f, 0.40f));
	vertices21.push_back(vec3(0.512f, 0.54f, 0.35f));
	vertices21.push_back(vec3(0.512f, 0.52f, 0.35f));
	vertices21.push_back(vec3(0.512f, 0.52f, 0.40f));
	Polygon Polygon21 = Polygon(vertices21, vec3(0.0f, 0.0f, 0.0f));
	//8
	std::vector<vec3> vertices22 = {};
	vertices22.push_back(vec3(0.512f, 0.08f, 0.40f));
	vertices22.push_back(vec3(0.512f, 0.08f, 0.35f));
	vertices22.push_back(vec3(0.512f, 0.06f, 0.35f));
	vertices22.push_back(vec3(0.512f, 0.06f, 0.40f));
	Polygon Polygon22 = Polygon(vertices22, vec3(0.0f, 0.0f, 0.0f));

	//النواس
	std::vector<vec3> vertices23 = {};
	vertices23.push_back(vec3(0.25f, -0.70f, -0.03f));
	vertices23.push_back(vec3(0.25f, -0.70f, 0.03f));
	vertices23.push_back(vec3(0.25f, -1.40f, 0.03f));
	vertices23.push_back(vec3(0.25f, -1.40f, -0.03f));
	Polygon Polygon23 = Polygon(vertices23, vec3(0.35f, 0.24f, 0.18f));

	//صندوق النواس
	std::vector<vec3> vertices24 = {};
	vertices24.push_back(vec3(0.251f, -1.20, -0.10f));
	vertices24.push_back(vec3(0.251f, -1.20, 0.10f));
	vertices24.push_back(vec3(0.251f, -1.40f, 0.10f));
	vertices24.push_back(vec3(0.251f, -1.40f, -0.10f));
	Polygon Polygon24 = Polygon(vertices24, vec3(0.20f, 0.15f, 0.10f));

	std::vector<vec3> vertices26 = {};
	vertices26.push_back(vec3(0.220f, -1.20, -0.10f));
	vertices26.push_back(vec3(0.220f, -1.20, 0.10f));
	vertices26.push_back(vec3(0.220f, -1.40f, 0.10f));
	vertices26.push_back(vec3(0.220f, -1.40f, -0.10f));
	Polygon Polygon26 = Polygon(vertices26, vec3(0.20f, 0.15f, 0.10f));

	std::vector<vec3> vertices27 = {};
	vertices27.push_back(vec3(0.220f, -1.20f, -0.10f));
	vertices27.push_back(vec3(0.251f, -1.20f, -0.10f));
	vertices27.push_back(vec3(0.251f, -1.40f, -0.10f));
	vertices27.push_back(vec3(0.220f, -1.40f, -0.10f));
	Polygon Polygon27 = Polygon(vertices27, vec3(0.20f, 0.15f, 0.10f));

	std::vector<vec3> vertices28 = {};
	vertices28.push_back(vec3(0.220f, -1.20f, 0.10f));
	vertices28.push_back(vec3(0.251f, -1.20f, 0.10f));
	vertices28.push_back(vec3(0.251f, -1.40f, 0.10f));
	vertices28.push_back(vec3(0.220f, -1.40f, 0.10f));
	Polygon Polygon28 = Polygon(vertices28, vec3(0.20f, 0.15f, 0.10f));

	std::vector<vec3> vertices29 = {};
	vertices29.push_back(vec3(0.220f, -1.40f, -0.10f));
	vertices29.push_back(vec3(0.251f, -1.40f, -0.10f));
	vertices29.push_back(vec3(0.251f, -1.40f, 0.10f));
	vertices29.push_back(vec3(0.220f, -1.40f, 0.10f));
	Polygon Polygon29 = Polygon(vertices29, vec3(0.20f, 0.15f, 0.10f));




	ourShader.use();
	
	mat4 projection = mat4(1.0f);
	projection = perspective(radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
	ourShader.setMat4("projection", projection);

	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		mat4 view = lookAt(cameraPos, cameraPos + cameraFront, cameraUp);

		
		ourShader.setMat4("view", view);
		
				
		Polygon1.draw(ourShader);

		Polygon2.draw(ourShader);

		Polygon3.draw(ourShader);

		Polygon4.draw(ourShader);

		Polygon5.draw(ourShader);

		Polygon6.draw(ourShader);

		Polygon7.draw(ourShader);

		Polygon8.draw(ourShader);

		Polygon9.draw(ourShader);

		Polygon10.draw(ourShader);

		Polygon11.draw(ourShader);

		Polygon12.draw(ourShader);

		Polygon13.draw(ourShader);

		Polygon14.draw(ourShader);

		Polygon15.draw(ourShader);

		Polygon16.draw(ourShader);

		Polygon17.draw(ourShader);

		Polygon18.draw(ourShader);

		Polygon19.draw(ourShader);

		Polygon20.draw(ourShader);

		Polygon21.draw(ourShader);

		Polygon22.draw(ourShader);

		Polygon23.draw(ourShader);

		Polygon24.draw(ourShader);

		Polygon25.draw(ourShader);

		Polygon26.draw(ourShader);

		Polygon27.draw(ourShader);

		Polygon28.draw(ourShader);

	    Polygon29.draw(ourShader);


		//لاهتزاز النواس 
		float swing = sin(glfwGetTime() * 3.14159f) * 0.3f;
		mat4 pendulumTransform = translate(mat4(1.0f), vec3(0.25f, -0.70f, 0.0f));
		pendulumTransform = rotate(pendulumTransform, swing, vec3(1.0f, 0.0f, 0.0f));
		pendulumTransform = translate(pendulumTransform, vec3(-0.25f, 0.70f, 0.0f));
		Polygon23.transformation(pendulumTransform);
		Polygon24.transformation(pendulumTransform);
		Polygon26.transformation(pendulumTransform);
		Polygon27.transformation(pendulumTransform);
		Polygon28.transformation(pendulumTransform);
		Polygon29.transformation(pendulumTransform);


		float testTime = glfwGetTime();
		float secondAngle = testTime * 6.0f;
		float minuteAngle = testTime * 0.1f; 
		float hourAngle = testTime * 0.008333f;  
		secondAngle = radians(secondAngle);
		minuteAngle = radians(minuteAngle);
		hourAngle = radians(hourAngle);

		vec3 pivotCenter = vec3(0.0f, 0.30f, 0.0f);
		vec3 handOffset = vec3(0.0f, -0.30f, 0.0f);

		//عقرب الساعات
		mat4 hourTransform = translate(mat4(1.0f), pivotCenter);
		hourTransform = rotate(hourTransform, hourAngle, vec3(-0.01f, 0.0f, 0.0f));
		hourTransform = translate(hourTransform, handOffset);
		Polygon9.transformation(hourTransform);

		// عقرب الدقايق 
		mat4 minuteTransform = translate(mat4(1.0f), pivotCenter);
		minuteTransform = rotate(minuteTransform, minuteAngle, vec3(-0.01f, 0.0f, 0.0f));
		minuteTransform = translate(minuteTransform, handOffset);
		Polygon10.transformation(minuteTransform);

		// عقرب الثواني
		mat4 secondTransform = translate(mat4(1.0f), pivotCenter);
		secondTransform = rotate(secondTransform, secondAngle, vec3(-0.01f, 0.0f, 0.0f));
		secondTransform = translate(secondTransform, handOffset);
		Polygon25.transformation(secondTransform);




		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

