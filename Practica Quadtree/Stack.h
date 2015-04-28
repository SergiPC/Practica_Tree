// --------------------------------------------
//              Stack Class
// --------------------------------------------

#ifndef __Stack_H__
#define __Stack_H__

#define STACK_PRED_SIZE 22

template<class kdata>
class Stack
{
private:

	kdata*			data; // pointer for array's memory
	unsigned int	num_elements; // number of elements
	unsigned int	capacity; // allocated memory

public:

	// Constructor -----------------------------------------
	Stack() : capacity(0), num_elements(0), data(NULL)
	{
		allocation(STACK_PRED_SIZE);
	}


	Stack(unsigned int new_capacity) : capacity(0), num_elements(0), data(NULL)
	{
		allocation(new_capacity);
	}

	// Destructor ------------------------------------------
	~Stack()
	{
		delete[] data;
	}

	// Data management -------------------------------------
	// add item to the end of array
	void pushBack(const kdata& value)
	{
		if (num_elements >= capacity)
		{
			allocation(capacity + STACK_PRED_SIZE);
		}
		data[num_elements++] = value;
	}

	// delete the last array item
	kdata& pop()
	{
		if (data != NULL && num_elements > 0)
		{
			unsigned int i = num_elements - 1;
			kdata& ret = data[i];
			num_elements--;
			return ret;
		}
		else
		{
			return NULL;
		}
	}

	bool pop(kdata& value)
	{
		if (num_elements > 0)
		{
			value = data[--num_elements];
			return true;
		}
		return false;
	}

	void clear()
	{
		num_elements = 0;
	}

	const kdata* Peek(unsigned int index) const
	{
		VALUE* result = NULL;

		if (index < num_elements)
			return result = &data[index];

		return result;
	}

	// Utilities -------------------------------------------
	unsigned int getCapacity() const
	{
		return capacity;
	}


	unsigned int count() const
	{
		return num_elements;
	}

private:

	// Requires going private ------------------------------
	void allocation(unsigned int new_memory)
	{
		kdata* new_data = data;
		capacity = new_memory;
		data = new kdata[capacity];
		if (num_elements > capacity)
		{
			num_elements = capacity;
		}
		if (new_data != NULL)
		{
			for (unsigned int i = 0; i < num_elements; ++i)
			{
				data[i] = new_data[i];
			}
			delete[] new_data;
		}
	}
};

#endif // __Stack_H__