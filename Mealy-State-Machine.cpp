#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

using namespace std;

typedef enum { STOP = 0 , GO = 1 } State_Type;

State_Type current_state;
int input;
int brake;
int gas;

void initialize_state()
{
    current_state = STOP;
}

void Stop_State()
{
    cout << "Input: " << input << endl;
    cout << "Brake: " << brake << endl;
    cout << "Gas: " << gas << endl;
    cout << endl;

    if(input == 0 && brake == 0 && gas == 0)
    {
        current_state = STOP;
    }
    else if(input == 1 && brake == 0 && gas == 1)
    {
        current_state = GO;
    }
    else
    {
        current_state = STOP;
    }
}

void Go_State()
{
    cout << "Input: " << input << endl;
    cout << "Brake: " << brake << endl;
    cout << "Gas: " << gas << endl;
    cout << endl;

    if(input == 0 && brake == 1 && gas == 0)
    {
        current_state = STOP;
    }
    else if(input == 1 && brake == 0 && gas == 1)
    {
        current_state = GO;
    }
    else
    {
        current_state = GO;
    }
}

int main()
{
    cout << endl;
    
    initialize_state();

    void (*state[2]) () = { Stop_State , Go_State };

    while(true)
    {
        cout << "The current state of the Mealy machine is: " << current_state << endl;
        input = rand() % 2;
        brake = rand() % 2;
        gas = rand() % 2;
        state[current_state] ();
        Sleep(2000);
    }

    return 0;
}