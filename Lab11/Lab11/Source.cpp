//13
//Дан указатель p1 на корень непустого дерева. Написать функцию, в которой нужно, начиная с нулевого уровня,
//вывести сумму количество вершин. Считать, что глубина дерева не превосходит 10.
//14
//Вершина бинарного дерева содержит ключ и два указателя на потомков. Написать функцию вычисления среднего арифметического всех элементов дерева.
//12
//Дан указатель p1 на корень непустого дерева. Написать функцию определения количества узлов с четными ключами.
//15
//Вершина бинарного дерева содержит ключ, строку и два указателя на потомков. Написать функцию определения количества узлов правой ветви дерева.
#include <iostream>
using namespace std;
int tabs = 0; //Для создания отступов

struct Branch
{
    int Data;
    Branch* LeftBranch;
    Branch* RightBranch;
};

void Add(int aData, Branch*& aBranch)
{
    if (aData == 0) return;
    if (!aBranch)
    {
        aBranch = new Branch;
        aBranch->Data = aData;
        aBranch->LeftBranch = nullptr;
        aBranch->RightBranch = nullptr;
        return;
    }
    else
        if (aBranch->Data > aData)
        {
            Add(aData, aBranch->LeftBranch);
        }
        else
        {
            Add(aData, aBranch->RightBranch);
        };
}

Branch* deleteElement(Branch* Root, int data)  //Удаление элемента по ключу
{	// Del, Prev_Del - удаляемый элемент и его предыдущий ;
    // R, Prev_R - элемент, на который заменяется удаленный, и его родитель; 
    Branch* Del, * Prev_Del, * R, * Prev_R;
    Del = Root;
    Prev_Del = NULL;
    while (Del != NULL && Del->Data != data)//поиск элемента и его родителя 
    {
        Prev_Del = Del;
        if (Del->Data > data)
            Del = Del->LeftBranch;
        else
            Del = Del->RightBranch;
    }
    if (Del == NULL)              // элемент не найден
    {
        puts("\nНет такого элемента");
        return Root;
    }
    if (Del->RightBranch == NULL) // поиск элемента R для замены
        R = Del->LeftBranch;
    else
        if (Del->LeftBranch == NULL)
            R = Del->RightBranch;
        else
        {
            Prev_R = Del; //поиск самого правого элемента в левом поддереве
            R = Del->LeftBranch;
            while (R->RightBranch != NULL)
            {
                Prev_R = R;
                R = R->RightBranch;
            }
            if (Prev_R == Del) // найден элемент для замены R и его родителя Prev_R 
                R->RightBranch = Del->RightBranch;
            else
            {
                R->RightBranch = Del->RightBranch;
                Prev_R->RightBranch = R->LeftBranch;
                R->LeftBranch = Prev_R;
            }
        }
    if (Del == Root) Root = R;	//удаление корня и замена его на R
    else
        // поддерево R присоединяется к родителю удаляемого узла
        if (Del->Data < Prev_Del->Data)
            Prev_Del->LeftBranch = R; // на левую ветвь 
        else
            Prev_Del->RightBranch = R;	// на правую ветвь
    int tmp = Del->Data;
    cout << "\nУдален элемент со значением " << tmp << endl;
    delete Del;
    return Root;
}

void print(Branch* aBranch)
{
    if (!aBranch) return;
    tabs++;

    print(aBranch->RightBranch);

    for (int i = 0; i < tabs; i++) cout << "  ";
    cout << aBranch->Data << endl;

    print(aBranch->LeftBranch);

    tabs--;
    return;
}

Branch* FreeTree(Branch* aBranch)
{
    if (!aBranch) return NULL;
    FreeTree(aBranch->LeftBranch);
    FreeTree(aBranch->RightBranch);
    Branch* temp = aBranch;
    aBranch = nullptr;
    delete temp;
    return aBranch;
}

int task13(Branch* tree) // подсчет вершин в дереве
{
    if (NULL == tree) return 0;
    return 1 + task13(tree->LeftBranch) + task13(tree->RightBranch);
}

int task14(Branch* tree) // среднее арифметическое
{
    if (NULL == tree) return 0;
    return tree->Data + task14(tree->LeftBranch) + task14(tree->RightBranch);
}

int task15(Branch* root, int depth, int data) // количество узлов правой ветви
{
    static int count = 0;

    if (root == NULL)
        return 0;
    else {
        task15(root->LeftBranch, ++depth, data);
        if (root->Data > data)
            count++;
        depth--;
    }
    task15(root->RightBranch, ++depth, data);

    return count;
}

int task12(Branch* root)
{
    static int count = 0;
    if (root != NULL)
    {
        if (root->Data % 2 == 0)
            count++;
        task12(root->LeftBranch);
        task12(root->RightBranch);
        return count;
    }
}

int main()
{
    setlocale(0, "Russian");
    int data, choice, n;
    Branch* Root = nullptr;
    while (true) {
        cout << "1 - добавить дереву элемент\n";
        cout << "2 - удаление элемента\n";
        cout << "3 - вывод дерева\n";
        cout << "4 - подсчет количества вершин(13)\n";
        cout << "5 - подсчет среднего арифметического всех элементов(14)\n";
        cout << "6 - подсчет количества узлов правой ветви(15)\n";
        cout << "7 - подсчет количества узлов с четными ключами(12)\n";
        cout << "8 - очистка дерева\n";
        cout << "0 - выход\n";
        cout << "Введите команду: ", cin >> choice; cout << endl;
        switch (choice)
        {
        case 1:  cout << "Конец ввода - 0\n";
            do { cout << "\nВведите значение: "; cin >> data; Add(data, Root); } while (data != 0);
            break;
        case 2:  cout << "\nВведите удаляемый элемент: ", cin >> data;
            Root = deleteElement(Root, data);  break;
        case 3:     if (Root == nullptr) cout << "Дерево пустое\n";
              else {
            cout << "  1";
            for (int i = 2; i < 11; i++) {
                cout << " " << i;
            }
            cout << endl << endl;
            print(Root);
        }
              break;
        case 4:	cout << "Количество вершин в дереве равна: " << task13(Root) << endl; break;
        case 5: cout << "Среднее арифметическое всех элементов: " << (float)task14(Root) / task13(Root) << endl; break;
        case 6: cout << "Количество узлов правой ветви дерева: " << task15(Root, 0, Root->Data) << endl; break;
        case 7: cout << "Количество узлов с четными ключами: " << task12(Root) << endl; break;
        case 8:  Root = FreeTree(Root); break;
        case 0:  exit(0);
        }
    }
    return 0;
}