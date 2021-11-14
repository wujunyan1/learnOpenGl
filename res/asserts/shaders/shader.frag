#version 330 core
in vec4 vertexColor;
in vec2 TexCoord;
in vec3 Normal;
in vec3 WorldPos;

out vec4 FragColor;

uniform vec3 ambientColor;
uniform sampler2D ourTexture;
uniform vec3 lightPos;

void main()
{
    // Ambient
    float ambientStrength = 0.1f;
    vec3 ambient = ambientStrength * ambientColor;

    // Diffuse 
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - WorldPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * ambientColor;

    //FragColor = vertexColor;
    FragColor = vec4((ambient + diffuse), 1.0) * texture(ourTexture, TexCoord);
}