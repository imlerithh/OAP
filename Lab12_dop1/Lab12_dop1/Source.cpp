#include <iostream>
constexpr auto STR_LEN = 16;
using namespace std;
int tabs = 0; //��� �������� ��������

struct PhoneUser
{
    char name[STR_LEN];
    char phoneNumber[STR_LEN];
    char network[STR_LEN];
    PhoneUser* LeftPhoneUser;
    PhoneUser* RightPhoneUser;
};

void Add(char name[], char phoneNumber[], char network[], PhoneUser*& aPhoneUser)
{
    if (!aPhoneUser)
    {
        aPhoneUser = new PhoneUser;
        for (int i = 0; i < strlen(name); i++) {
            aPhoneUser->name[i] = name[i];
        }
        aPhoneUser->name[strlen(name)] = '\0';
        for (int i = 0; i < strlen(phoneNumber); i++) {
            aPhoneUser->phoneNumber[i] = phoneNumber[i];
        }
        aPhoneUser->phoneNumber[strlen(phoneNumber)] = '\0';
        for (int i = 0; i < strlen(network); i++) {
            aPhoneUser->network[i] = network[i];
        }
        aPhoneUser->network[strlen(network)] = '\0';
        aPhoneUser->LeftPhoneUser = nullptr;
        aPhoneUser->RightPhoneUser = nullptr;
        return;
    }
    else
        if (aPhoneUser->name[0] >= name[0])
        {
            Add(name, phoneNumber, network, aPhoneUser->LeftPhoneUser);
        }
        else
        {
            Add(name, phoneNumber, network, aPhoneUser->RightPhoneUser);
        };
}

PhoneUser* search(PhoneUser* aPhoneUser, char* phoneNumber)
{   
    PhoneUser* temp = NULL;
    if (!aPhoneUser) return NULL;
    if (strcmp(aPhoneUser->phoneNumber, phoneNumber)==0) return aPhoneUser;
    temp = search(aPhoneUser->RightPhoneUser, phoneNumber);
    if(temp==NULL) temp = search(aPhoneUser->LeftPhoneUser, phoneNumber);

    return temp;
}


void print(PhoneUser* aPhoneUser)
{
    if (!aPhoneUser) return;
    tabs++;

    print(aPhoneUser->RightPhoneUser);

    for (int i = 0; i < tabs; i++) cout << "   ";
    cout << aPhoneUser->name << endl;

    print(aPhoneUser->LeftPhoneUser);

    tabs--;
    return;
}

PhoneUser* FreeTree(PhoneUser* aPhoneUser)
{
    if (!aPhoneUser) return NULL;
    FreeTree(aPhoneUser->LeftPhoneUser);
    FreeTree(aPhoneUser->RightPhoneUser);
    PhoneUser* temp = aPhoneUser;
    aPhoneUser = nullptr;
    delete temp;
    return aPhoneUser;
}

int amountOfBranches(PhoneUser* tree) // ������� ������ � ������
{
    if (NULL == tree) return 0;
    return 1 + amountOfBranches(tree->LeftPhoneUser) + amountOfBranches(tree->RightPhoneUser);
}

int networkDistribution(PhoneUser* tree, char network[])
{
    if (NULL == tree) return 0;
    bool m = 1;
    for (int i = 0; i < strlen(tree->network); i++) {
        if (tree->network[i] != network[i]) {
            m = 0; break;
        }
    }
    return m + networkDistribution(tree->LeftPhoneUser, network) + networkDistribution(tree->RightPhoneUser, network);
}



int main()
{
    setlocale(0, "Russian");
    int choice, mtc, life;
   char name[STR_LEN], phoneNumber[STR_LEN], network[STR_LEN];
    char mtcString[3],  lifeString[4];
    mtcString[0] = 'm'; mtcString[1] = 't'; mtcString[2] = 'c';
    lifeString[0] = 'l'; lifeString[1] = 'i'; lifeString[2] = 'f'; lifeString[3] = 'e';
    PhoneUser* Root = nullptr;
    PhoneUser* temp = nullptr;
    while (true) {
        cout << "1 - �������� ������ �������\n";
        cout << "2 - ����� �� ������\n";
        cout << "3 - ����� ������\n";
        cout << "4 - ������ ���������� ��������� �� ����������\n";
        cout << "5 - ������� ������\n";
        cout << "0 - �����\n";
        cout << "������� �������: ", cin >> choice; cout << endl;
        switch (choice)
        {
        case 1:  
            cout << "\n������� ���: "; cin >> name; cout << "\n������� ����� ��������: "; cin >> phoneNumber;  cout << "\n������� ���������: "; cin >> network; 
            Add(name, phoneNumber, network, Root);
            break;
        case 2:  cout << "\n������� ����� ��������: ", cin >> phoneNumber;
            temp = search(Root, phoneNumber);
            if (temp) {
                cout << "��� ��������: " << temp->name << endl;
                cout << "�������� ��������: " << temp->network << endl;
            }
            else cout << "�������� � ����� ������� � ���� ������ ���" << endl;
            break;
        case 3:     if (Root == nullptr) cout << "������ ������\n";
              else {
            cout << endl << endl;
            print(Root);
        }
              break;
        case 4:	mtc = networkDistribution(Root, mtcString); life = networkDistribution(Root, lifeString);

            cout << "���������� ���������: "; cout << "MTC - " << mtc << " ���������" << endl;
            cout << "Life - " << life << " ���������";
            cout << endl << "������ - " << amountOfBranches(Root) - life - mtc << " ���������" << endl; break;
        case 5:  Root = FreeTree(Root); break;
        case 0:  exit(0);
        }
    }
    system("pause");
    return 0;
}