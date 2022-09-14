#include <Pong.h>

#include <SFML/System.hpp>

int main(int argc, char** argv)
{
    Pong p;

    p.init();
    p.run();

    return 0;
}
