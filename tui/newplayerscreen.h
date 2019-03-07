#ifndef NEWPLAYERSCREEN_H
#define NEWPLAYERSCREEN_H
#include "altscreen.h"

class NewPlayerScreen : public AltScreen
{
protected:
    void fields_fill(); // last field must be null!
    void disp_labels();
public:
};

#endif // NEWPLAYERSCREEN_H
