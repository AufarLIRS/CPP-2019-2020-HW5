#include "counted.h"

// Конструктор
Counted::Counted()
{
    bool pr;
    ID = 0;

    do
    {
        pr = false;
        ID++;

        for (size_t i = 0; i < id_.size(); i++)
        {
            // Если ID уже есть в списке
            if (id_[i] == ID)
            {
                pr = true;
                break;
            }
        }
    }
    while (pr);

    // Добавим ID в список
    id_.push_back(ID);
}

// Деструктор
Counted::~Counted()
{
    for (size_t i = 0; i < id_.size(); i++)
    {
        // Удалим ID из списка
        if (id_[i] == ID)
        {
            id_.erase(id_.begin() + i);
            break;
        }
    }
}

// Конструктор копирования
Counted::Counted(const Counted & cnt)
{
    this->ID = cnt.ID;
}

// Конструктор перемещения
Counted::Counted(Counted && cnt)
{
    ID = cnt.ID;
}

// Оператор присваивания копированием
Counted& Counted::operator =(Counted const& cnt)
{
    if (this == &cnt) return *this;
    Counted tmp;
    tmp.ID = cnt.ID;
    return tmp;
}

// Оператор присваивания перемещением
Counted& Counted::operator =(Counted && cnt)
{
    if (this == &cnt) return *this;
    ID = cnt.ID;
    return *this;
}

vector<int> Counted::id_;
