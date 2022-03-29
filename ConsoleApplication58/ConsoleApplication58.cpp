#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
class List
{
private:
    Node* head; //"голова" связанного списка
public:
    List() //конструктор класса без параметров
    {
        head = NULL; //первого элемента пока нет
    }
    //метод, добавляющий новый узел в список
    void addNode(int d)
    {
        Node* nd = new Node; //динамически создаем новый узел
        nd->data = d;        //задаем узлу данные
        nd->next = NULL;     //новый узел в конце, поэтому NULL
        if (head == NULL)     //если создаем первый узел
            head = nd;
        else                 //если узел уже не первый
        {
            Node* current = head;
            //ищем в цикле предшествующий последнему узел
            while (current->next != NULL)
                current = current->next;
            //предшествующий указывает на последний
            current->next = nd;
        }
    }
    //метод, выводящий связанный список на экран
    void printList()
    {
        if (head == NULL)
            cout << "List is empty!";
        Node* current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }

    void pos_nums(List& L1, List& L2)
    {
        Node* current = head;
        while (current != NULL)
        {
            //cout << "e";
            if (current->data > 0)
                L1.addNode(current->data);
            else
                L2.addNode(current->data);
            current = current->next;
        }
    }

    void remove_neg() {
        Node* current = head;

        while (head->data<0 and head->next!=NULL)
            head = head->next;

        if (head->next == NULL)
            head = NULL;

        while (current != NULL)
        {
            if (current->next != nullptr and current->next->data<0)
                current->next = current->next->next;
            else
                current = current->next;
        }
    }

    void max_to_begin()
    {
        int maxx = head->data;
        Node* current = head->next;
        while (current != NULL)
        {
            if (maxx < current->data)
                maxx = current->data;
            current = current->next;
        }

        Node* newmax = new Node;
        newmax->data = maxx;
        newmax->next = head;
        head = newmax;

        current = head;
        while (current->next->data != maxx) {
            current = current->next;
        }
        current->next = current->next->next;
    }
};




int main()
{
    //диапазон генерации случайных чисел [a,b]
    int a = -99;
    int b = 99;
    int N = 10; //количество чисел в списке

    List L;
    List L1;
    List L2;

    srand(time(NULL));
    //заполнение списка случайными числами
    for (int i = 0; i < N; i++)
    {
        int x = rand() % (b - a + 1) + a;
        L.addNode(x);
    }

    L.pos_nums(L1, L2);

    //вывод первоначального созданного списка
    cout << "Randomly created first list:" << endl;
    L.printList();

    cout << endl << endl;

    cout << "Second list with only positiv numbers from first list:" << endl;
    L1.printList();

    cout << endl << endl;

    L1.max_to_begin();

    cout << "Second list after moving the node with max value to the beginning:" << endl;
    L1.printList();

    cout << endl << endl;

    cout << "Third list of all other numbers not included in the second list:" << endl;
    L2.printList();

    cout << endl << endl;

    L2.remove_neg();

    cout << "Third list after removing all negative numbers (only zeros):" << endl;
    L2.printList();

    cout << endl;
    return 0;
}