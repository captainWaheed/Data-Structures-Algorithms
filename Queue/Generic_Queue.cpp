#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;
template < class T >
    class Q {
        private:
            T Data[10];
        int front;
        int rear;
        int count;
        public:
            Q() {
                front = rear = count = 0;
            }
        bool isEmpty() {
            return (count == 0);
        }
        bool isFull() {
            return (count == 10);
        }
        void enQue(T);
        T deQue();
    };
template < class T >
    void Q < T > ::enQue(T x) {
        if (!isFull()) {
            Data[rear] = x;
            rear++;
            rear = rear % 10;
            count++;
        } else {
            cout << "\nSorry Q is Full ";
        }
    }
template < class T >
    T Q < T > ::deQue() {
        T temp;
        if (!isEmpty()) {
            temp = Data[front];
            front++;
            front = front % 10;
            count--;
        } else {
            cout << "\nSorry Q is Empty ";
            temp = -1;
        }
        return temp;
    }
// int main() {
//     Q < int > myQ;
//     cout << "\n Q Status " << myQ.isEmpty();
//     myQ.enQue(10);
//     myQ.enQue(20);
//     myQ.enQue(30);
//     myQ.enQue(40);
//     cout << "\n Q Status " << myQ.isEmpty();
//     cout << "\n" << myQ.deQue();
//     cout << "\n" << myQ.deQue();
//     myQ.enQue(50);
//     myQ.enQue(60);
//     myQ.enQue(70);
//     myQ.enQue(80);
//     myQ.enQue(90);
//     myQ.enQue(100);
//     myQ.enQue(110);
//     myQ.enQue(120);
//     myQ.enQue(130);
//     myQ.enQue(140);
//     for (int i = 0; i <= 10; i++)
//         cout << "\n" << myQ.deQue();
//     myQ.enQue(555);
//     myQ.enQue(666);
//     cout << "\n" << myQ.deQue();
//     cout << "\n" << myQ.deQue();
//     cout << "\n\n\nNow using Character based Queue";
//     Q < char > myQ2;
//     cout << myQ2.deQue();
//     myQ2.enQue('A');
//     myQ2.enQue('B');
//     myQ2.enQue('C');
//     for (int i = 0; i <= 2; i++)
//         cout << "\n" << myQ2.deQue();
//     Q < float > myQ3;
//     myQ3.enQue(3.1415);
//     cout << "\n";
//     cout << myQ3.deQue();
//     getch();
// }
