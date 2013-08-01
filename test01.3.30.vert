#version 330 core

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec3 vertexColor;
uniform mat4 MVP;

out vec3 fragmentColor;

void main(){
    vec4 v = vec4( vertexPosition, 1 );
    gl_Position = MVP * v;
    fragmentColor = vertexColor;
}
