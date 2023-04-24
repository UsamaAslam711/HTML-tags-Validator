#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<vector>

using namespace std;
class node
{
private:
	string data;
public:
	node* next_ptr;
	node* pre_ptr;
	node()
	{

	}
	node(string data)
	{
		this->data = data;
		next_ptr = NULL;
		pre_ptr = NULL;
	}
	void set_data(string data)
	{
		this->data = data;
	}
	string get_data()
	{
		return data;
	}
};



class stack : public node
{
private:
	node* Head;
public:
	stack()
	{
		Head = NULL;
	}
	bool isEmpty()
	{
		return(Head == NULL);
	}
	void push(node*n)
	{
		bool Check;
		Check = isEmpty();
		if (Check == true)
		{
			Head = n;
		}
		else
		{
			n->next_ptr = Head;
			Head->pre_ptr = n;
			Head = n;
		}
	}
	string pop()
	{
		bool Check;
		Check = isEmpty();
		if (Check == true)
		{
			cout << "The stack is Empty";
		}
		else
		{
			node* rptr = Head;
			string n;
			n.clear();
			n = Head->get_data();
			if (Head->next_ptr == NULL)
			{
				if (Head->get_data() == "")
				{
					Head = Head->next_ptr;
					return"0";
				}
				else
				{
					return n;
				}
			}
			else
			{
				Head = Head->next_ptr;
				Head->pre_ptr = NULL;
				return n;
			}
		}
	}
	void peak()
	{
		bool Check;
		Check = isEmpty();
		if (Check == true)
		{
			cout << "The stack is Empty";
		}
		else
		{
			cout << Head->get_data();
		}
	}
	int sizeOf()
	{
		node* rptr = Head;
		int x = 0;
		if (rptr == NULL)
		{
			return x;
		}
		while (rptr->next_ptr != NULL)
		{
			x++;
			rptr = rptr->next_ptr;
		}
		x++;
		return x;
	}
	bool search(string i)
	{
		bool Check;
		Check = isEmpty();
		if (Check == true)
		{
			cout << "The stack is Empty";
		}
		else
		{
			node* rptr1 = Head;

			while (rptr1->next_ptr != NULL)
			{
				rptr1 = rptr1->next_ptr;
			}
			while (rptr1->pre_ptr != NULL || rptr1->next_ptr != NULL || rptr1->get_data() != "")
			{
				if (rptr1->get_data() == i)
				{
					rptr1->set_data("");
					return true;
				}
				else
				{
					rptr1 = rptr1->pre_ptr;
					if (rptr1 == NULL)
					{
						break;
					}
				}
			}
			return false;
		}
	}
	void check()
	{
		bool Check;
		string n;
		int Size = sizeOf();
		for (int i = 0; i < Size; i++)
		{
			if (isEmpty() != true)
			{
				Check = false;
				n.clear();
				n = pop();
				while (n == "")
				{
					n.clear();
					n = pop();
					if (n == "0")
					{
						Check = true;
						break;
					}
				}
				if (Check == true)
				{
					break;
				}
				else
				{
					int Size = n.length();
					char* c = new char[Size];
					for (int i = 0; i < Size; i++)
					{
						c[i] = n[i];
					}
					if (c[0] == '/')
					{
						n.clear();
						for (int i = 0; i <= Size - 2; i++)
						{
							n = n + c[i + 1];
						}
						Check = search(n);
						if (Check == false)
						{
							break;
						}
					}
					else
					{
						break;
					}
				}
			}
			else
				break;
		}
		cout << "The file has been checked and the result is" << endl << endl;
		Check = isEmpty();
		if (Check == true)
		{
			cout << "------------------------------------" << endl;
			cout << "     This file has valid tags" << endl;
			cout << "------------------------------------" << endl << endl;
		}
		else
		{
			cout << "------------------------------------" << endl;
		cout << "    This file has INVALID tags" << endl;
		cout << "------------------------------------" << endl << endl;
		}
	}
};




void main()
{
	cout << "***********************************************************************" << endl;
	cout << "         ~~~~~COMPILER FOR VERIFYING HTML TAGS~~~~~~" << endl;
	cout << "***********************************************************************" << endl << endl << endl;
	vector<string>inp;
	string x;
	fstream File;
	string filename;
	int string_length = 0, Count = 0;
	cout << "Enter the name of the file long with it's extension = ";
	cin >> filename;
	File.open(filename);
	while (getline(File, x))
	{
		string_length = string_length + x.length();
		inp.push_back(x);
	}
	stack List;
	char* ch = new char[string_length];
	for (int i = 0; i < inp.size(); i++)
	{
		x.clear();
		x = inp[i];
		for (int i = 0; i < x.length(); i++)
		{
			ch[Count] = x[i];
			Count++;
		}
	}
	while (*ch != '>')
	{
		if (*ch == '<')
		{
			ch++;
			if (*ch == '/')
			{
				x.clear();
				while (*ch != '>')
				{

					x = x + *ch;
					ch++;
				}
				List.push(new node(x));
				if (ch[1] == '<')
				{
					ch++;
				}
				else
					break;
			}
			else
			{
				x.clear();
				while (*ch != '>')
				{
					if (*ch == '<')
					{
						ch++;
						continue;
					}
					else
					{
						x = x + *ch;
						ch++;
					}
				}
				List.push(new node(x));
				if (ch[1] == '<')
				{
					ch++;
				}
				else
					break;
			}
		}
		else
			ch++;
	}
	File.close();
	List.check();
	_getch();
}













