#include <list>
#include "tictactoe.h"

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

    //std::list <Button> button_list;
    //button_list.push_back(Button("Button1",sf::IntRect(0,0,130,130),board_texture,sf::Vector2f(20,200)));
    /*/X 20 170 220 370 420
    //Y 350 400 550 600 */
    //button_list.push_back(Button("Button2",sf::IntRect(0,0,130,130),board_texture,sf::Vector2f(220,200)));
    //button_list.push_back(Button("Button3",sf::IntRect(0,0,130,130),board_texture,sf::Vector2f(420,200)));
    //button_list.push_back(Button("Button4",sf::IntRect(0,0,130,130),board_texture,sf::Vector2f(20,400)));
    //button_list.push_back(Button("Button5",sf::IntRect(0,0,130,130),board_texture,sf::Vector2f(220,400)));
    //button_list.push_back(Button("Button6",sf::IntRect(0,0,130,130),board_texture,sf::Vector2f(420,400)));
    //button_list.push_back(Button("Button7",sf::IntRect(0,0,130,130),board_texture,sf::Vector2f(20,600)));
    //button_list.push_back(Button("Button8",sf::IntRect(0,0,130,130),board_texture,sf::Vector2f(220,600)));
    //button_list.push_back(Button("Button9",sf::IntRect(0,0,130,130),board_texture,sf::Vector2f(420,600)));
   
    Board board(MyFont , board_texture);

    board.win_check();
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
                        std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                        std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                        board.play(event.mouseButton.x, event.mouseButton.y);
                    }
                    break;
                }
                default:
                    break;
            }
        }



        // ------------------------------DRAW-----------------------
        board.draw(window);

    }




    return 0;
}