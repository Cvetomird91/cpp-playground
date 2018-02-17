#ifndef SCOPEDPTR_H
#define SCOPEDPTR_H

class ScopedPtr {

    public:
        ScopedPtr(Vector* v) : m_Obj(v){
        }

        Vector* operator->() {
            return m_Obj;
        }

        const Vector* operator->() const {
            return m_Obj;
        }

        ~ScopedPtr() {
            delete m_Obj;
        }

        //Vector* operator->() {
        //    return m_Obj;
        //}

    private:
        Vector* m_Obj;

};

#endif // SCOPEDPTR_H
