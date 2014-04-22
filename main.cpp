#include "Main.h"

using namespace sf;

RenderWindow MainWindow;

WindowHandle MainWindowHandle;

bool fullscreen = false;

bool debuginput = false;
bool paused = false;
//bool g_exit = false;

//void GameLoop(float dt);

void HandleEvent(const Event &event)
{
  switch (event.type)
  {
    case Event::MouseButtonPressed:
      if (debuginput)
      {
        cout << event.mouseButton.button + " was pressed"  << endl;
        cout << "mouse x: "  <<      event.mouseButton.x   << endl;
        cout << "mouse y: "  <<      event.mouseButton.y   << endl;
      }
      break;

    case Event::MouseButtonReleased:
      if (debuginput)
      {
        cout << event.mouseButton.button + " was released" << endl;
        cout << "mouse x: "    <<   event.mouseButton.x    << endl;
        cout << "mouse y: "    <<   event.mouseButton.y    << endl;
      }
      break;

    case Event::MouseMoved:
      if (debuginput)
      {
        cout << "new mouse x: " << event.mouseMove.x << endl;
        cout << "new mouse y: " << event.mouseMove.y << endl;
      }
      break;

    case Event::KeyPressed:
      if (debuginput)
      {
        cout << event.key.code + " was pressed"   << endl;
        cout << "control:"  << event.key.control  << endl;
        cout << "alt:"      << event.key.alt      << endl;
        cout << "shift:"    << event.key.shift    << endl;
        cout << "system:"   << event.key.system   << endl;
      }
      break;

    case Event::TextEntered:
      if (debuginput && event.text.unicode < 128)
        cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << endl;
      break;

    case Event::KeyReleased:
      if (debuginput)
      {
        cout << "control:"  << event.key.control  << endl;
        cout << "alt:"      << event.key.alt      << endl;
        cout << "shift:"    << event.key.shift    << endl;
        cout << "system:"   << event.key.system   << endl;
      }

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

    case Event::Resized:
      // adjust the viewport when the window is resized
      //glViewport(0, 0, event.size.width, event.size.height);
      break;

    case Event::LostFocus:
      paused = true;
      //autosave
      break;

    case Event::GainedFocus:
      paused = false;
      //load autosave
      break;
  }
}

void renderingThread(sf::Window* window)
{
  // activate the window's context
  window->setActive(true);

  // the rendering loop
  while (window->isOpen())
  {
    // draw...

    // end the current frame -- this is a rendering function (it requires the context to be active)
    window->display();
  }
}

int main()
{//Switch to fullscreen for release
	if (fullscreen)
	{
		MainWindow.create(VideoMode::getDesktopMode(), "Title Text", Style::Fullscreen);
	}
	else
	{
		MainWindow.create(VideoMode(800, 600), "Title Text");
	}


  ContextSettings settings = MainWindow.getSettings();

  cout << "depth bits:" << settings.depthBits << endl;
  cout << "stencil bits:" << settings.stencilBits << endl;
  cout << "antialiasing level:" << settings.antialiasingLevel << endl;
  cout << "version:" << settings.majorVersion << "." << settings.minorVersion << endl;

  //glEnable(GL_TEXTURE_2D);

	MainWindowHandle = MainWindow.getSystemHandle();
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);
	
	Clock clock;
	while (MainWindow.isOpen())
	{
		Time elapsed = clock.restart();
		//updateGame(elapsed);

		Event event;
		while (MainWindow.pollEvent(event))
		{
      HandleEvent(event);
		}

    //clear the buffers
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		MainWindow.clear();
		//MainWindow.draw(shape);
		MainWindow.display();
	}

	return 0;
}

