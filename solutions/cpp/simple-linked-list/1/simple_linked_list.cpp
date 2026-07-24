#include "simple_linked_list.h"

#include <stdexcept>
#include <vector>

namespace simple_linked_list
{

    std::size_t List::size() const
    {
        auto p = head;
        size_t n = 0;
        while (p)
        {
            n++;
            p = p->next;
        }
        return n;
    }

    void List::push(int entry)
    {
        auto ele = std::make_shared<Element>(entry);
        if (!head)
        {
            head = ele;
        }
        else
        {
            auto p = head;
            while (p->next)
            {
                p = p->next;
            }
            p->next = ele;
        }
    }

    int List::pop()
    {
        if (!head)
        {
            return 0;
        }
        if (!head->next)
        {
            auto data = head->data;
            head = nullptr;
            return data;
        }
        auto p = head;
        while (p)
        {
            if (!p->next->next)
            {
                auto q = p->next;
                p->next = nullptr;
                return q->data;
            }
            p = p->next;
        }
        return 0;
    }

    void List::reverse()
    {
        if (!head)
        {
            return;
        }

        auto size = this->size();
        std::vector<int> nodes;
        for (int i = 0; i < size; ++i)
        {
            nodes.emplace_back(this->pop());
        }
        for (int i = 0; i < size; ++i)
        {
            this->push(nodes[i]);
        }
    }

} // namespace simple_linked_list
