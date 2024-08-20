// This program generates a window and renders circles within the window. Using keyboard inputs
// you can change the direction of the circles.
// 
// SFML (Simple and Fast Multimedia Library) - Copyright (c) Laurent Gomila
// SFML libraries and source code are distributed under the zlib/png license.

#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <vector>

using namespace sf;

int main(int argc, char * argv[]){
	
	// Configuration for window, circles, and text
		// Create a new window of size w*h pixels
		const int wWidth = 1280;
		const int wHeight = 720;
		sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Bubbles!");
		window.setFramerateLimit(60);

		// Load a font to display some text	
		sf::Font myFont;

		// Attempt to load the font from a file
		if (!myFont.loadFromFile("../font/Ohyou.ttf")){
			// If font file does not load, print an error message to the error console and exit
				std::cerr << "Could not load font!\n";
				exit(-1);
		}
	
		// Set up the text object that will be drawn to the screen
		sf::Text text("Watch these bubbles move!", myFont, 45);

		// Align text on the bottom on the screen
		text.setPosition(10, wHeight - (float)text.getCharacterSize() - 10);

		// Variables for movement speed, direction, and utility counter for loops
		float array[] = {2.0, 3.0, 4.0};
		float array2[] = {1.0, 2.0, 1.0};
		float x_direction[] = {1.0, 1.0, 1.0};
		float y_direction[] = {1.0, 1.0, 1.0};
		int counter = 1;
	
		// Create a vector of circles	
		std::vector<sf::CircleShape> circles;
		for (int i = 0; i <= 2; i++){
			circles.push_back(sf::CircleShape(25.f*(counter*2)));
			circles.back().setPosition(30.0f*counter, 50.0f*counter);
			circles.back().setFillColor(sf::Color(100*(counter*20), 50, 200));
			counter++;
		}

		// Create a vector of text shapes
		std::vector<sf::Text> texts;
		counter = 1;
		for (int i = 0; i <= circles.size(); i++){
			texts.push_back(sf::Text("Wee!", myFont, 30 * counter));
			counter++;
		}
	//End configuration for window, circles, and text


	// Main loop
	while (window.isOpen()){
		// Event handling
		sf::Event event;
		// Check for user input
		while (window.pollEvent(event)){
			switch (event.type){
				// Close window using the button on the top left of window
				case sf::Event::Closed:
					window.close();
					break;
				// Check for keyboard input
				case sf::Event::KeyPressed:
					// Close window if 'x' is pressed
					if (event.key.code == sf::Keyboard::X){
						window.close();
					}
					// Reverse the direction of the circles movement if 'k' is pressed
					if (event.key.code == sf::Keyboard::K){
						for (int i = 1; i <= circles.size(); i++){
							x_direction[i] = x_direction[i] * -1;
							y_direction[i] = y_direction[i] * -1;
						}
					}
					break;
				default:
					break;
			} // End switch statement
		} // End event handling while loop


		// Basic animation function calls
			// Change the circle's direction before it goes out of the window range 
			for(int i = 0; i <= circles.size(); i++){
				if (circles[i].getPosition().x > 1000)
					x_direction[i] = -1.0;
				if (circles[i].getPosition().y > 500)
					y_direction[i] = -1.0;
				if (circles[i].getPosition().x < 5)
					x_direction[i] = 1.0;
				if (circles[i].getPosition().y < 5)
					y_direction[i] = 1.0;
			} // End for loop checking circles position on screen
		
			// Set circle and text shape's new position for the next iteration of while loop 
			counter = 1;
			for (int i = 0; i <= circles.size(); i++){
				circles[i].setPosition(circles[i].getPosition().x + (array[i] * x_direction[i]), circles[i].getPosition().y + (array2[i] * y_direction[i]));
			texts[i].setPosition((circles[i].getPosition().x + 12*counter) + (array[i] * x_direction[i]), (circles[i].getPosition().y + 32*counter) + (array2[i] * y_direction[i]));
				counter++;
			} // End for loop setting circle and text shape's new position
		// End basic animation function calls


		// Basic rendering function calls
			// Set window background to white
			window.clear(sf::Color(255, 255, 255));
		
			// Draw circles and text shapes
			for (int i = 0; i <= 2; i++){
				window.draw(circles[i]);
				window.draw(texts[i]);
			}
		
			// Draw text at the bottom of the window
			window.draw(text);
			window.display();
		// End basic rendering function calls


	} // End main while loop

} // End main function
