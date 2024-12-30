#include "OpenGLRenderer.h"

#include <QFile>
#include <QTextStream>

unsigned int shaderProgram;
unsigned int VAO;

// Main Flow
void OpenGLRenderer::initialize() {
    initializeOpenGLFunctions();

    QFile vertFile(":/shaders/vert.shader");
    if (!vertFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open vertex shader:" << vertFile.fileName();
    }
    QTextStream vertStream(&vertFile);
    std::string vertexShaderString = vertStream.readAll().toStdString();
    const char* vertexShaderSource = vertexShaderString.c_str();
    vertFile.close();
    
    QFile fragFile(":/shaders/frag.shader");
    if (!fragFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Failed to open fragment shader:" << fragFile.fileName();
    }
    QTextStream fragStream(&fragFile);
    std::string fragmentShaderString = fragStream.readAll().toStdString();
    const char* fragmentShaderSource = fragmentShaderString.c_str();
    fragFile.close();

    // set up shaders
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        qDebug() << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog;
    }
    // fragment shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    // check for shader compile errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        qDebug() << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog;
    }
    // link shaders
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        qDebug() << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // set up buffers
    float vertices[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
        -0.5f,  0.5f, 0.0f   // top left 
    };
    unsigned int indices[] = {
        0, 1, 3,  // first Triangle
        1, 2, 3   // second Triangle
    };
    unsigned int VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}
void OpenGLRenderer::resize(int w, int h) {
    glViewport(0, 0, w, h);
}

void OpenGLRenderer::render() {
    glClearColor(0.83f, 0.83f, 0.83f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    

    // draw triangle
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void OpenGLRenderer::setBlockContainer(BlockContainerWrapper* blockContainer) {
    
}

void OpenGLRenderer::setEvaluator(Evaluator* evaluator) {
    
}

void OpenGLRenderer::updateView(ViewManager* viewManager) {
    
}

ElementID OpenGLRenderer::addSelectionElement(const SelectionElement& selection) {
    return 0;
}

void OpenGLRenderer::removeSelectionElement(ElementID selection) {
    
}

ElementID OpenGLRenderer::addBlockPreview(const BlockPreview& blockPreview) {
    return 0;
}

void OpenGLRenderer::removeBlockPreview(ElementID blockPreview) {
    
}

ElementID OpenGLRenderer::addConnectionPreview(const ConnectionPreview& connectionPreview) {
    return 0;
}

void OpenGLRenderer::removeConnectionPreview(ElementID connectionPreview) {
    
}

ElementID OpenGLRenderer::addHalfConnectionPreview(const HalfConnectionPreview& halfConnectionPreview) {
    return 0;
}

void OpenGLRenderer::removeHalfConnectionPreview(ElementID halfConnectionPreview) {
    
}

void OpenGLRenderer::spawnConfetti(FPosition start) {
    
}

