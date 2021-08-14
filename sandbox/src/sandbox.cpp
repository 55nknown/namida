#include <iostream>
#include <namida/namida.h>

class Sandbox : public Namida::Application
{
public:
    Sandbox()
    {

    }   

    ~Sandbox()
    {

    }
};

Namida::Application *Namida::CreateApplication()
{
    return new Sandbox();
}