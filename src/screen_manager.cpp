#include "screen_manager.h"

Screen_manager::Screen_manager()
{
    //ctor
}

Screen_manager::~Screen_manager()
{
    //dtor
}


 void Screen_manager::load_content()
{
    current_screen = new Game_screen;
    current_screen->load_content();
}

 void Screen_manager::update(ALLEGRO_EVENT ev)
{
    current_screen->update(ev);
}

 void Screen_manager::draw(ALLEGRO_DISPLAY *disp)
{
    current_screen->draw(disp);
}

 void Screen_manager::unload_content()
{
    current_screen->unload_content();
    delete current_screen;
}
