#include <iostream>
#include "Vector.h"
#include <memory>
#include "String.h"
#include <string>
#include <stdlib.h>
#include "ScopedPtr.h"

using namespace std;

void PrintString(const String& string) {
    std::cout << string << std::endl;
}

int main()
{

    {
        Vector position(4.0f, 4.0f);
    }

    cout << "After init" << endl;

    Vector speed(0.5f, 1.5f);
    Vector powerup(1.1f, 1.0f);

    Vector init(1.1f, 1.0f);
    Vector* memLeak = new Vector(0.0f, 0.0f);
    Vector* strange = new Vector();

    const Vector* i = &init;
    i = &powerup;

    bool areEqual = init == powerup;

    cout << areEqual << endl;
    cout << strange->x << endl;

    delete memLeak;
    delete strange;

    int(*initVar)() = Vector::VectorInit;

    //unique pointer
    //shared pointer
    //make shared

    std::shared_ptr<Vector> v1;
    {
        std::shared_ptr<Vector> shared = std::make_shared<Vector>();
        std::weak_ptr<Vector> weakPtr = v1 = shared;
    }

    Vector* a = new Vector();
    Vector* b = a;

    cout << sizeof(b) << endl;

    String str = "Ceco";
    String second = str;
    second[2] = 'C';

    PrintString(str);
    PrintString(second);

    const ScopedPtr scoped = new Vector();
    scoped->getVector();

}
