struct Stack
{
	int data;
	int num;			//информационный элемент
	Stack* head;		 //вершина стека 
	Stack* next;		 //указатель на следующий элемент
};

void show(Stack* myStk);         //прототип
void push(int x, int i, Stack* myStk);  //прототип
int fromFile(Stack* myStk);
int myFunct(Stack* myStk);