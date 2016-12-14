#include "Game.h"

Game::Game(){
		/*for(unsigned int i = 0; i < entities.size(); i++){ // Draw the entities from buildings vector
			int x = entities[i]->get_x_position();
			int y = entities[i]->get_y_position();
			std::cout<<"at gam "<<x<<","<<y<<std::endl;
			}	
			*/
}

void Game::draw(sf::RenderWindow &window, sf::View view){		
	for(unsigned int i = 0; i < entities.size(); i++){ // Draw the entities from buildings vector
		if ( entities[i]->check_hp() ){
			
		}
		else{
			int x = entities[i]->get_x_position();
			int y = entities[i]->get_y_position();
			if ( x > view.getCenter().x-CAMCENTERX  && x < view.getCenter().x+CAMCENTERX
				&& y > view.getCenter().y-CAMCENTERY  && y < view.getCenter().y+CAMCENTERY){
				window.draw( entities[i]->sprite);
			}
		}
	}
}


