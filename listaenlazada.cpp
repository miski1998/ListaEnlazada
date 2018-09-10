#include<iostream>

using namespace std;

struct node
{
	int data;
	node *next;	
};
class list
{
		private:
		node *head, *last;
		public:
		list()
		{
			head=NULL;
			last=NULL;
		}
		void createnode(int value)
		{
			node *temp=new node;
			temp->data=value;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				last=temp;
				temp=NULL;
			}
			else
			{	
				last->next=temp;
				last=temp;
			}
		}
		void show()
		{
			node *temp=new node;
			temp=head;
			if(temp==NULL){cout<<"LISTA VACIA"<<endl;}
			else{
				while(temp!=NULL)
				{
					cout<<temp->data<<"\t";
					temp=temp->next;
				}
			}
		}
		void insert_start(int value)
		{
			node *temp=new node;
			temp->data=value;
			temp->next=head;
			head=temp;
		}
		void insert_position(int pos, int value)
		{
			node *pre=new node;
			node *c=new node;
			node *temp=new node;
			c=head;
			for(int i=1;i<pos;i++)
			{
				pre=c;
				c=c->next;
			}
			temp->data=value;
			pre->next=temp;	
			temp->next=c;
		}
		void delete_first()
		{
			node *temp=new node;
			temp=head;
			head=head->next;
			delete temp;
		}
		void delete_last()
		{
			node *c=new node;
			node *pre=new node;
			c=head;
			while(c->next!=NULL)
			{
				pre=c;
				c=c->next;	
			}
			last=pre;
			pre->next=NULL;
			delete c;
		}
		void delete_position(int pos)
		{
			node *c=new node;
			node *pre=new node;
			c=head;
			for(int i=1;i<pos;i++)
			{
				pre=c;
				c=c->next;
			}
			pre->next=c->next;
			delete c;
		}
		void list_lenght ()
		{
			node *temp;
			temp = head;
			int cont=0;
			while(temp!=NULL){
				temp=temp->next;
				cont++;
			}
			cout<<cont;			
		}
		void delete_list()
		{
			node *temp;
			while(head!=NULL){
				temp=head;
				head=head->next;
				delete temp;
			}
		}
		bool find_item(int value)
		{
			node *temp;
			temp=head;
			bool x = false;
			while(x==false){
				if(temp->data==value){
					x = true;
				}
				else{
					temp=temp->next;
				}
				//cout<<x<<endl;
			}
			cout<<x<<endl;
			return x;
		}
		void copy_list()
		{
			node *temp,*temp_b,*head1;
			temp=head;
			temp_b=head1;
			while(temp!=NULL){
				temp_b->data=temp->data;
				temp=temp->next;
				temp_b=temp_b->next;
				cout<<temp_b->data;
			}
		}
};
int main()
{
	list A,B;
	A.createnode(2);
	A.createnode(5);
	A.createnode(9);
	A.createnode(4);
	cout<<"---------------Mostrar todos los nodos---------------"<<endl;
	A.show();
	cout<<endl;
	cout<<"-----------------Insertando al Final-----------------"<<endl;
	A.createnode(55);
	A.show();
	cout<<endl;
	cout<<"----------------Tamano Lista-----------------------"<<endl;
	A.list_lenght();
	cout<<endl;
	cout<<"----------------Buscar Elemento-----------------------"<<endl;
	A.find_item(34);
	cout<<endl;
	//cout<<"----------------Copiar elementos-----------------------"<<endl;
	//A.copy_list();
	//A.show();
	//B.show();
	//cout<<"----------------Borrar lista-----------------------"<<endl;
	//A.delete_list();
	//A.show();
	cout<<"----------------Inseratar al inicio----------------"<<endl;
	A.insert_start(50);
	A.show();
	cout<<endl;
	cout<<"-------------Insercion particular--------------"<<endl;
	A.insert_position(5,60);
	A.show();
	cout<<endl;
	cout<<"----------------Borrar inicio-----------------"<<endl;
	A.delete_first();
	A.show();
	cout<<endl;
	cout<<"-----------------Borrar final-------------------"<<endl;
	A.delete_last();
	A.show();
	cout<<endl;
	cout<<"--------------Borrar particular--------------"<<endl;
	A.delete_position(5);
	A.show();
	cout<<"\n--------------------------------------------------\n";
	//system("pause");
	return 0;
}
