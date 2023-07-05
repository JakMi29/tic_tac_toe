#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
using namespace std;

int main(){
    game game;
    game.run();
   /* sf::RenderWindow window(sf::VideoMode(800, 600), "Narysuj linię");

    // Główna pętla gry
    sf::RectangleShape field(sf::Vector2f(200, 200));
    field.setPosition(300, 200);
    field.setFillColor(sf::Color::Green);

    // Główna pętla gry
    while (window.isOpen())
    {
        // Obsługa zdarzeń
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.field == sf::Mouse::Left)
                {
                    // Sprawdzanie czy przycisk został kliknięty
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    if (field.getGlobalBounds().contains(mousePos.x, mousePos.y))
                    {
                        std::cout << "Przycisk został kliknięty!" << std::endl;
                    }
                }
            }
        }

        // Wyczyszczenie okna
        window.clear();

        // Rysowanie przycisku
        window.draw(field);

        // Wyświetlanie zawartości okna
        window.display();
    }

*/
    return 0;
}