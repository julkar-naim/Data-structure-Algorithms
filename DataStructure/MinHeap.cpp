#include <iostream>
using namespace std;



template<class T>
class MinHeap{
private:
    int _capacity, _root, _right;
    T *_arr;
    int _leftChild (int idx) {
        return idx * 2;
    }
    int _rightChild (int idx) {
        return (idx * 2) + 1;
    }
    int _parent (int idx) {
        return idx / 2;
    }
public:
    MinHeap (int size) {
        _capacity = size;
        _arr = new T[_capacity+2];
        _root = 1, _right = 0;
    }
    int size () { return _right; }
    bool isEmpty () { return _right < _root; }
    void insert (T data) {
        if (_right+1 == _capacity+1) {
            cout << "Overflow" << endl;
            return;
        }
        _arr[++_right] = data;
        int temp = _right;

        while (_parent(temp) != 0 && _arr[temp] < _arr[_parent(temp)]) {
            swap(_arr[temp], _arr[_parent(temp)]);
            temp = _parent(temp);
        }
    }
    int remove () {
        T ret = _arr[_root];
        swap(_arr[_root], _arr[_right]);
        _right--;
        int temp = _root;
        while (true) {
            int left = _leftChild(temp);
            int right = _rightChild(temp);
            if (left > _right) break; // If left child doesn't exist
            if (right > _right) {        // If right child doesn't exist
                if (_arr[left] < _arr[temp]) {
                    swap(_arr[temp], _arr[left]);
                    temp = left;
                }
                else break;
            }
            else {
                if (_arr[left] < _arr[right] && _arr[left] < _arr[temp]) {
                    swap(_arr[left], _arr[temp]);
                    temp = left;
                }
                else if (_arr[right] < _arr[left] && _arr[right] < _arr[temp]) {
                        swap(_arr[right], _arr[temp]);
                        temp = right;
                }
                else break;
            }
        }
        return ret;
    }
};

int main () {
    MinHeap<int> hp(10);
    for (int i = 0; i < 10; i++)
        hp.insert(rand() % 100);

    cout << hp.size() << endl << endl;
    while (!hp.isEmpty()) {
        cout << hp.remove() << endl;
    }
}
