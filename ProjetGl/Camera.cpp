#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "transformation_mat.h"
#include "Camera.h"


Camera::Camera()
{
	position = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	speed = 0.1f;
}

void Camera::execute(GLFWwindow *window)
{
	glm::vec3 cartesian_dir = glm::vec3(1, 0, 0);
	glm::vec3 cartesian_dir_right = glm::vec3(0, 0, 1);

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
		position = translation(cartesian_dir * speed, position);
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
		position = translation(-cartesian_dir * speed, position);
	}

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		position = translation(cartesian_dir_right * speed, position);
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		position = translation(-cartesian_dir_right * speed, position);
	}

	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS) {
		cartesian_dir = rotation_x(60.0f, position);
	}

	CamViewMatrice = glm::lookAt(glm::vec3(position), glm::vec3(position) + cartesian_dir, glm::vec3(0,1,0));

	projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);

}

Camera::~Camera()
{

}
