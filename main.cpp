#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include "screen_manager.h"


using std::cout;
using std::endl;
void deinit(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE *qu, ALLEGRO_TIMER *timer)
{
    al_destroy_display(display);
    al_destroy_event_queue(qu);
    al_destroy_timer(timer);
}

int main()
{
    ALLEGRO_DISPLAY *display;
    ALLEGRO_EVENT_QUEUE *qu;
    ALLEGRO_TIMER *timer;
    Screen_manager screen;

     if(!al_init())
    {
        cout<<"nie mozna zainicjalizowaæ allegro"<<endl;
    }
    al_install_keyboard();
    al_install_mouse();
    al_set_new_display_flags(ALLEGRO_WINDOWED);
    display = al_create_display( 800, 600 );
    if(!display)
    {
        cout<<"nie mozna stworzyc okna"<<endl;
    }
    al_set_window_title( display, "MedievalTopDown" );

    timer = al_create_timer(1.0f/100);
    qu = al_create_event_queue();

    if(!qu)
    {
        cout<<"nie mozna utworzyc kolejki eventow"<<endl;
    }

    al_register_event_source(qu, al_get_display_event_source(display));
    al_register_event_source(qu, al_get_keyboard_event_source());
    al_register_event_source(qu, al_get_mouse_event_source());
    al_register_event_source(qu, al_get_timer_event_source(timer));

    al_init_primitives_addon();
    al_init_image_addon();

    al_clear_to_color( al_map_rgb( 156, 156, 156 ) );

    al_start_timer(timer);

    screen.load_content();
    while( true )
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(qu, &ev);
        screen.update(ev);
        if(ev.type == ALLEGRO_EVENT_TIMER)
            screen.draw(display);
        al_flip_display();


        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE ||
           (ev.type == ALLEGRO_EVENT_KEY_DOWN && ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE))
            break;
    }
    screen.unload_content();
    deinit(display, qu, timer);
    return 0;
}

