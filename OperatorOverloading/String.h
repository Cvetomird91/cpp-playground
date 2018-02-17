#ifndef STRING_H
#define STRING_H

#include <cstring>

class String
{
    private:
        char* m_Buffer;
        unsigned int m_Size;

    public:
        String(const char* string){
            m_Size = strlen(string);
            m_Buffer = new char[m_Size + 1];
            memcpy(m_Buffer, string, m_Size);
            m_Buffer[m_Size] = 0;
        }

        ~String() {
            delete[] m_Buffer;
        }

        char& operator[](unsigned int index) {
            return m_Buffer[index];
        }

        //String(const String& other) : m_Buffer(other.m_Buffer), m_Size(other.m_Size) {
            //memcpy(this, &other, sizeof(String));
        //}

        //String(const String& other) = delete;

        String(const String& other) : m_Size(other.m_Size) {

            std::cout << "Copied string!" << std::endl;

            m_Buffer = new char[m_Size + 1];
            memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
        }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);

};

std::ostream& operator<<(std::ostream& stream, const String& string){
    stream << string.m_Buffer;
    return stream;
}

#endif // STRING_H
