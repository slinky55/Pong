#include <Player.h>

#include <SFML/Network.hpp>

/*Player player;
player.connect(sf::IpAddress::resolve(argv[1]).value(), std::stoi(argv[2]));

sf::Packet packet;
std::string message;

while (true)
{
std::cout << "\nEnter message to send to server: ";
std::getline(std::cin, message);

if (message == "exit")
break;

packet << message;

player.sendMessage(packet);
packet.clear();
}

player.disconnect();*/

void pollEvents(sf::RenderWindow& window)
{

}

int main(int argc, char** argv)
{
    sf::RenderWindow window;
    Player player;

    window.create( sf::VideoMode({800, 600}), "Pong - Multiplayer");

    player.connect(sf::IpAddress::resolve(argv[1]).value(), std::stoi(argv[2]));

    while (window.isOpen())
    {
        // pollEvents(window);

        sf::Event e {};
        while (window.pollEvent(e))
            if (e.type == sf::Event::Closed)
                window.close();

        window.clear();
        player.draw(window);
        window.display();
    }

    player.disconnect();

    return 0;
}
