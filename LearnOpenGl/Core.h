#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// C 运行时头文件
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <string>
#include <map>

#include "base/TypeDef.h"

namespace Core 
{
	typedef glm::vec3			Vector3;
	typedef glm::vec4			Vector4;
	typedef glm::mat4			Mat4;
	typedef glm::mat3			Mat3;

	typedef std::string			String;

	class Camera;
}

