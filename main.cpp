#include "Main.h"

using namespace sf;

sf::RenderWindow MainWindow;

sf::WindowHandle MainWindowHandle;

bool fullscreen = false;

//bool g_exit = false;

//void GameLoop(float dt);

int main()
{
	//Switch to fullscreen for release
	if (fullscreen)
	{
		//MainWindow.create(VideoMode::getDesktopMode(), "Title Text", Style::Fullscreen);
	}
	else
	{
		MainWindow.create(VideoMode(800, 600), "Title Text");
	}

	MainWindowHandle = MainWindow.getSystemHandle();
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);
	
	sf::Clock clock;
	while (MainWindow.isOpen())
	{
		sf::Time elapsed = clock.restart();
		//updateGame(elapsed);

		Event event;
		while (MainWindow.pollEvent(event))
		{
			switch (event.type)
			{
				case Event::MouseButtonPressed:
					std::cout << event.mouseButton.button + " was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
				break;

				case Event::MouseButtonReleased:
					std::cout << event.mouseButton.button + " was released" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;
					break;

				case Event::MouseMoved:
					std::cout << "new mouse x: " << event.mouseMove.x << std::endl;
					std::cout << "new mouse y: " << event.mouseMove.y << std::endl;
					break;

				case Event::KeyPressed:
					std::cout << event.key.code + " was pressed" << std::endl;
					std::cout << "control:" << event.key.control << std::endl;
					std::cout << "alt:" << event.key.alt << std::endl;
					std::cout << "shift:" << event.key.shift << std::endl;
					std::cout << "system:" << event.key.system << std::endl;
					break;
				case Event::TextEntered:
					if (event.text.unicode < 128)
						std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
					break;
				case Event::KeyReleased:
					std::cout << event.key.code + " was released" << std::endl;
					std::cout << "control:" << event.key.control << std::endl;
					std::cout << "alt:" << event.key.alt << std::endl;
					std::cout << "shift:" << event.key.shift << std::endl;
					std::cout << "system:" << event.key.system << std::endl;
					switch (event.key.code)
					{
						case Keyboard::Key::Escape:
							
							break;
						case Keyboard::Key::LSystem:
						case Keyboard::Key::RSystem:
							
							break;
					}
					break;
				case Event::Closed:
					//Save and prompt for confirmation of close
					MainWindow.close();
					break;
			}
		}

		MainWindow.clear();
		MainWindow.draw(shape);
		MainWindow.display();
	}

	return 0;
}