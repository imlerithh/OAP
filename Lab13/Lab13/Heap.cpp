#include "Heap.h"

void AAA::print()
{
	std::cout << x;
}
int AAA::getPriority() const
{
	return x;
}
int l = 10000000;
int z = -1;       //переменная для минимального
int y = 0;       //ключ минимального
int i = 0;
int p[60];

int arr(int count)
{
	return p[count];
}

namespace heap
{
	int h = 0;

	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix)
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix]))
				irl = l;

			if (r > 0 && isGreat(storage[r], storage[irl]))
				irl = r;

			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}
	void Heap::insert(void* x)
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}

	void Heap::scan(int i) const     //Вывод значений элементов на экран
	{
		int probel = 20;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		std::cout << '\n';
	}

	//////////////////////////////////////////////////////////////

	void Heap::scanx1()
	{
		cout << '\n';
		if (size == 0)
			cout << "Куча пуста";
		for (int u = 0; u < size; u++)
		{
			p[i] = ((AAA*)storage[u])->x;
			i++;
		}
	}

	//Минимальный
	void Heap::scan2()
	{
		if (size == 0)
			cout << "Куча пуста";
		for (int u = 0; u < size; u++)
		{
			z++;
			if (l > ((AAA*)storage[u])->x)
			{
				l = ((AAA*)storage[u])->x;
				y = z;
			}
		}
		cout << "\nМинимальный элемент: " << l << endl;
	}

	void* Heap::extractMin()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[y];
			storage[y] = storage[size - 1];
			size--;
			heapify(0);
		};
		l = 100000000000;
		z = -1;
		return rc;
	}

	//i-ый элемент
	void* Heap::ielem(int l)
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[l];
			storage[l] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}

	////////////////////////////////////////////////////

	// Среднее значение
	void Heap::average()
	{
		double temp;
		if (size == 0)
			cout << "Куча пуста";
		int sum = 0;
		int counter = 0;
		for (int u = 0, y = 0; u < size; u++)
		{
			sum = sum + ((AAA*)storage[u])->x;
			counter++;
		}
		temp = sum / counter;
		cout << "\nСреднее арифметическое: " << temp << endl;
	}

	void Heap::amount()
	{
		if (size == 0)
			cout << "Куча пуста";
		int counter = 0;
		for (int u = 0, y = 0; u < size; u++)
		{
			counter++;
		}
		cout << "\nКоличество элементов: " << counter << endl;
	}

	void Heap::even()
	{
		if (size == 0)
			cout << "Куча пуста";
		int counter = 0;
		for (int u = 0, y = 0; u < size; u++)
		{
			if (((AAA*)storage[u])->x % 2 == 0)
			{
				counter++;
			}
		}
		cout << "\nКоличество чётных: " << counter << endl;
	}
}
