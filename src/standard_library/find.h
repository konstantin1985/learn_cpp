/*
 * find.h
 *
 *  Created on: Nov 27, 2015
 *      Author: konstantin
 */

#ifndef FIND_H_
#define FIND_H_

//http://stackoverflow.com/questions/571394/how-to-find-an-item-in-a-stdvector
//http://www.cplusplus.com/reference/algorithm/find_if/


/*
 * sortedlist.h
 *
 *  Created on: 04.10.2013
 *      Author: shmykov
 */

#ifndef SORTEDLIST_H_
#define SORTEDLIST_H_



#include <set>


typedef enum {
    PH_SUCCESS = 0,
    PH_FAILURE
} PH_RC_t;

template<typename T>
class SortedList
{
    std::set<T> __sortedList;

public:
    typedef typename std::set<T>::const_iterator ConstIterator;
        bool operator == (const ConstIterator &iterator) const;

    SortedList();
    ~SortedList();

    PH_RC_t Add(const T &object);
    PH_RC_t Remove(const T &object);

    static SortedList GetUnion(const SortedList &first, const SortedList &second);
    static SortedList GetDifference(const SortedList &first, const SortedList &second);

    ConstIterator Begin() const
    {
        return __sortedList.begin();
    }

    ConstIterator End() const
    {
        return __sortedList.end();
    }

    bool IsMember(const T &object) const;
    int GetCount() const;

    bool IsEmpty() const;

    void Clear();
};

template<typename T>
SortedList<T>::SortedList()
{
    this->Clear();
}

template<typename T>
SortedList<T>::~SortedList()
{
    this->Clear();
}

template<typename T>
PH_RC_t SortedList<T>::Add(const T &object)
{
    if (__sortedList.count(object) != 0) {
        return PH_FAILURE;
    }

    __sortedList.insert(object);

    return PH_SUCCESS;
}

template<typename T>
PH_RC_t SortedList<T>::Remove(const T &object)
{
    if (__sortedList.erase(object) == 0) {
        return PH_FAILURE;
    }

    return PH_SUCCESS;
}

template<typename T>
SortedList<T> SortedList<T>::GetUnion(const SortedList<T> &first, const SortedList<T> &second)
{
    SortedList<T> result = first;
    ConstIterator iter;
    for (iter = second.Begin(); iter != second.End(); iter++) {
        result.Add(*iter);
    }
    return result;
}

template<typename T>
SortedList<T> SortedList<T>::GetDifference(const SortedList<T> &first, const SortedList<T> &second)
{
    SortedList<T> result = first;
    ConstIterator iter;
    for (iter = second.Begin(); iter != second.End(); iter++) {
        result.Remove(*iter);
    }
    return result;
}

template<typename T>
bool SortedList<T>::IsMember(const T &object) const
{
    return (__sortedList.count(object) != 0);
}

template<typename T>
int SortedList<T>::GetCount() const
{
    return __sortedList.size();
}

template<typename T>
bool SortedList<T>::IsEmpty() const
{
    return __sortedList.empty();
}

template<typename T>
void SortedList<T>::Clear()
{
    __sortedList.clear();
}

#endif /* SORTEDLIST_H_ */




#endif /* FIND_H_ */
