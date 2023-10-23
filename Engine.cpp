#include "Engine.h"


Engine::Engine()
{
    VideoMode vm(1280, 720);
    //VideoMode vm(1920, 1080);
    m_Window.create(vm, "Pong", Style::Default); 
}

void Engine::run()
{
    int lives = 3;
    
    //create a bat at the bottom center of the screen
    Bat bat1(192, m_Window.getSize().y / 2);
    Bat bat2(m_Window.getSize().x - 192, m_Window.getSize().y / 2);

    //create a ball
    Ball ball(m_Window.getSize().x / 2, 0);

    
    Text hud;
    //hud.setOrigin(hud.g)
    //int score = 0;
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");

    //Gamelay HUD

    switch (HHUDContext)
    {
    case 0:
    {
        hud.setFont(font);
        hud.setCharacterSize(76);
        hud.setFillColor(Color::White);
        hud.setPosition(m_Window.getSize().y / 2, 0);
        //hud.setPosition(m_Window.getSize().y/2 - hud.getLocalBounds().width/2, (m_Window.getSize().y / 2) - hud.getLocalBounds().height/2);
        //hud.setString("Two Player Pong");
        break;
    }
    default:
        break;
    }
   

    Clock clock;

    while (m_Window.isOpen())
    {
		m_DT = m_Clock.restart();
		m_FPS = m_DT.asSeconds();

        Event event;

        while (m_Window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                //quit the game when window is closed
                m_Window.close();
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            m_Window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Up) && bat2.getPosition().top > 0)
        {
            bat2.moveUp();
        }
        else
        {
            bat2.stopUp();
        }

        if (Keyboard::isKeyPressed(Keyboard::Down) && bat2.getPosition().top + bat2.getPosition().height < m_Window.getSize().y)
        {
            bat2.moveDown();
        }
        else
        {
            bat2.stopDown();
        }
       
        if (Keyboard::isKeyPressed(Keyboard::W) && bat1.getPosition().top > 0)
        {
            bat1.moveUp();
        }
        else
        {
            bat1.stopUp();
        }

        if (Keyboard::isKeyPressed(Keyboard::S) && bat1.getPosition().top + bat1.getPosition().height < m_Window.getSize().y)
        {
            bat1.moveDown();
        }
        else
        {
            bat1.stopDown();
        }

        //update delta time
        Time dt = clock.restart();
        bat1.update(dt);
        bat2.update(dt);
        ball.update(dt);

        //update the hud text 
        std::stringstream ss;
        ss << "P1: " << bat1.getScore() << "  P2:" << bat2.getScore();
        hud.setString(ss.str());

        //handle ball hitting the bottom
        if (ball.getPosition().left < 0 )
        {

            ball.rePosition();
            //lives--;
            bat1.getScore()++;
         
        }
        if (ball.getPosition().left + ball.getPosition().width > m_Window.getSize().x)
        {

            ball.rePosition();
       
            bat2.getScore()++;
          
        }
        //handle ball hitting top and bottom
        if (ball.getPosition().top < 0 || ball.getPosition().top + ball.getPosition().height > m_Window.getSize().y)
        {
           ball.reboundSides();
        }

        // ball hit the bat
        if (ball.getPosition().intersects(bat1.getPosition()) || ball.getPosition().intersects(bat2.getPosition()))
        {
            ball.reboundBat();
        }


        // Draw

        m_Window.clear();

        m_Window.draw(hud);
        m_Window.draw(bat1.getShape());
        m_Window.draw(bat2.getShape());
        m_Window.draw(ball.getShape());

        m_Window.display();
    }
}
