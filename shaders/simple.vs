#version 330 core

layout(location=0) in vec3 vPos;
layout(location=1) in vec3 vColor;

uniform mat4 MVP;

out vec3 fragementColor;

void main() {
    gl_Position = MVP*vec4(vPos, 1);
    
    fragementColor = vColor;
}
