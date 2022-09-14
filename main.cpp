#include <Pong.h>

int main(int argc, char** argv)
{
    Pong p;

    p.init("192.168.0.118", 4500);
    p.run();

    return 0;
}
