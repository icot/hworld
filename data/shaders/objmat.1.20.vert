#version 120

attribute vec3 vertexPosition;
uniform mat4 MVP;

void main(){
    vec4 v = vec4( vertexPosition, 1 );
    gl_Position = MVP * v;
}
