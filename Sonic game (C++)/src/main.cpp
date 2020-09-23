#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

float offsetX = 0, offsetY = 0;


const int H = 70;
const int W = 130;


String TileMap[H] = {

"OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
"B                                                                                                                           B",
"B                                                                                                                           B",
"B                                                                                                                           B",
"B                                                                                                                           B",   
"B                                                                                                                           B",  
"B                                                                                                                           B",
"B                                                                                                                           B",
"B                                                                                                                           B",
"B      OOOOOOOOO                                                                                                            B",
"B      BBBBBBBBBOOO                                                                                                         B",
"B         BBBBBBBBBOO                                                                                                       B",
"BO         BBBBBBBBBBOOOOO      OOOOOOOO                                                                                    B",
"BB         BBBBBBBBBBBBBBB      BBBBBBBBOOOO                                                                                B",
"B          BBBBBBBBBBBB                 BBBB                                                                              B",
"B          BBBBBBBBBB                   BBBB      OO                                                                     B",
"B          BBBBBBBB                     BBBB      BB                                                                        B",
"B     OOO  BBBBBB                       BBBB  BBB BB                                                                        B",
"B     BBB  BBBB                         BBBB      BB                                                                       B",
"B          BBBB                         BBBB      BB                                                                       B",
"B          BBBB                         BBBB      BB                                                                       B",
"B          BBBB                         BBBB      BB                                                                       B",
"BO         BBBB                         BBBB      BB                                                                       B",
"BB         BBBB                         BBBB      BB                                                                       B",
"B          BBBB                         BBBB      BB        OOOO     O                                                     B",
"B           BBB                         BBBB      BB      BBBBBB     B                                                     B",
"B      OO    BBB                        BBBB      BB        BBBB     B                                                     B",
"B      BB     BB                        BBBB      BB        BBBB     B                                                     B",
"B              B                        BBBB      BB        BBBB     B                                                     B",
"B             OB                        BBBB      BB        BBBB     B                                                     B",
"B             BB                        BBBB      BB        BBBB     B                                                     B",
"B           OOBB                        BBBB      BB        BBBB     B                                                     B",
"B           BBBB   BB                   BBBB      BB        BBBB     B                                                     B",
"B           BBBB   B B                  BBBB      BB        BBBB     B                                                     B",
"B           BBBB   B  B                 BBBB      BB        BBBB     B                                                     B",
"B           BBBB   B B                  BBBB      BB        BBBB     B                                                     B",
"B    OOO    BBBB   BB                   BBBB      BB        BBBB     B                                                     B",
"B    BBB    BBBB                        BBBB      BB        BBBB     B                                                     B",
"B           BBBB                        BBBB      BB        BBBB     B                                                     B",
"B           BBBB    BBB   B  BBBBB      BBBB      BB        BBBB     B                                                     B",
"B           BBBB    B  B  B    B        BBBB      BB        BBBB     B                                                     B",
"B        OOOBBBB    BBB   B    B        BBBB      BB        BBBB     B                                                     B",
"B        BBBBBBB    B     B    B        BBBB      BB        BBBB     B                                                     B",
"B          OBBBB    B     B    B        BBBB      BB        BBBB     B                                                     B",
"B          OBBBB                        BBBB      BB        BBBB     B                                                     B",
"B          OBBBB                        BBBB      BB        BBBB     B                                                     B",
"B  OOOOOOOOOBBBB                        BBBB      BB        BBBB     B                                                     B",
"B  OBBBBBBBBBBBB                        BBBB      BB        BBBB     B                                                     B",
"BOOOBBBBBBBBBBBB                        BBBB      BBOOOOOOOOBBBBOOOOOBOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOB",
"YYYYYYYYYYYYYYYY                        YYYY      YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY",

}; 

void menu(RenderWindow & window) {
	
	Texture menuTexture1, menuTexture2, menuBackground;
	menuTexture1.loadFromFile("images/play.png");
	menuTexture2.loadFromFile("images/quit.png");
	menuBackground.loadFromFile("images/menu.jpg");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menuBg(menuBackground);
	
	bool isMenu = 1;
	int menuNum = 0;
	
	menu1.setPosition(40, 40);
	menu2.setPosition(40, 200);
	menuBg.setPosition(1, 1);
 
	while (isMenu) {
        Event event;
         while (window.pollEvent(event)) {
             if (event.type == Event::Closed)
             window.close();
        }

		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(10, 18, 21));
 
		if (IntRect(40, 40, 230, 230).contains(Mouse::getPosition(window))) {
             		menu1.setColor(Color::Blue); 
            	        menuNum = 1; 
        }

		if (IntRect(40, 200, 230, 230).contains(Mouse::getPosition(window))) { 
            		menu2.setColor(Color::Blue); 
            		menuNum = 2; 
        }

 
		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (menuNum == 1) {
                	isMenu = false;
       }

			if (menuNum == 2) { 
                		window.close(); 
                		isMenu = false; 
       }
}
 
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.display();
	}
}

class SONIC  {
    public:

    float dx, dy;
    FloatRect rect;
    bool onGround;
    bool move = false;
    Sprite sprite;
    float currentFrame;

    SONIC (Texture &image) {
        sprite.setTexture(image);
    
        rect = FloatRect(100,300,45,55);
        sprite.setTextureRect(IntRect(0,0,75,100));
  
        dx = dy = 0.1;
        currentFrame = 0;
    }

    void update(float time) {
        rect.left += dx * time;
        Collision(0);

        if(!onGround) 
        dy = dy + 0.0035*time;
        rect.top += dy * time;
        onGround = false;
        Collision(1);

            currentFrame += time * 0.008;
            //num of pic
            if(currentFrame > 4) 
            currentFrame -= 4;
            //left (mirror than right)
           if (dx<0) 
           sprite.setTextureRect(IntRect(80*int(currentFrame)+75.2,95,-75.4,100));

           if (dx>0) 
           sprite.setTextureRect(IntRect(80*int(currentFrame),95,75.2,100));
        
        sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

        dx = 0;
    }

  void Collision(int dir) {
     for (int i = rect.top/34 ; i<(rect.top+rect.height)/34; i++)
	  for (int j = rect.left/34; j<(rect.left+rect.width)/34; j++) { 
	  	if (TileMap[i][j]=='B') { 
	        if ((dx>0) && (dir==0)) rect.left =  j*34 -  rect.width; 
		    if ((dx<0) && (dir==0)) rect.left =  j*34 + 34;
			if ((dy>0) && (dir==1))  { rect.top =   i*34 -  rect.height;  dy=0;   onGround=true; }
			if ((dy<0) && (dir==1))  { rect.top = i*34 + 34;   dy=0;}
		   }
        if (TileMap[i][j]=='O') { 
	        if ((dx>0) && (dir==0)) rect.left =  j*34 -  rect.width; 
		    if ((dx<0) && (dir==0)) rect.left =  j*34 + 34;
			if ((dy>0) && (dir==1))  { rect.top =   i*34 -  rect.height;  dy=0;   onGround=true; }
			if ((dy<0) && (dir==1))  { rect.top = i*34 + 34;   dy=0;}
		}

        if (TileMap[i][j]=='Y') { 
	        if ((dx>0) && (dir==0)) rect.left =  j*34 -  rect.width; 
		    if ((dx<0) && (dir==0)) rect.left =  j*34 + 34;
			if ((dy>0) && (dir==1))  { rect.top =   i*34 -  rect.height;  dy=0;   onGround=true; }
			if ((dy<0) && (dir==1))  { rect.top = i*34 + 34;   dy=0;}
		}
		 
		 if (TileMap[i][j]=='0') { 
			        TileMap[i][j]=' ';
		
        } 
         if (TileMap[i][j]=='M') { 
		 
		} 
    	}
    }
};


int main(){
    
    RenderWindow window(VideoMode(1250, 580), "SFML works!");
	menu(window);
    
    /*
    Texture tileSet;
	tileSet.loadFromFile("Mario_tileset.png");
    Sprite tile(tileSet);*/

    Texture sonic;
    sonic.loadFromFile("images/sonic.png");

    SONIC s(sonic);

    float currentFrame = 0;
    Clock clock;

   RectangleShape rectangle( Vector2f(32,32));
    
    while (window.isOpen()) {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        time = time/700;
        if (time>20) time = 20;
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(Keyboard::isKeyPressed(Keyboard::Left)) { 
            s.dx = -0.3;

        }

        if(Keyboard::isKeyPressed(Keyboard::Right)) {
            s.dx = 0.3;

        }

        if(Keyboard::isKeyPressed(Keyboard::Up)) {
            
            if (s.onGround) {
                s.dy = -1.2;
                s.onGround = false;
            }
        }
 
        s.update(time);

		if (s.rect.left > 300) offsetX = s.rect.left - 300;
        offsetY = s.rect.top - 200;

		window.clear(Color::White);


		 for (int i=0; i<H; i++)
			 for (int j=0; j<W ; j++) { 
				  if (TileMap[i][j]=='B') 
                  rectangle.setFillColor(Color::Black);

                  if (TileMap[i][j]=='Y') 
                  rectangle.setFillColor(Color::Green);

                  if (TileMap[i][j]=='O') 
                  rectangle.setFillColor(Color::White);

			      if (TileMap[i][j]=='0')  
                  rectangle.setFillColor(Color::Green);

                  if (TileMap[i][j]=='M')  
                  rectangle.setFillColor(Color::White);

				  if (TileMap[i][j]==' ') 
                  continue;

		          rectangle.setPosition(j*34-offsetX,i*34 - offsetY); 
   
		          window.draw(rectangle);   
	       	 }
    
		window.draw(s.sprite);
        window.display();
    }

    return 0;
}
