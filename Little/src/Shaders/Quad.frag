#version 330 core

out vec4 oFragment;

uniform vec3 color;

void main(){
    oFragment = vec4(color, 1.0f);
}