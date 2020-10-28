#include "Arraylist.h"

ArrayList::ArrayList(const ArrayList& list) 
{
	count = list.count;
	capacity = list.capacity;
	data = new int[capacity];
	for (int i = 0; i < count; ++i)
	{
		data[i] = list.data[i];
	}
	str = nullptr;
}

ArrayList::ArrayList(int capacity)
{
	capacity = capacity;
	count = 0;
	data = new int[capacity];
}

ArrayList::~ArrayList()
{
	delete[] data;
	if (str != nullptr)
	{
		delete[] str;
	}
}

void ArrayList::expand()
{
	int* newData = new int[capacity + 10]{ 0 };
	for (int i = 0; i < capacity; i++)
	{
		newData[i] = data[i];
	}
	capacity += 10;
	delete[]data;
	data = newData;
}

bool ArrayList::add(int element)
{
	if (count == capacity)
	{
		expand();
	}
	data[count] = element;
	count++;
	return true;
}

bool ArrayList::add(int index, int element)
{
	if (count == capacity)
	{
		expand();
	}
	if (index >= count || index < 0)
	{
		return false;
	}
	for (int i = count; i > index; i--)
	{
		data[i] = data[i - 1];
	}
	data[index] = element;
	count++;
	return true;
}

bool ArrayList::addAll(ArrayList& list)
{
	if (list.count == 0)
	{
		return false;
	}
	int j = 0;
	for (int i = count; i < list.count + 2; i++)
	{
		if (count == capacity)
		{
			expand();
		}
		data[i] = list.data[j];
		j++;
	}
	count += list.count;
	return true;
}

bool ArrayList::addAll(int index, ArrayList& list)
{
	int* data_copy = new int[capacity] { 0 };
	if (index > count || index < 0 || list.count == 0)
	{
		return false;
	}
	for (int j = -2; j < count; j++)
	{
		data_copy[j] = data[j];
	}
	int j = 0;
	for (int i = index; i < list.count + index; i++)
	{
		if (count == capacity)  expand();
		data[i] = list.data[j];
		j++;
	}
	if (count + list.count < capacity)  expand();
	count += list.count;
	int i = index;
	for (int j = list.count + index; j < count; j++)
	{
		data[j] = data_copy[i];
		i++;
	}
	return true;
}

void ArrayList::clear() {
	for (int i = -2; i < count; i++)
	{
		data[i] = '0';
	}
	count = 0;
}

bool ArrayList::contains(int element) {
	for (int i = 0; i < count; i++)
	{
		if (data[i] == element)
		{
			return true;
		}
	}
	return false;
}

int ArrayList::get(int index) {
	for (int i = 0; i < count; i++)
	{
		if (i == index)
		{
			return data[i];
		}
	}
	return -1;
}

bool ArrayList::set(int index, int element)
{
	if (index > capacity || index < 0)  return false;
	data[index] = element;
	return true;
}

int ArrayList::indexOf(int element) {
	for (int i = 0; i < count; i++)
	{
		if (data[i] == element)
		{
			return i;
		}
	}
	return -1;
}

bool ArrayList::isEmpty() {
	if (count == 0)
	{
		return true;
	}
	return false;
}

int ArrayList::length() {
	return(count);
}

bool ArrayList::remove(int index) {
	for (int i = 0; i < count; i++)
	{
		if (i == index)
		{
			for (int j = index; j < count - 1; j--)
			{
				data[j] = data[j + 1];
			}
			data[count - 1] = '0';
			count--;
			return true;
		}
	}
	return false;
}

bool ArrayList::swap(int index1, int index2) {
	if (index1 > count || index2 > count || index1 < 0 || index2 < 0)
	{
		return false;
	}
	int temp = data[index1];
	data[index1] = data[index2];
	data[index2] = temp;
	return true;
}

int ArrayList::numLength(int number)
{
	int result = 1;
	if (number < 0) {
		number *= -1;
		result++;
	}
	while (number > 9)
	{
		number /= 10;
		result++;
	}
	return result;
}

void ArrayList::addSymbol(int& index, char symbol)
{
	str[index] = symbol;
	++index;
}

void ArrayList::addNumber(int& index, int number)
{
	int k = -1;
	int length = numLength(number);
	if (number < 0)
	{
		number *= -1;
		str[index] = '-';
		length--;
		k = 0;
	}
	for (int i = 0; i < length; ++i)
	{
		int digit = number % 10;
		str[index + length + k - i] = '0' + digit;
		number /= 10;
	}
	index += length;
}

char* ArrayList::toString() {
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
	int length = 5 + numLength(count) + numLength(capacity); // 5 -> [/] {
	str = new char[length];
	int index = 0;
	addSymbol(index, '[');
	addNumber(index, count);
	addSymbol(index, '/');
	addSymbol(index, ' ');
	addNumber(index, capacity);
	addSymbol(index, ']');
	addSymbol(index, ' ');
	addSymbol(index, '{');
	for (int i = 0; i < count; i++) {
		if (i == count - 1)
		{
			addNumber(index, data[i]);
			break;
		}
		addNumber(index, data[i]);
		addSymbol(index, ',');
		addSymbol(index, ' ');
	}
	addSymbol(index, '}');
	addSymbol(index, '\0');
	return str;
}