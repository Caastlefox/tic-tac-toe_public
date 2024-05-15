#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>


class Button {
	private:
		std::string name;
		sf::IntRect rectangle;
		int state{};


	public:
		sf::Sprite sprite;
		Button(std::string name, sf::IntRect rect, sf::Texture& texture, sf::Vector2f position)
		{
			this->name = name;
			this->rectangle = rect;
			sprite.setTexture(texture);
			sprite.setTextureRect(rect);
			sprite.setPosition(position);

		};
		Button() {};
		~Button() {};
		int read_state() 
		{ 
			return state; 
		};
		void change_state(sf::IntRect rect,int state) 
		{
			this->state = state;
			sprite.setTextureRect(rect);
		};
		void change_state(int state)
		{
			if (this->state != 0)
				return;
			this->state = state;
			
			switch (this->state) {
			case 0:
				rectangle = sf::IntRect(0, 0, 130, 130);
				this->sprite.setTextureRect(rectangle);
				break;
			case 1:
				rectangle = sf::IntRect(0, 600, 130, 130);
				this->sprite.setTextureRect(rectangle);
				break;
			case 2:
				rectangle = sf::IntRect(150, 600, 130, 130);
				this->sprite.setTextureRect(rectangle);
				break;
			default:
				rectangle = sf::IntRect(0, 0, 130, 130);
				this->sprite.setTextureRect(rectangle);
				break;
			}

			

		};
		int what_was_clicked(int xposition, int yposition, int player)
		{
			if (rectangle.contains(xposition, yposition)) 
			{
				this->state = player;
			}
		};
};


class Board {

	int player_flag = 1;
	
	bool win_flag = false;

	Button button_list[9];

	sf::Font MyFont;

	sf::Text title;

	sf::Sprite main_sprite;

public:
	Board(sf::Font font, sf::Texture& texture)
	{
		
		button_list[0] = Button("Button1", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(20 , 200));
		/*/X 20 170 220 370 420
		//Y 350 400 550 600 */
		button_list[1] = Button("Button2", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(240, 200));
		button_list[2] = Button("Button3", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(440, 200));
		button_list[3] = Button("Button4", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(20 , 410));
		button_list[4] = Button("Button5", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(240, 410));
		button_list[5] = Button("Button6", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(440, 410));
		button_list[6] = Button("Button7", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(20 , 600));
		button_list[7] = Button("Button8", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(240, 600));
		button_list[8] = Button("Button9", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(440, 600));
		Board::clear();

		MyFont = font;



		// select the font
		title.setFont(MyFont); // font is a sf::Font

		// set the string to display
		title.setString(" Tic-Tac-Toe \n   Player 1" + player_flag);

		title.setCharacterSize(40);
		title.setPosition(sf::Vector2f(215.f, 0.f));


		main_sprite.setTexture(texture, true);
		main_sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
		main_sprite.setPosition(sf::Vector2f(0.f, 175.f));
	
	};
	
	bool play (int x, int y);
	
	bool win_check();
	
	void clear();

	void draw(sf::RenderWindow& window);

};

bool Board::play(int x, int y) {
	 /*/X 20 170 220 370 420
	 Y 350 400 550 600 */

	 if (x < 170 and x > 20  and y > 200 and y < 350) { button_list[0].change_state(player_flag);}
	 if (x < 370 and x > 220 and y > 200 and y < 350) { button_list[1].change_state(player_flag);}
	 if (x < 570 and x > 440 and y > 200 and y < 350) { button_list[2].change_state(player_flag);}
	 if (x < 170 and x > 20  and y > 410 and y < 550) { button_list[3].change_state(player_flag);}
	 if (x < 370 and x > 240 and y > 410 and y < 550) { button_list[4].change_state(player_flag);}
	 if (x < 570 and x > 440 and y > 410 and y < 550) { button_list[5].change_state(player_flag);}
	 if (x < 170 and x > 20  and y > 600 and y < 750) { button_list[6].change_state(player_flag);}
	 if (x < 370 and x > 240 and y > 600 and y < 750) { button_list[7].change_state(player_flag);}
	 if (x < 570 and x > 440 and y > 600 and y < 750) { button_list[8].change_state(player_flag);}
	 title.setString(" Tic-Tac-Toe \n   Player " + std::to_string(player_flag));
	 
	 
	 
	 win_flag = Board::win_check();
	 
	 if (win_flag) { title.setString(" Tic-Tac-Toe \n   Player " + std::to_string(player_flag)+"\n     Wins!"); return true; }

	 if (player_flag == 1) { player_flag = 2; return false; }
	 player_flag = 1;
	 return false;
 }

 bool Board::win_check() {

	 if (button_list[0].read_state() == player_flag and button_list[4].read_state() == player_flag and button_list[8].read_state() == player_flag)
	 {
		 return true;
	 }
	 else if (button_list[6].read_state() == player_flag and button_list[4].read_state() == player_flag and button_list[2].read_state() == player_flag)
	 {
		 return true;
	 }
	  
	 for (int i = 0; i <= 2; i++) {
		 if (button_list[3 * i].read_state() == player_flag and button_list[3 * i + 1].read_state() == player_flag and button_list[3 * i + 2].read_state() == player_flag)
		 {
			 return true;
		 }

		 if (button_list[i].read_state() == player_flag and button_list[i + 3].read_state() == player_flag and button_list[i + 6].read_state() == player_flag)
		 {
			 return true;
		 }
	 }
	 return false;
 }
 
 void Board::clear() {
	 for ( Button& i : button_list) {
		 i.change_state(sf::IntRect(0, 0, 130, 130),0);
	 }
 }
 
 void Board::draw(sf::RenderWindow& window) {

	 window.clear(sf::Color::Black);
	 window.draw(title);
	 window.draw(main_sprite);
	 for (int i = 0; i < 9; i++) {
		 window.draw(button_list[i].sprite);
	 }
	 
	 window.display();
 }