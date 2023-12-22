#ifndef IDRAWABLE_H
#define IDRAWABLE_H

class IDrawable {
    public:
        virtual ~IDrawable() {}
        virtual void draw() = 0; //This is a virtual becuase  it's = to 0.




};


#endif