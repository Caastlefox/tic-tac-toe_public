#include <SFML/Graphics.hpp>
#include <iostream>
//#include <list>
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
			this->state = state;
			
			switch (state) {
			case 0:
				rectangle = sf::IntRect(0, 0, 130, 130);
				this->sprite.setTextureRect(rectangle);
				break;
			case 1:
				rectangle = sf::IntRect(0, 600, 130, 130);
				this->sprite.setTextureRect(rectangle);
				std::cout << "executed";
				break;
			case 2:
				rectangle = sf::IntRect(150, 600, 130, 130);
				this->sprite.setTextureRect(rectangle);
				std::cout << "executed";
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
		button_list[1] = Button("Button2", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(220, 200));
		button_list[2] = Button("Button3", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(420, 200));
		button_list[3] = Button("Button4", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(20 , 400));
		button_list[4] = Button("Button5", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(220, 400));
		button_list[5] = Button("Button6", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(420, 400));
		button_list[6] = Button("Button7", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(20 , 600));
		button_list[7] = Button("Button8", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(220, 600));
		button_list[8] = Button("Button9", sf::IntRect(0, 0, 130, 130), texture, sf::Vector2f(420, 600));
		Board::clear();

		MyFont = font;



		// select the font
		title.setFont(MyFont); // font is a sf::Font

		// set the string to display
		title.setString(" Tic-Tac-Toe \n   Player " + player_flag);

		title.setCharacterSize(40);
		title.setPosition(sf::Vector2f(215.f, 0.f));


		main_sprite.setTexture(texture, true);
		main_sprite.setTextureRect(sf::IntRect(0, 0, 600, 600));
		main_sprite.setPosition(sf::Vector2f(0.f, 175.f));
	
	};
	
	void play (int x, int y);
	
	bool win_check();
	
	void clear();

	void draw(sf::RenderWindow& window);

};

 void Board::play(int x, int y) {
	 /*/X 20 170 220 370 420
	 Y 350 400 550 600 */

	 if (x < 170 and x > 20  and y > 200 and y < 350) { button_list[0].change_state(player_flag);}
	 if (x < 170 and x > 20  and y > 400 and y < 550) { button_list[1].change_state(player_flag);}
	 if (x < 170 and x > 20  and y > 600 and y < 750) { button_list[2].change_state(player_flag);}
	 if (x < 370 and x > 220 and y > 200 and y < 350) { button_list[3].change_state(player_flag);}
	 if (x < 370 and x > 220 and y > 400 and y < 550) { button_list[4].change_state(player_flag);}
	 if (x < 370 and x > 220 and y > 600 and y < 750) { button_list[5].change_state(player_flag);}
	 if (x < 570 and x > 420 and y > 200 and y < 350) { button_list[6].change_state(player_flag);}
	 if (x < 570 and x > 420 and y > 400 and y < 550) { button_list[7].change_state(player_flag);}
	 if (x < 570 and x > 420 and y > 600 and y < 750) { button_list[8].change_state(player_flag);}
	 std::cout << player_flag;
	 /*
	 if (pos[num] != 0) {return;}
	 pos[num] = player_flag;
	 Board::win_check();
	 */
	 if (player_flag == 1) {player_flag = 2; return;}
	 player_flag = 1;
	 return;
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
	 /*
	 std::list <Button> blist(button_list);
	 Button b9 = blist.back();
	 std::cout << b9.read_state();
	 blist.pop_back();
	 Button b8 = blist.back();
	 blist.pop_back();
	 Button b7 = blist.back();
	 blist.pop_back();
	 Button b6 = blist.back();
	 blist.pop_back();
	 Button b5 = blist.back();
	 blist.pop_back();
	 Button b4 = blist.back();
	 blist.pop_back();
	 Button b3 = blist.back();
	 blist.pop_back();
	 Button b2 = blist.back();
	 blist.pop_back();
	 Button b1 = blist.back();
	 blist.pop_back();
	 if (b1.read_state() == player_flag and b5.read_state() == player_flag and b9.read_state() == player_flag)
		 {
			 return true;
		 }
	 else if (b7.read_state() == player_flag and b5.read_state() == player_flag and b3.read_state() == player_flag)
		 {
			 return true;
		 }

		 if (b1.read_state() == player_flag and b2.read_state() == player_flag and b3.read_state() == player_flag)
	 {
		 return true;
	 }
	 if (b4.read_state() == player_flag and b5.read_state() == player_flag and b6.read_state() == player_flag)
	 {
		 return true;
	 }
	 if (b7.read_state() == player_flag and b8.read_state() == player_flag and b9.read_state() == player_flag)
	 {
		 return true;
	 }
	 if (b1.read_state() == player_flag and b4.read_state() == player_flag and b7.read_state() == player_flag)
	 {
		 return true;
	 }
	 if (b2.read_state() == player_flag and b5.read_state() == player_flag and b8.read_state() == player_flag)
	 {
		 return true;
	 }
	 if (b3.read_state() == player_flag and b6.read_state() == player_flag and b9.read_state() == player_flag)
	 {
		 return true;
	 }
		 */

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



