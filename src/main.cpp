/*
 * main.cpp
 *
 *  Created on: 24/07/2013
 *      Author: cabellos
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#define GL_GLEXT_PROTOTYPES 1
#define GL3_PROTOTYPES 1
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glext.h>

#include "shader.hpp"

int main(){
	sf::ContextSettings desired;
	desired.majorVersion = 3;
	desired.minorVersion = 3;

    GLuint vertexArrayID;
    glGenVertexArrays( 1, &vertexArrayID );
    glBindVertexArray( vertexArrayID );

    sf::RenderWindow window{
    	sf::VideoMode(800, 600),
    	"HexWorld", sf::Style::Default, desired };
    window.setVerticalSyncEnabled( true );

    auto settings = window.getSettings();

    std::cout << "depth bits: " << settings.depthBits << std::endl;
    std::cout << "stencil bits: " << settings.stencilBits << std::endl;
    std::cout << "antialiasing level: " << settings.antialiasingLevel << std::endl;
    std::cout << "version: " << settings.majorVersion << "." << settings.minorVersion << std::endl;

    sf::Font font;
    if( !font.loadFromFile( "GentiumPlus-R.ttf") ){
    	std::cout << "Error loading Font\n";
    	std::terminate();
    }

    sf::Text text;
    text.setFont( font );
    text.setString( "Hex World" );
    text.setCharacterSize( 18 );
    text.setColor( sf::Color::White );
    text.setStyle( sf::Text::Bold );

    // An array of 3 vectors which represents 3 vertices
    static const GLfloat g_vertex_buffer_data[] = {
       -1.0f, -1.0f, 0.0f,
       1.0f, -1.0f, 0.0f,
       0.0f,  1.0f, 0.0f,
    };

    // This will identify our vertex buffer
    GLuint vertexbuffer;

    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &vertexbuffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint programID = loadProgram( "test01" );

    bool running = true;
    while( running ){
        sf::Event event;
        while( window.pollEvent(event) ){
            if( event.type == sf::Event::Closed ){
                running = false;
            }else if(event.type == sf::Event::Resized){
                // adjust the viewport when the window is resized
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        //window.clear();
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        glUseProgram( programID );

        // 1rst attribute buffer : vertices
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
           0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
           3,                  // size
           GL_FLOAT,           // type
           GL_FALSE,           // normalized?
           0,                  // stride
           (void*)0            // array buffer offset
        );

        // Draw the triangle !
        glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
        glDisableVertexAttribArray(0);
        glBindBuffer( GL_ARRAY_BUFFER, 0 );

        window.pushGLStates();
        //window.resetGLStates();

        window.draw( text );

        window.popGLStates();

        window.display();
    }

    return 0;
}
