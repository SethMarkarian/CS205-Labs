#ifndef ENGINE_H
#define ENGINE_H


class engine
{
protected:
    int rows;
    int cols;
    char gameboard[rows][cols];
public:
    engine(int r, int c);
    ~engine();
};

#endif // ENGINE_H
