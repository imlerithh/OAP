//13
//��� ��������� p1 �� ������ ��������� ������. �������� �������, � ������� �����, ������� � �������� ������,
//������� ����� ���������� ������. �������, ��� ������� ������ �� ����������� 10.
//14
//������� ��������� ������ �������� ���� � ��� ��������� �� ��������. �������� ������� ���������� �������� ��������������� ���� ��������� ������.
//12
//��� ��������� p1 �� ������ ��������� ������. �������� ������� ����������� ���������� ����� � ������� �������.
//15
//������� ��������� ������ �������� ����, ������ � ��� ��������� �� ��������. �������� ������� ����������� ���������� ����� ������ ����� ������.
#include <iostream>
using namespace std;
int tabs = 0; //��� �������� ��������

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

Branch* deleteElement(Branch* Root, int data)  //�������� �������� �� �����
{	// Del, Prev_Del - ��������� ������� � ��� ���������� ;
    // R, Prev_R - �������, �� ������� ���������� ���������, � ��� ��������; 
    Branch* Del, * Prev_Del, * R, * Prev_R;
    Del = Root;
    Prev_Del = NULL;
    while (Del != NULL && Del->Data != data)//����� �������� � ��� �������� 
    {
        Prev_Del = Del;
        if (Del->Data > data)
            Del = Del->LeftBranch;
        else
            Del = Del->RightBranch;
    }
    if (Del == NULL)              // ������� �� ������
    {
        puts("\n��� ������ ��������");
        return Root;
    }
    if (Del->RightBranch == NULL) // ����� �������� R ��� ������
        R = Del->LeftBranch;
    else
        if (Del->LeftBranch == NULL)
            R = Del->RightBranch;
        else
        {
            Prev_R = Del; //����� ������ ������� �������� � ����� ���������
            R = Del->LeftBranch;
            while (R->RightBranch != NULL)
            {
                Prev_R = R;
                R = R->RightBranch;
            }
            if (Prev_R == Del) // ������ ������� ��� ������ R � ��� �������� Prev_R 
                R->RightBranch = Del->RightBranch;
            else
            {
                R->RightBranch = Del->RightBranch;
                Prev_R->RightBranch = R->LeftBranch;
                R->LeftBranch = Prev_R;
            }
        }
    if (Del == Root) Root = R;	//�������� ����� � ������ ��� �� R
    else
        // ��������� R �������������� � �������� ���������� ����
        if (Del->Data < Prev_Del->Data)
            Prev_Del->LeftBranch = R; // �� ����� ����� 
        else
            Prev_Del->RightBranch = R;	// �� ������ �����
    int tmp = Del->Data;
    cout << "\n������ ������� �� ��������� " << tmp << endl;
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

int task13(Branch* tree) // ������� ������ � ������
{
    if (NULL == tree) return 0;
    return 1 + task13(tree->LeftBranch) + task13(tree->RightBranch);
}

int task14(Branch* tree) // ������� ��������������
{
    if (NULL == tree) return 0;
    return tree->Data + task14(tree->LeftBranch) + task14(tree->RightBranch);
}

int task15(Branch* root, int depth, int data) // ���������� ����� ������ �����
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
        cout << "1 - �������� ������ �������\n";
        cout << "2 - �������� ��������\n";
        cout << "3 - ����� ������\n";
        cout << "4 - ������� ���������� ������(13)\n";
        cout << "5 - ������� �������� ��������������� ���� ���������(14)\n";
        cout << "6 - ������� ���������� ����� ������ �����(15)\n";
        cout << "7 - ������� ���������� ����� � ������� �������(12)\n";
        cout << "8 - ������� ������\n";
        cout << "0 - �����\n";
        cout << "������� �������: ", cin >> choice; cout << endl;
        switch (choice)
        {
        case 1:  cout << "����� ����� - 0\n";
            do { cout << "\n������� ��������: "; cin >> data; Add(data, Root); } while (data != 0);
            break;
        case 2:  cout << "\n������� ��������� �������: ", cin >> data;
            Root = deleteElement(Root, data);  break;
        case 3:     if (Root == nullptr) cout << "������ ������\n";
              else {
            cout << "  1";
            for (int i = 2; i < 11; i++) {
                cout << " " << i;
            }
            cout << endl << endl;
            print(Root);
        }
              break;
        case 4:	cout << "���������� ������ � ������ �����: " << task13(Root) << endl; break;
        case 5: cout << "������� �������������� ���� ���������: " << (float)task14(Root) / task13(Root) << endl; break;
        case 6: cout << "���������� ����� ������ ����� ������: " << task15(Root, 0, Root->Data) << endl; break;
        case 7: cout << "���������� ����� � ������� �������: " << task12(Root) << endl; break;
        case 8:  Root = FreeTree(Root); break;
        case 0:  exit(0);
        }
    }
    return 0;
}