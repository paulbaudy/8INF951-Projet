// Include GLFW
#include <glfw3.h>

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include "PhysicalObject.h"

#include "MovableObject.h"

MovableObject::MovableObject(const char* path, glm::vec3 objcolor, GLuint fragShader, GLFWwindow* Objwindow) : PhysicalObject(path, objcolor, fragShader, Objwindow) { }

void MovableObject::fix_vertex() {
	// TODO transform normals obj ....
	m_OBB.transform(ModelMatrix);

	// Ignore first object
	for (int i = 1; i < m_objects.size(); i++) {
		if (m_OBB.collides(m_objects[i]->m_OBB)) {
			m_OBB.restore();
			translated = translated_old;
			return;
		}
	}

	for (int i = 0; i < geometric_vertex.size(); i++) {
		geometric_vertex[i] = ModelMatrix * geometric_vertex[i];
	}
}

void MovableObject::setObjects(std::vector<PhysicalObject*> _objects) {
	m_objects = _objects;
}


void MovableObject::applyTransformsFromControls() {
	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS) {
		applyTranslation(glm::vec3(0, 0, 0.2));
	}else if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS) {
		applyTranslation(glm::vec3(0, 0, -0.2));
	}else if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS) {
		applyTranslation(glm::vec3(-0.2, 0, 0));
	}else if(glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS) {
		applyTranslation(glm::vec3(0.2 ,0, 0));
	}else if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS) {
		applyRotation(-2, 0, 0);
	}else if (glfwGetKey(window, GLFW_KEY_SEMICOLON) == GLFW_PRESS) {
		applyRotation(2, 0, 0);
	}else if (glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS) {
		applyRotation(0, 2, 0);
	}else if (glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS) {
		applyRotation(0, -2, 0);
	}else if (glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS) {
		applyRotation(0, 0, -2);
	}else if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS) {
		applyRotation(0, 0, 2);
	}

	//Apply when click and move mouse?
	//applyRotationAroundAxis

	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
		applyScale(glm::vec3(1.2, 1.2, 1.2));
	}

	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
		applyScale(glm::vec3(0.8, 0.8, 0.8));
	}

	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
		applyReflection(glm::vec3(0, 1, 0));
	}

	if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS) {
		applyShearingYZ(1.2, -0.5);
	}

	if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS) {
		applyShearingYZ(-1.2, 0.5);
	}

	if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS) {
		applyShearOrNot(true);
	}

	if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS) {
		applyShearOrNot(false);
	}
}
