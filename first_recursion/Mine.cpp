#include <iostream>
#include "mine.h"

using namespace std;
// My very first attempt to solve a problem by recursion, (not so clean code)


int main(int argc, char const *argv[])
{
	cout<<"Please enter size of array !"<<endl;
    int g;
	
	

	//
	
	srand(time(0));
	
	 
	cin>>g; // heere
	
	cout<<"Do you want to pass pointer of array ? (y/n) :";
	char by_pointer;
	cin>>by_pointer;

	int ans_to_print;

	if(by_pointer == 'y')
	{
		int n=g;
		//int array1[g][g];
		
		int **p= new int*[g];
		for(int i=0; i<g; i++)
		{
			p[i]= new int[g];

		}
		// a two dimensional array has formed
		cout<<"Enter elements of array one by one"<<endl;

		for(int z=0; z<g; z++)
		{
			for(int y=0; y<g; y++)
			{
				cin>> p[z][y];
			}
		}

		Mine my_mine(p, g);
		// printing now
		cout<<"Final Mine : "<<endl;

		for(int i=0; i<g; i++)
	    {
		  for(int k=0; k<g; k++)
		  {
			 cout<<my_mine.map[i][k]<<" ";
		  }
		     cout<<endl;
	    }
	    // gaining two structs here

	    cout<<"Enter starting point (x,y) : ";
	    mine_index starting_point;
	    cin>>starting_point.row;
	    cin>>starting_point.column;
 
	    cout<<"Enter ending point (x,y) : ";
	    mine_index ending_point;
	    cin>>ending_point.row;
	    cin>>ending_point.column;

	   
         Miner man;
	   cout<<"Tell about Miner : "<<endl;
	    
	    cout<<"Can go up    (1/0) : "; cin>> man.up;
	    cout<<"Can go down  (1/0) : "; cin>> man.down;
	    cout<<"Can go left  (1/0) : "; cin>> man.left;
	    cout<<"Can go right (1/0) : "; cin>> man.right;

	  ans_to_print=  my_mine.can_solve(man, starting_point, ending_point);
	  //////////////////////////
   /////////////////

    }



	
	// calling by second constructor i guess
	else if(by_pointer == 'n')
     {
		cout<<"Enter P for making mine of your provided size or D for default size :";
		char dec;
		cin>> dec;
		if(dec =='P' || dec=='p')
		{

	Mine my_mine(g);

	cout<<"Mine : "<<endl;
    for(int i=0; i<g; i++)
	{
		for(int k=0; k<g; k++)
		{
			cout<<my_mine.map[i][k]<<" ";
		}
		cout<<endl;
	}
	// gaing two structa here

	cout<<"Enter starting point (x,y) : ";
	mine_index starting_point;
	cin>>starting_point.row;
	cin>>starting_point.column;

	cout<<"Enter ending point (x,y) : ";
	mine_index ending_point;
	cin>>ending_point.row;
	cin>>ending_point.column;

	
    Miner man;
	cout<<"Tell about Miner : "<<endl;
	
	cout<<"Can go up    (1/0) : "; cin>> man.up;
	cout<<"Can go down  (1/0) : "; cin>> man.down;
	cout<<"Can go left  (1/0) : "; cin>> man.left;
	cout<<"Can go right (1/0) : "; cin>> man.right;

	//cout<<"Ending point is :"<< ending_point.column<<endl;

	ans_to_print = my_mine.can_solve(man, starting_point, ending_point);
	//////////////////////////
	  
   /////////////////

    }
    else 
    {
    	Mine my_mine;

	cout<<"Mine : "<<endl;
    for(int i=0; i<5; i++)
	{
		for(int k=0; k<5; k++)
		{
			cout<<my_mine.map[i][k]<<" ";
		}
		cout<<endl;
	}
	// gaing two structa here

	cout<<"Enter starting point (x,y) : ";
	mine_index starting_point;
	cin>>starting_point.row;
	cin>>starting_point.column;

	cout<<"Enter ending point (x,y) : ";
	mine_index ending_point;
	cin>>ending_point.row;
	cin>>ending_point.column;
	

	//
    Miner man;
    cout<<"Tell about Miner : "<<endl;
	
	cout<<"Can go up    (1/0) : "; cin>> man.up;
	cout<<"Can go down  (1/0) : "; cin>> man.down;
	cout<<"Can go left  (1/0) : "; cin>> man.left;
	cout<<"Can go right (1/0) : "; cin>> man.right;
  //  cout<<"janey lga"<<endl;
	ans_to_print = my_mine.can_solve(man, starting_point, ending_point);//cout<<"gya chla"<<endl;

    }
}
   cout<<endl<<ans_to_print<<endl;

   


	return 0;
}

int Mine::can_solve(Miner man, mine_index starting_point, mine_index ending_point)
{
	//cout<<"called"<<endl;
	int x1= starting_point.row;
	int y1= starting_point.column;
	int x2= ending_point.row;
	int y2= ending_point.column;
	
	int gar1=ending_point.row;
	int gar2= ending_point.column;
	if(map[starting_point.row][starting_point.column]==0){cout<<"cant even start from here"<<endl; return 0;}
	if(starting_point.row== ending_point.row && starting_point.column==ending_point.column){cout<<"bsssssss"<<endl; return 1;}
	if(map[gar1][gar2] == 0) {cout<<"cant go there"<<endl; return 0;}
	// editing
	if(ending_point.row>size_of_array || ending_point.row <0 ){cout<<"location does not exist"<<endl; return 0;}
	if(ending_point.column>size_of_array || ending_point.column<0 ){cout<<"location does not exist"<<endl; return 0;}
	//int copy_mine[size_of_array][size_of_array];
	copy_mine = new int*[size_of_array];
		for(int nn=0; nn< size_of_array; nn++)
			copy_mine[nn] = new int[size_of_array];
		// now defining
		for(int t=0; t<size_of_array; t++)
		{
			for(int o=0; o<size_of_array; o++)
			{
				copy_mine[t][o]= map[t][o];
			}
		}
	/////////////////----------------///////////////////
	for(int i=0; i<size_of_array; i++)
	{
		for(int k=0; k<size_of_array; k++)
		{
			cout<<map[i][k]<< " ";
		}
		cout<<endl;
	}
	/*---*/
	int to_return=can_solve2(man, x1, y1, x2, y2);
	// double checking
/*	if(to_return==0)
	{
		// recovering original array
		for(int q=0; q<size_of_array; q++)
		{
			for(int w=0; w<size_of_array; w++)
			{
				map[q][w]= copy_mine[q][w];
			}
		}
		// now calling by reversing arguments
		to_return= can_solve2(man, x2, y2, x1, y1);
	} */

	 if(to_return==1){cout<<"yes, miner CAN transverse mine."<<endl;}
     else if(to_return==0){cout<<"no, miner CANNOT transverse mine."<<endl;}
	return to_return;

}
int Mine::zero_it(int x1, int y1)
{
	map[x1][y1]=0;
	return 1;
}

int Mine::can_solve2(Miner man, int x1, int y1, int x2, int y2)
{
	//cout<<"2 mein a gya "<<size_of_array<<endl;
	if(x1==x2 && y1 == y2)
	{
		//cout<<"yeah"<<endl;
		return 1; 
	}


	if((x1 < size_of_array && x1 >= 0 && y1 < (size_of_array-1) && y1 >= 0) && map[x1][y1+1]==1 && man.right==1)
	{
		
		if(((x1 < (size_of_array-1) && x1 >= 0 && y1<size_of_array && y1 >= 0) && map[x1+1][y1]==1) && man.down==1 && (zero_it( x1, y1)==1 &&  can_solve2(man, x1+1, y1, x2, y2)==1)){return 1;}
		if(((x1 < (size_of_array) && x1 >0 && y1<size_of_array && y1 >= 0) && map[x1-1][y1]==1)&& man.up==1 && ( zero_it(x1, y1)==1 && can_solve2(man, x1-1, y1, x2, y2)==1  )) {return 1;}
		if(((x1 < size_of_array && x1 >= 0 && y1<size_of_array && y1 > 0) && map[x1][y1-1]==1) && man.left==1 && (zero_it(x1, y1)==1 && can_solve2(man, x1, y1-1, x2, y2)==1)){return 1;}
		//if(((x1 < 5 && x1 >=0 && y1<5 && y1 >= 0) && m[x1-1][y1]==1)&&(solve(m, x1-1, y1, x2, y2)==1)){return 1;}
		//cout<<"yess !"<< x1<<" "<< y1+1<<endl;
		map[x1][y1]=0;
		can_solve2(man, x1, y1+1, x2, y2); 

	}
	else if((x1 < (size_of_array-1) && x1 >= 0 && y1 < size_of_array && y1 >= 0) && man.down==1 && map[x1+1][y1]==1)
	{
		if(((x1 < size_of_array && x1 >= 0 && y1<size_of_array && y1 >0) && map[x1][y1-1]==1) && man.left==1 && (zero_it( x1, y1)==1 && can_solve2(man,x1, y1-1, x2, y2)==1)){return 1;}
		if(((x1 < (size_of_array) && x1 >0 && y1<size_of_array && y1 >= 0) && map[x1-1][y1]==1)&& man.up && ( zero_it(x1, y1)==1 && can_solve2( man, x1-1, y1, x2, y2)==1  )) {return 1;}

		
		map[x1][y1]=0;
		can_solve2(man, x1+1, y1, x2, y2); 

	}
	else if((x1 < size_of_array && x1 > 0 && y1<size_of_array && y1 >= 0) && man.up == 1 && map[x1-1][y1]==1)
	{
	  //	cout<<"---entered in third------"<<endl;
		if(((x1 < size_of_array && x1 >= 0 && y1 < (size_of_array-1) && y1 >= 0) && map[x1][y1+1]==1)&& man.right==1 &&(zero_it(x1, y1)==1 && can_solve2(man, x1, y1+1, x2, y2)==1)){return 1;}
		if(((x1 < size_of_array && x1 >= 0 && y1<size_of_array && y1 > 0) && map[x1][y1-1]==1)&& man.left==1 &&(zero_it(x1, y1)==1 && can_solve2(man,x1, y1-1, x2, y2)==1)){return 1;}
		if(((x1 < (size_of_array-1) && x1 >= 0 && y1<size_of_array && y1 >= 0) && map[x1+1][y1]==1)&& man.down==1 &&(zero_it(x1, y1)==1 && can_solve2(man, x1+1, y1, x2, y2)==1)){return 1;}

		map[x1][y1]=0;
		can_solve2(man, x1-1, y1, x2, y2); 

	}
	else if((x1 < size_of_array && x1 >= 0 && y1<size_of_array && y1 > 0) && man.left==1 && map[x1][y1-1]==1)
	{
	
		map[x1][y1]=0;
		can_solve2(man, x1, y1-1, x2, y2); 

	}
	else
	{
		cout<<endl;
	 return 0;
	}


}



