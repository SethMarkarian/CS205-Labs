#ifndef ENGINE_H
#define ENGINE_H


class engine
{
protected:
    int rows;
    int cols;
    char ** gameboard; // who knows how to use this??
public:
    engine(int r, int c);
    engine();
    ~engine();
};

#endif // ENGINE_H
