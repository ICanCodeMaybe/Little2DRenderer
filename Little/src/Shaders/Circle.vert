#version 330 core

layout(location = 0) in vec3 aPos;

out vec2 VertXY;
out vec3 color;

uniform mat4 vp;
uniform mat4 model;
uniform vec3 inColor;

void main(){
    gl_Position = vp * model * vec4(aPos, 1.0);

    VertXY = aPos.xy;
    color = inColor;
}