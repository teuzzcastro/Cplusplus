#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Plataforma 2D");

    sf::RectangleShape player(sf::Vector2f(50.0f, 50.0f));
    player.setFillColor(sf::Color::Green);
    player.setPosition(100.0f, 100.0f);

    float velocityY = 0;
    const float gravity = 0.5f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.move(-5.0f, 0.0f);
        }
      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.move(5.0f, 0.0f);
        }
      
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && player.getPosition().y + 50 >= 600) {
            velocityY = -10.0f;
        }

        velocityY += gravity;
        player.move(0.0f, velocityY);

        if (player.getPosition().y + 50 > 600) {
            player.setPosition(player.getPosition().x, 600 - 50);
            velocityY = 0;
        }

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}
