// StackBy2Queue.cpp : 定义控制台应用程序的入口点。
#include"iostream"
#include<queue>
#include<assert.h>
using namespace std;
template<typename T>class StackBy2Queue
{
private:
	queue<T>_queue1;
	queue<T>_queue2;
public:
	void Push(const T&x)
	{
		if (_queue1.size() > 0)
			_queue1.push(x);//如果队列1不为空则将数据插入队列1中
		else if (_queue2.size() > 0)
			_queue2.push(x);//队列1为空队列2不为空插入到队列2中
		else
			_queue1.push(x);
	}
	void Pop()
	{
		assert(!_queue1.empty() || !_queue2.empty());
		if (_queue2.empty())
		{
			//队列2为空时
			while (_queue1.size() > 1)
			{
				//保留队列1原本的队尾元素
				_queue2.push(_queue1.front());
				_queue1.pop();
			}
			_queue1.pop();
		}
		else
		{
			//队列2不为空
			while (_queue2.size() > 1)
			{
				//保留队列2 的队尾元素
				_queue1.push(_queue2.front());
				_queue2.pop();
			}
			_queue2.pop();
		}
	}
	T&Top()
	{
		if (_queue1.size() > 0)
			return _queue1.back();
		else
			return _queue2.back();
	}
	bool Empty()
	{
		//两个队列为空是才为空
		return (_queue1.empty()) && (_queue2.empty());
	}
	rsize_t Size()
	{
		return _queue1.size() + _queue2.size();
	}
};
void testStackBy2Queue()
{
	StackBy2Queue<int>sq;
	sq.Push(1);
	sq.Push(2);
	sq.Push(3);
	sq.Push(4);
	sq.Push(5);
	cout << sq.Top() << endl;
	sq.Pop();
	cout << sq.Top() << endl;
	sq.Push(6);
	cout << sq.Top() << endl;
	cout << sq.Size() << endl;
	sq.Pop();
	sq.Pop();
	sq.Pop();
	sq.Pop();
	sq.Pop();
}
int main()
{
	testStackBy2Queue();
	system("pause");
	return 0;
}