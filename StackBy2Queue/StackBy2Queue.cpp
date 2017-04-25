// StackBy2Queue.cpp : �������̨Ӧ�ó������ڵ㡣
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
			_queue1.push(x);//�������1��Ϊ�������ݲ������1��
		else if (_queue2.size() > 0)
			_queue2.push(x);//����1Ϊ�ն���2��Ϊ�ղ��뵽����2��
		else
			_queue1.push(x);
	}
	void Pop()
	{
		assert(!_queue1.empty() || !_queue2.empty());
		if (_queue2.empty())
		{
			//����2Ϊ��ʱ
			while (_queue1.size() > 1)
			{
				//��������1ԭ���Ķ�βԪ��
				_queue2.push(_queue1.front());
				_queue1.pop();
			}
			_queue1.pop();
		}
		else
		{
			//����2��Ϊ��
			while (_queue2.size() > 1)
			{
				//��������2 �Ķ�βԪ��
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
		//��������Ϊ���ǲ�Ϊ��
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