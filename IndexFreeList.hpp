#include <vector>

template <typename T>
class IndexFreeList
{
public:
    IndexFreeList();
    IndexFreeList(const int size);
    ~IndexFreeList();
    int Insert(const T &data);
    void Remove(const int index);
    T &operator[](const int index);
    void Clear();

private:
    struct Element
    {
        T data;
        int next;
    };

    std::vector<Element> m_data;
    int m_firstFree;
};

template <typename T>
IndexFreeList<T>::IndexFreeList()
    : m_firstFree(-1)
{
}

template <typename T>
IndexFreeList<T>::IndexFreeList(const int size)
    : m_firstFree(-1)
{
    m_data.reserve(size);
}

template <typename T>
IndexFreeList<T>::~IndexFreeList()
{
    m_data.clear();
}

template <typename T>
int IndexFreeList<T>::Insert(const T &data)
{
    if (m_firstFree != -1)
    {
        const int index = m_firstFree;
        m_data[index].data = data;
        m_firstFree = m_data[index].next;
        return index;
    }
    else
    {
        Element newElement;
        newElement.data = data;
        m_data.push_back(newElement);
        return (int)m_data.size() - 1;
    }
}

template <typename T>
void IndexFreeList<T>::Remove(const int index)
{
    m_data[index].next = m_firstFree;
    m_firstFree = index;
}

template <typename T>
T &IndexFreeList<T>::operator[](const int index)
{
    return m_data[index].data;
}

template <typename T>
void IndexFreeList<T>::Clear()
{
    m_data.clear();
    m_firstFree = -1;
}