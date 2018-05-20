#include <iostream>

#include "Heap.h"
#include "Node.h"

int main()
{
	Heap heap;

	std::cout << "Testing Heap!" << std::endl;
	std::cout << "Inserting 1!" << std::endl;
	heap.Insert(1);
	std::cout << "Inserting 2!" << std::endl;
	heap.Insert(2);
	std::cout << "Inserting 3!" << std::endl;
	heap.Insert(3);

	std::cout << "Heap done" << std::endl;
	heap.ViewHeap();
	system("pause");

	//heap.Insert(15);
	//heap.Insert(14);
	// heap.Insert(30);
	// heap.Insert(16);

	heap.RemoveFirst();
	heap.ViewHeap();
	heap.RemoveFirst();
	heap.ViewHeap();
	heap.RemoveFirst();
	heap.ViewHeap();
	/*heap.RemoveFirst();
	heap.ViewHeap();
	heap.RemoveFirst();
	heap.ViewHeap();
	heap.RemoveFirst();
	heap.ViewHeap();
	heap.RemoveFirst();
	heap.ViewHeap();
	heap.RemoveFirst();
	heap.ViewHeap();*/

	heap.ViewHeap();

	//system("pause");


	return 0;
}