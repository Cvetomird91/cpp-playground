#ifndef VECTOR_ONCE
#define VECTOR_ONCE

struct Vector
{
    float x, y;

    Vector(float x, float y) {
        this->x = x;
        this->y = y;
    }

    Vector() {
        this->x = 1.0f;
        this->y = 0.0f;
    }

    Vector Add(const Vector &other) const
    {
        return *this + other;
    }

    Vector Multiply(const Vector &other) const {
        return *this * other;
    }

    Vector operator+(const Vector &other) const {
        return Vector(x + other.x, y + other.y);
    }

    Vector operator*(const Vector &other) const {
        return Vector(x * other.x, y * other.y);
    }

    bool operator==(const Vector &other) const {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector &other) const {
        return !(*this == other);
        //return !operator==(other);
    }

    Vector* getVector() const {
        const Vector* v = this;
    }

    static int VectorInit(Vector v){};


    ~Vector() {
        std::cout << "Vector Destroyed!!!" << std::endl;
    }

    //private:
    Vector(const Vector& other) : x(other.x), y(other.y) {
        std::cout << "Copied Vector!" << std::endl;
    }

};

#endif
