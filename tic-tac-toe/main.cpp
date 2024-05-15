#include "tictactoe.h"
#include <thread>
#include <chrono>
int main()
{
    // ------------------------------INITIALIZE-----------------------
    sf::RenderWindow window(sf::VideoMode(600, 800), "GAME");
    sf::Font MyFont;
    // Load from a font file on disk
    if (!MyFont.loadFromFile("times.ttf"))
    {
        // Error...
    }

    sf::Texture board_texture;
    if (!board_texture.loadFromFile("TTTboard.png"))
    {
        // error...
        std::cout << "Texture loading error";
    }   
    
    
    Board board(MyFont , board_texture);
    bool win_flag = false;
    
    // main game loop
    while (window.isOpen()) {
        // ------------------------------UPDATE-----------------------
        
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case(sf::Event::Closed): {
                    window.close();
                    break;
                }
                case(sf::Event::KeyPressed): {
                    if ((event.key.scancode == sf::Keyboard::Scan::Escape))
                        window.close();
                    break;
                }
                case (sf::Event::MouseButtonPressed):
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        //std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                        //std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                        win_flag = board.play(event.mouseButton.x, event.mouseButton.y);
                    }
                    break;
                }
                default:
                    break;
            }
        }
        // ------------------------------DRAW-----------------------
       board.draw(window);
       if (win_flag) { std::this_thread::sleep_for(std::chrono::milliseconds(2000)); return 0; }
    }




    return 0;
}