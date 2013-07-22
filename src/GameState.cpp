#include "GameState.hpp"

#include "graphics.hpp"
#include "stateDriver.hpp"

GameState::GameState()
{
    playerTexture.loadFromFile("res/img/player.png", sf::IntRect(32 ,0,32 , 32));
    player.setTexture(playerTexture);

    map.resizeLayer(0,5,5);
    map.fillLayer(0,2);
    

}

void GameState::onSet()
{
    graphics::window.setTitle("game");

    // Buttons

    buttonlayer.create("Add Layer");
    buttonresizelayer.create("Resize Layer");
    buttonfilllayer.create("Fill Layer");

    buttonlayer.setPosition( 10, 10);
    buttonresizelayer.setPosition( ( 10 + buttonlayer.getWidth() + 5), 10);
    buttonfilllayer.setPosition((10 + buttonlayer.getWidth() + 5 + buttonresizelayer.getWidth() + 5), 10);


}

void GameState::onUpdate()
{
    using graphics::window;

   
    /*** KEYBOARD PLAYER  STUFF ***/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        player.move(0, -7);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        player.move(7, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        player.move(0, 7);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        player.move(-7, 0);

    /*** END KEYBOARD PLAYER STUFF  ***/

    /*** EDITOR MODE WHEN PRESSING CONTROL AND ZQSD/WASD AT THE SAME TIME ***/

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
        camera.editorCamera();


    //camera
    camera.view.setCenter(player.getPosition().x, player.getPosition().y);

    //Draw Here for the game
    camera.setView(1);
    window.clear(sf::Color(0,0,0));
    map.display();
    window.draw(player);

    //Draw here for the GUI
    camera.setView(2);

    buttonlayer.display();
    buttonresizelayer.display();
    buttonfilllayer.display();

     /** PUT EVENTS FOR BUTTONS **/

     if(buttonlayer.hovered)
        buttonlayer.move(0, 5);
         
      if(buttonresizelayer.hovered)
         buttonresizelayer.move(0, 5);

      if(buttonfilllayer.hovered)
         buttonfilllayer.move(0, 5);

    
    if(buttonlayer.released)
        buttonlayer.setWidth(buttonlayer.getWidth()+20);


    /** PUT EVENTS FOR BUTTONS END **/




}

void GameState::onEvent(const sf::Event &event)
{
    using graphics::window;

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        stateDriver::requestQuit();

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
        stateDriver::setState("menu");

    if(event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F4)
        stateDriver::setState("editor");

    if(event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta == 1)
        camera.zoomIn();

    if(event.type == sf::Event::MouseWheelMoved && event.mouseWheel.delta == -1)
        camera.zoomOut();

    buttonlayer.processEvents(event);
    buttonresizelayer.processEvents(event);
    buttonfilllayer.processEvents(event);



}
