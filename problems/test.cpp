// #include<bits/stdc++.h>

#include<iostream>
using namespace std;
class Box{
    private:
    int l , b , h;

    public:
    Box():l(0) , b(0) , h(0){}
    Box(int length , int breadth , int height){
        l = length;
        b = breadth;
        h = height;
    }
    Box(const Box& new_box){
        l = new_box.getLength();
        h = new_box.h;
        b= new_box.b;
    }
    int getLength() const{
        return l;
    }
    int getBreadth (){
        return b;

    }
    int getHeight (){
    return h;   
    }
    long long CalculateVolume(){
        return (long long )l*b*h;
    }
    friend bool operator < (const Box& b1,const Box& b2){
            if((b1.l < b2.l) || (b1.l == b2.l && b1.b < b2.b) ||
               (b1.l == b2.l && b1.b == b2.b && b1.h <b2.h))
                return(true);
            else
                return(false);
    }
    friend ostream& operator << (ostream& s,const Box& b1)
    {
        s << b1.l << " " << b1.b << " " << b1.h;
        return s;
    }
};


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}