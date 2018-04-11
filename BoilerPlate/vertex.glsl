#version 330 core

// Input vertex data (attributes)
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;


// Output vertex data
out vec4 ourColor;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main() {
	gl_Position.xyz = aPos;
	gl_Position.w = 1.0;
	gl_Position = projection * view * model * vec4(aPos, 1.0);
	ourColor = aColor;
	TexCoord = aTexCoord;
}