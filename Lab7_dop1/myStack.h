struct Stack
{
	char data;
	            //�������������� �������
	Stack* head;		 //������� ����� 
	Stack* next;		 //��������� �� ��������� �������
};

void show(Stack* myStk);         //��������
int myFunc(Stack* mySck);
void push(char x, Stack* myStk);