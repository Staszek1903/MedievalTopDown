#ifndef EVENT_H
#define EVENT_H

#include <utility>


class Event
{
public:
    enum Type
    {
        SOLID,
        HP,
        SPEED
    };

private:
    Type type;

public:
    int value;
    std::pair <int, int> pos;

    Event(Type, int);
    Event(const Event&);
    virtual ~Event();

    Type get_type() const;
};

#endif // EVENT_H
