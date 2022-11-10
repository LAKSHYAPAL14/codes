using namespace std;
template <typename T>
class queueusingarray
{
    T *data;
    int nextindex;
    int firstindex;
    int size;
    int capacity;

public:
    queueusingarray(int s)
    {
        data = new T[s];
        nextindex = 0;
        firstindex = -1;
        size = 0;
        capacity = s;
    }
    int getsize()
    {
        return size;
    }
    bool isempty()
    {
        return size == 0;
    }
    void enqueue(T element)
    {
        if (size == capacity)
        {
            T*newdata=new T[2*capacity];
            int j=0;
            for(int i=firstindex ;i<capacity ; i++)
            {
                newdata[j]=data[i];
                j++;
            }
            for(int i=0 ; i<firstindex ; i++)
            {
                newdata[j]=data[i];
                j++;
            }
            delete[] data;
            data=newdata;
            firstindex=0;
            nextindex=capacity;
            capacity*=2;
        }
        data[nextindex] = element;
        nextindex = (nextindex + 1) % capacity;
        if (firstindex == -1)
        {
            firstindex = 0;
        }
        size++;
    }
    T front()
    {
        if (isempty())
        {
            cout << " queue is empty " << endl;
            return 0;
        }
        return data[firstindex];
    }
    T dequeue()
    {
        if (isempty())
        {
            cout << " queue is empty " << endl;
            return 0;
        }
        T ans = data[firstindex];
        size--;
        firstindex = (firstindex + 1) % capacity;
        if (size == 0) // although it is not necessary it
        {              // resetting to default values when queue gets empty
            firstindex = -1;
            nextindex = 0;
        }
        return ans;
    }
};