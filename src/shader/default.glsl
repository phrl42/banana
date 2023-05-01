#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in int aTextureID;

out vec4 vertexColor;
out vec2 vertexTexCoords;

void main()
{
  vertexColor = vec4(aColor, 1.0);
  gl_Position = vec4(aPos, 1.0);
  //vertexTexCoords = aTexCoords;
}

#version 330 core

out vec4 FragColor;

in vec4 vertexColor;
in vec2 vertexTexCoords;

//uniform sampler2D endTexture[8];

void main()
{
  FragColor = vertexColor;
}