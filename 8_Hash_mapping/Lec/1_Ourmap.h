#include <string>
using namespace std;
template <typename v>
class MapNode
{
public:
    string key;
    v value;
    MapNode *next;
    MapNode(string key, v value)
    {
        this->key = key;

        this->value = value;
        next = NULL;
    }
    ~MapNode()
    {
        delete next;
    }
};

template <typename v>
class ourmap
{
    MapNode<v> **buckets;
    int count;
    int numbuckets;

public:
    ourmap()
    {
        count = 0;
        numbuckets = 5;
        buckets = new MapNode<v> *[numbuckets];
        for (int i = 0; i < numbuckets; i++)
        {
            buckets[i] = NULL;
        }
    }
    ~ourmap()
    {
        for (int i = 0; i < numbuckets; i++)
        {
            delete buckets[i];
        }
        delete[] buckets;
    }
    int size()
    {
        return count;
    }

    // search

    v getvalue(string key)
    {
        int bucketIndex = getbucketIndex(key);
        MapNode<v> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

private:
    int getbucketIndex(string key)
    {
        int hashcode = 0;
        int currentcoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashcode += key[i] * currentcoeff;
            hashcode = hashcode % numbuckets;
            currentcoeff *= 37;
            currentcoeff = currentcoeff % numbuckets;
        }
        return hashcode % numbuckets;
    }
    void rehash()
    {
        MapNode<v> **temp = buckets;
        buckets = new MapNode<v> *[2 * numbuckets];
        for (int i = 0; i < 2 * numbuckets; i++)
        {
            buckets[i] = NULL;
        }
        int oldbucketcount = numbuckets;
        numbuckets *= 2;
        count = 0;
        for (int i = 0; i < oldbucketcount; i++)
        {
            MapNode<v> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                v value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        // delete []temp; only yeh bhi toh ho skata h 
        for (int i = 0; i < oldbucketcount; i++)
        {
            MapNode<v> *head = temp[i];
            delete head;
        }
        delete[] temp;
    }

public:
    void insert(string key, v value)
    {
        int bucketIndex = getbucketIndex(key);
        MapNode<v> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                head->value = value;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<v> *node = new MapNode<v>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        double loadfactor = (1.0 * count) / numbuckets;
        if (loadfactor > 0.7)
        {
            rehash();
        }
    }
    double getloadFactor()
    {
        return (1.0 * count) / numbuckets;
    }
    v remove(string key)
    {
        int bucketIndex = getbucketIndex(key);
        MapNode<v> *head = buckets[bucketIndex];
        MapNode<v> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next=head->next;
                    
                
                }
                v value = head->value;
                head->next == NULL; // IMportant bcz delete is made recurisive it will delete complete if it's next is not made null;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};