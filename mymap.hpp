//
// Created by HP User on 11/26/2018.
//

#ifndef MIDTERM2_MYMAP_HPP
#define MIDTERM2_MYMAP_HPP
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <class K = string, class V = int>
class MyMap {
private:
    vector<pair<K, V>> container;
public:
    bool add(K key, V value){
        return add(pair<K, V>(key, value));
    }
    bool add(pair<K, V> element){
        bool newEntry = true;
        auto it = container.begin();
        for(; it != container.end(); ++it){
            if(it->first == element.first){
                it->second = element.second;
                newEntry = false;
            }
        }
        if(newEntry){
            container.push_back(element);
            sortContainer();
        }
        return newEntry;
    }
    void sortContainer(){
        sort(container.begin(), container.end(),
             [](const pair<K, V>& p1, const pair<K, V>& p2){
                 return (string)(p1.first) < (string)(p2.first);
             });
    }
    vector<V> getValues(){
        vector<V> values;
        for(auto it = container.begin(); it != container.end(); ++it){
            values.push_back(it->second);
        }
        return values;
    }
    pair<K, V>& operator[](int index){
        return container[index];
    }
    pair<K, V>& operator[](K key){
        auto it = container.begin();
        for(it = container.begin(); it != container.end(); ++it){
            if(it->first == key){
                return *it;
            }
        }
        it++;
        return *it;
    }
    friend ostream& operator<<(ostream& os, const MyMap& mm){
        for(auto it = mm.container.begin(); it != mm.container.end(); ++it){
            os << it->first << ": " << it->second << endl;
        }
        return os;
    }
};


#endif //MIDTERM2_MYMAP_HPP
