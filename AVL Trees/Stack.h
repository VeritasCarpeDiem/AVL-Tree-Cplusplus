#pragma once
#include <memory>
template<typename T>
class Stack
{
private:
	size_t capacity = 5;
	size_t minimumCapacity = 5;
	std::unique_ptr<T[]> data;
	void EnsureCapacity();
public:
	Stack();
	~Stack();

	size_t count = 0;

	void Push(T value);

	T Pop();

	T Peek();

	void Clear();

	bool isEmpty();


};

template<typename T>
void Stack<T>::EnsureCapacity()
{
	if (capacity == count)
	{
		capacity = 2 * capacity;
		std::unique_ptr<T[]> temp = std::make_unique<T[]>(capacity);
		for (size_t i = 0; i < capacity / 2; i++)
		{
			temp[i] = data[i];
		}
		data = std::move(temp);
	}

	if (capacity > minimumCapacity && count <= capacity / 4)
	{
		capacity = capacity / 2;
		std::unique_ptr<T[]> temp = std::make_unique<T[]>(capacity);
		for (size_t i = 0; i < capacity / 2; i++)
		{
			temp[i] = data[i];
		}

		data = std::move(temp);
	}
}
template<typename T>
Stack<T>::Stack()
{
	data = std::make_unique<T[]>(minimumCapacity);
}
template<typename T>
Stack<T>::~Stack()
{
	Clear();
}
template<typename T>
void Stack<T>::Push(T value)
{
	EnsureCapacity();
	data[count] = value;

	count++;
}
template<typename T>
T Stack<T>::Pop()
{
	T value = Peek();
	count--;

	EnsureCapacity();

	return value;
}
template<typename T>
T Stack<T>::Peek()
{
	if (isEmpty())
	{
		throw;
	}

	return data[count - 1];
}
template<typename T>
void Stack<T>::Clear()
{
	std::unique_ptr<T[]> temp = std::make_unique<T[]>(minimumCapacity);
	data = std::move(temp);
	capacity = minimumCapacity;
	count = 0;
}
template<typename T>
bool Stack<T>::isEmpty()
{
	return count == 0;
}
