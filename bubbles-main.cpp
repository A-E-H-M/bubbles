// g++ -c main.cpp
// g++ main.o -o sfml-main -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
// ./sfml-main

#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char * argv[]){
	// Create a new window of size w*h pixels
	// Top-left of the window is (0,0) and bottom-right is (w,h)
	const int wWidth = 1280;
	const int wHeight = 720;
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
	window.setFramerateLimit(60);

	// Make a shape that will draw to the screen
	sf::CircleShape circle(50);					// Create a circle shape with radius 50
	circle.setFillColor(sf::Color::Green);		// Set the circle color to green
	circle.setPosition(300.0f, 300.0f);			// Set the top-left position of the circle
	float circleMoveSpeed = 1.0f;				// Use this to move the circle later
	

	/*
	// Load a font to display some text	
	sf::Font myFont;

	// Attempt to load the font from a file
	if (!myFont.loadFromFile("arial.ttf"))	// Get a font file for this example!!
	{
		// If font file does not load, print an error message to the error console and exit
			std::cerr << "Could not load font!\n";
			exit(-1);
	}
	
	// Set up the text object that will be drawn to the screen
	sf::Text text("Sample Text", myFont, 24);

	// Position the top-left corner of the text so that the text aligns on the bottom
	// Text character size is in pixels, so move the text up from the bottom by its height
	text.setPosition(0, wHeight - (float)text.getCharacterSize());
	*/


	// Main loop - continues for each frame while window is open
	while (window.isOpen())
	{
		// Event handling
		sf::Event event;
		while(window.pollEvent(event))
		{
			// This event triggers when the window is closed
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			// This event is triggered when a key is pressed
			if (event.type == sf::Event::KeyPressed)
			{
				// Print the key that was pressed to the console
				std::cout << "Key pressed with code = " << event.key.code << "\n";
					
				// Create an event when 'x' is pressed
				if (event.key.code == sf::Keyboard::X)
				{
					// Reverse the direction of the circle on the screen
					circleMoveSpeed *= -1.0f;
				}
			}
		}

		// Basic animation - move each frame if it's still in frame
		circle.setPosition(circle.getPosition().x + circleMoveSpeed, circle.getPosition().y + circleMoveSpeed);

		// Basic rendering function calls -- double buffering under the hood with OpenGL
		window.clear();
		window.draw(circle);
		//window.draw(text);
		window.display();	
	}
}
