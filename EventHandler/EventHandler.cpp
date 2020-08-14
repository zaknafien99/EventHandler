#include "pch.h"

using namespace System;

ref class Counter
{
    int count;
    int limit;

public:
    Counter(int lim)
    {
        count = 0;
        limit = lim;
    }
    event EventHandler^ LimitReached;
    void Increment()
    {
        Console::WriteLine("Count: {0}", ++count);
        if (count == limit)
            LimitReached(this, gcnew EventArgs());
    }
};

ref class Observer
{
public:
    static void CallMe(Object^ src, EventArgs^ args)
    {
        Console::WriteLine("Limit reached");
    }
};

int main(array<System::String ^> ^args)
{
    //Define a counter with a limit of 3
    Counter count(3);

    count.LimitReached += gcnew EventHandler(&Observer::CallMe);

    for (size_t i = 0; i < 5; i++)
    {
        count.Increment();
    }
    return 0;
}
