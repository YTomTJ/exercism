#pragma once
#include <memory>
#include <cstddef>

namespace simple_linked_list
{
    class List
    {
    public:
        struct Element;

        using ptr = std::shared_ptr<Element>;

        List() = default;

        List(const List &) = delete;
        List &operator=(const List &) = delete;
        List(List &&) = delete;
        List &operator=(List &&) = delete;

        std::size_t size() const;
        void push(int entry);
        int pop();
        void reverse();

        struct Element
        {
            Element(int data) : data{data} {};
            int data{};
            ptr next{nullptr};
        };

    private:
        ptr head{nullptr};
    };

} // namespace simple_linked_list
