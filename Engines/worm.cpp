#include "worm.h"

Worm::Worm(int s)
{
    //! set instance variables
    //! these are preset so that the developer does not make an impossible setup
    score = 0;
    biq = 0;
    len = 1;
    edge = '*';
    empt = ' ';
    body = 'o';
    head = '@';
    hs.first = 3;
    hs.second = 3;
    dir.first = 1;
    dir.second = 0;
    won_yet = false;
    lost_yet = false;
    srand(s);
    //! set up gameboard
    place();
}

void Worm::place()
{
    //! loop through each row, column location
    for(int i = 0; i < ROWS; i++)
    {
        gameboard[i][0] = edge; //! the left and right column of each row is a edge
        for(int j = 1; j < COLS - 1; j++)
        {
            if(i == 0 || i == ROWS - 1)
            {
                gameboard[i][j] = edge; //! assign an edge character
            }
            else
            {
                insert(i, j, empt); //! assign an empty character
            }
        }
        gameboard[i][COLS - 1] = edge; //! assign to an edge character
    }
    insert(hs.first, hs.second, head); //! insert the head on the gameboard
    segments.push_back(hs); //! insert the head on the segments vector
    for(int i = 0; i < len; i++) //! builds up the worm from the head to the tail
    {
        std::pair<int, int> p_i; //! stands for pair i
        p_i.first = hs.first + i * dir.first * -1; //! coordinates of next segment based on direction
        p_i.second = hs.second + i * dir.second * -1;
        segments.push_back(p_i); //! add segments to vector
        insert(p_i.first, p_i.second, body); //! insert onto gameboard
    }
    insert(1, 1, '1'); //! place the first point; done manually instead of randomly here for testing purposes
}

char Worm::insert(int row, int col, char c)
{
    if(gameboard[row][col] == empt) //! if the location is an empty space
    {
        int key = (row - 1) * ROWS + col;
        blanks.erase(key); //! erase this location from blanks map
        gameboard[row][col] = c; //! set row, column to c
        return empt;
    }
    else
    {
        char ret = gameboard[row][col];
        gameboard[row][col] = c; //! set row, column to c
        return ret;
    }
}

char Worm::remove(int row, int col)
{
    char ret = gameboard[row][col];
    gameboard[row][col] = empt; //! sets location to empty space
    insert_blank(row, col); //! adds location to blanks map
    return ret;
}

void Worm::procession()
{
    std::pair<int, int> temp_a; //! where the current segment will go to
    std::pair<int, int> temp_b; //! where the current segment is/ was
    temp_a.first = segments[0].first + dir.first; //! new location for head
    temp_a.second = segments [0].second + dir.second;
    char to = gameboard[temp_a.first][temp_a.second];
    if(to == body || to == edge) //! checks if going to hit an edge or body segment
    {
        lost_yet = true; //! the player lost
        return;
    }
    insert(temp_a.first, temp_a.second, head); //! insert the head
    insert(segments[0].first, segments[0].second, body); //! inserts body segment where head was
    if(to > 48 && to < 58) //! adjusts for if a score is there
    {
        score += (to - 48); //! adjusts score
        biq += (to - 48); //! adjusts body in queue
        place_points(); //! places a new point
    }
    for(int i = 0; i < segments.size(); i ++) //! adjusts segments to location of the segment in front of them
    {
        temp_b = segments[i];
        segments[i] = temp_a;
        temp_a = temp_b;
    }
    if(biq != 0) //! if there are segments in queue, add segment
    {
        segments.push_back(temp_a);
        biq--;
    }
    else
    {
        remove(temp_a.first, temp_a.second); //! remove character from final segment
    }
}

void Worm::up()
{
    //! changes direction to up then calls procession
    dir.first = 1;
    dir.second = 0;
    procession();
}

void Worm::left()
{
    //! changes direction to left then calls procession
    dir.first = 0;
    dir.second = -1;
    procession();
}

void Worm::down()
{
    //! changes direction to down then calls procession
    dir.first = -1;
    dir.second = 0;
    procession();
}

void Worm::right()
{
    //! changes direction to right then calls procession
    dir.first = 0;
    dir.second = 1;
    procession();
}

void Worm::place_points()
{
    if(blanks.size() == 0) //! if there are no blank spaces
    {
        won_yet = true; //! the player won!
        return;
    }
    std::pair<int, int> next;
    next = get_rand_blank(); //! assigns next points location to a random blank space
    int max;
    if(blanks.size() < 9)
    {
        max = blanks.size();
    }
    else {
        max = 9;
    }
    int s = rand() % (max) + 49; //! character value for score
    insert(next.first, next.second, s);
}

void Worm::insert_blank(int row, int col)
{
    int key = (row - 1) * ROWS + col; //! key value based on the location in the gameboard
    std::pair<int, int> value; //! value is the location on the board
    value.first = row;
    value.second = col;
    std::pair<int, std::pair<int, int>> ins;
    ins.first = key;
    ins.second = value;
    blanks.insert(ins); //! insert the key, value pair into the map
}

std::pair<int, int> Worm::get_rand_blank()
{
    int r = rand() % blanks.size(); //! picks a random number within the map for the iterator
    std::map<int, std::pair<int, int>>::iterator it = blanks.begin(); //! initialize iterator
    std::advance(it, r); //! go to random location
    std::pair<int, int> value = it -> second; //! retrieve value
    return value; //! returns value
}

char Worm::get(int row, int col)
{
    return gameboard[row][col]; //! returns char at that location
}

std::vector<std::pair<int, int>> Worm::get_worm()
{
    return segments;
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
