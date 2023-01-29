#ifndef HASH_MAP_H
#define HASH_MAP_H

#define l1 long long int
#include <bits/stdc++.h>
using namespace std;

template <typename T>

class node{
public:
    string key;
    T value;
    node *next;

    node(string key, T value){//Constructor
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    node (node &object){ //Copy Constructor
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    ~node(){ //Destructor
        node *head = this;
        while(head != NULL){
            node *currNode = head;
            head = head->next;
            delete currNode;
        }
    }
};

//Hash Table (Unordered Map)
template <typename T>
class hash_map{
public:
    int numOfElements, bucketSize;
    node<T> **arr_pointers;

    hash_map(){//Constructor
        this->bucketSize = 1;
        this->numOfElements = 0;
        this->arr_pointers = new node <T> *[this->bucketSize];
        this->arr_pointers[0] = NULL;
    }
    int hashFunction(string key) // hash function for hashing a string
    {
        int bucketIndex;
        l1 sum = 0, factor = 31;
        for (int i = 0; i < key.size(); i++)
        {

            sum = ((sum % this->bucketSize) + ((int(key[i])) * factor) % this->bucketSize) % this->bucketSize;
            factor = ((factor % INT16_MAX) * (31 % INT16_MAX)) % INT16_MAX;
        }

        bucketIndex = sum;
        return bucketIndex;
    }

    float getLoadFactor()
    {
        // number of elements in hash table / total numbers of buckets
        return (float)(this->numOfElements + 1) / (float)(this->bucketSize);
    }
    void rehashing()
    {
        int oldBucketSize = this->bucketSize;
        node<T> **temp = this->arr_pointers; // temp is hodling current array

        this->bucketSize = oldBucketSize * 2; // doubling the size of current capacity
        this->arr_pointers = new node<T> *[this->bucketSize]; // points to new array of doubled size

        for (int i = 0; i < this->bucketSize; i++)
        {
            arr_pointers[i] = NULL;
        }
        for (int i = 0; i < oldBucketSize; i++)
        {
            node<T> *currBucketHead = temp[i];
            while (currBucketHead != NULL)
            {
                this->insert(currBucketHead->key, currBucketHead->value);
                currBucketHead = currBucketHead->next;
            }
        }
        delete[] temp; // deleting old array from heap memory
        return;
    }

    void insert(string key, T value)
    {
        while (this->getLoadFactor() > 0.5f) // when load factor > 0.5
        {
            this->rehashing();
        }

        int bucketIndex = this->hashFunction(key);
        if (this->arr_pointers[bucketIndex] == NULL) // No linked lists exists in the bucket
        {
            node<T> *newNode = new node<T>(key, value);
            arr_pointers[bucketIndex] = newNode;
        }
        else // adding at the head of current linked list
        {
            node<T> *newNode = new node<T>(key, value);
            newNode->next = this->arr_pointers[bucketIndex];
            this->arr_pointers[bucketIndex] = newNode;
        }
        return;
    }

    int find(string key)
    {
        int bucketIndex = this->hashFunction(key); // getting bucket index
        node<T> *bucketHead = this->arr_pointers[bucketIndex];
        while (bucketHead != NULL) // searching in the linked list which is present at bucket for given key
        {
            if (bucketHead->key == key)
            {
                return bucketHead->value;
            }
            bucketHead = bucketHead->next; // moving to next node in linked list
        }
        cout << "Not found, try again :)" << endl; // when key is not matched...
        return -1;
    }

};



#endif // HASH_MAP_H
