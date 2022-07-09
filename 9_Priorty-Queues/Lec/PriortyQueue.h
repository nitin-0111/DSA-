#include <vector>
using namespace std;
class PriortyQueue
{
    vector<int> pq;

public:
    PriortyQueue()
    {
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getsize()
    {
        return pq.size();
    }
    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }
    void insert_min(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
            {
                swap(pq[childIndex], pq[parentIndex]);
                childIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    int removeMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        while (parentIndex < pq.size())
        {
            int childIndex_1 = 2 * parentIndex + 1;
            int childIndex_2 = 2 * parentIndex + 2;
            if (pq[parentIndex] > pq[childIndex_2] || pq[parentIndex] > pq[childIndex_1])
            {
                int minchild = min(pq[childIndex_1], pq[childIndex_2]);
                if (minchild == pq[childIndex_1])
                    {
                        swap(pq[parentIndex], pq[childIndex_1]);
                        parentIndex = childIndex_1;
                    }
                else
                {
                    swap(pq[parentIndex], pq[childIndex_2]);
                    parentIndex = childIndex_2;
                }
            }
            else
                break;
        }
        return ans;
    }

    //
    //              MAX PRIORTY QUEUE
    //
    int getmax()
    {
        if (isEmpty())
        {
            return 0;
        }
        return pq[0];
    }
    void insert_max(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] > pq[parentIndex])
            {
                swap(pq[childIndex], pq[parentIndex]);
                childIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    int removeMax()
    {
        if (isEmpty())
        {
            return 0;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        int parentIndex = 0;
        while (parentIndex < pq.size()-1)
        {
            int childIndex_1 = 2 * parentIndex + 1;
            int childIndex_2 = 2 * parentIndex + 2;

            if (pq[parentIndex] < pq[childIndex_2] || pq[parentIndex] < pq[childIndex_1])
            {
                int maxchild = max(pq[childIndex_1], pq[childIndex_2]);
                if (maxchild == pq[childIndex_1])
                {
                    swap(pq[parentIndex], pq[childIndex_1]);
                    parentIndex = childIndex_1;
                }
                else
                {
                    swap(pq[parentIndex], pq[childIndex_2]);
                    parentIndex = childIndex_2;
                }
            }
            else
                break;
        }
        return ans;
    }
    void print()
    {
        for (auto x : pq)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};
