#version 330 core

out vec4 oFragment;

in vec2 VertXY;

uniform vec2 WidthHeight;

void main(){

    vec2 uv = VertXY * 2;
    float asspect = WidthHeight.x / WidthHeight.y;
    uv.x *= asspect;

    oFragment = vec4(1.0);
    float distance = 1 - length(uv);

    distance = smoothstep(0.0, 0.01, distance);
    oFragment = vec4(distance);

}
