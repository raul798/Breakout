#version 330 core

// Ouput data
out vec4 color;

uniform float time;

in vec4 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;

void main()
{
	color = texture(texture1, TexCoord) * ourColor;
}