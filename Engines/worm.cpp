#include "worm.h"

Worm::Worm()
{
    score = 0;
    biq = 0;
    len = 1; // 7 on web
    edge = '*';
    empt = ' ';
    body = 'o';
    head = '@';
    hs.first = 3;
    hs.second = 3;
    dir.first = 1;
    dir.second = 0;
    seed = 17;
    srand(seed);
    place();
    won_yet = false;
    lost_yet = false;
}

void Worm::place()
{
    for(int i = 0; i < ROWS; i++)
    {
        gameboard[i][0] = edge;
        for(int j = 0; j < COLS - 1; j++)
        {
            if(i == 0 || i == ROWS - 1)
            {
                gameboard[i][j] = edge;
            }
            else
            {
                gameboard[i][j] = empt;
                insert_blank(i, j);
            }
        }
        gameboard[i][COLS - 1] = edge;
    }
    insert(hs.first, hs.second, head);
    segments.push_back(hs);
    // this assumes the developer won't make the sizes "impossible"
    for(int i = 0; i < len; i++)
    {
        std::pair<int, int> p_i; // stands for pair i
        p_i.first = hs.first + i * dir.first * -1; // because we're populating backwards
        p_i.second = hs.second + i * dir.second * -1;
        segments.push_back(p_i);
        insert(p_i.first, p_i.second, body);
    }
    place_points();
}

char Worm::insert(int x, int y, char c)
{
    if(gameboard[x][y] == empt)
    {
        int key = (x - 1) * ROWS + y;
        blanks.erase(key);
        gameboard[x][y] = c;
        return empt;
    }
    else
    {
        char ret = gameboard[x][y];
        gameboard[x][y] = c;
        return ret;
    }
}

char Worm::remove(int a, int b)
{
    char ret = gameboard[a][b];
    gameboard[a][b] = empt;
    insert_blank(a, b);
    return ret;
}

void Worm::procession() //std::pair<int, int> dir
{
    std::pair<int, int> temp_a;
    std::pair<int, int> temp_b;
    temp_a.first = segments[0].first + dir.first;
    temp_a.second = segments [0].second + dir.second;
    char to = gameboard[temp_a.first][temp_b.second];
    if(to == body || to == edge)
    {
        lost_yet = true;
        return;
    }
    insert(temp_a.first, temp_a.second, head);
    if(to > 48 && to < 58) //adjusts for if a score is there
    {
        score += (to - 48);
        biq += (to - 48);
        place_points();
    }
    for(int i = 0; i < segments.size(); i ++)
    {
        temp_b = segments[i];
        segments[i] = temp_a;
        temp_a = temp_b;
    }
    if(biq != 0)
    {
        segments.push_back(temp_a);
        biq--;
    }
    else
    {
        remove(temp_a.first, temp_a.second);
    }
}

void Worm::up()
{
    dir.first = 0;
    dir.second = 1;
    procession();
}

void Worm::left()
{
    dir.first = -1;
    dir.second = 0;
    procession();
}

void Worm::down()
{
    dir.first = 0;
    dir.second = -1;
    procession();
}

void Worm::right()
{
    dir.first = 1;
    dir.second = 0;
    procession();
}

void Worm::place_points()
{
    if(blanks.size() == 0)
    {
        won_yet = true;
        return;
    }
    std::pair<int, int> next;
    next = get_rand_blank();
    //int x = rand() % (ROWS - 1) + 1;
    //int y = rand() % (COLS - 1) + 1;
    int s = rand() % (9) + 49; // character value for score
    insert(next.first, next.second, s);
}

void Worm::insert_blank(int x, int y)
{
    int key = (x - 1) * ROWS + y;
    std::pair<int, int> value;
    value.first = x;
    value.second = y;
    std::pair<int, std::pair<int, int>> ins;
    ins.first = key;
    ins.second = value;
    blanks.insert(ins);
}

std::pair<int, int> Worm::get_rand_blank()
{
    int r = rand() % blanks.size();
    std::map<int, std::pair<int, int>>::iterator it = blanks.begin();
    std::advance(it, r);
    std::pair<int, int> value = it -> second;
    return value;
}

/* void Worm::timer_start(std::function func, unsigned int interval){
    std::thread([func, interval](){
        while (true){
            auto x = std::chrono::steady_clock::now() + std::chrono::milliseconds(interval);
            func();
            std::this_thread::sleep_until(x);
        }
    }).detach();
}

void Worm::do_something(){
    std::cout << "Worm moved!" << std::endl;
    procession();
}

int Worm::main(){
    timer_start(do_something, 1000);
    while (true){}
} */
