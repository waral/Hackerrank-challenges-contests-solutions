#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

struct Player 
{
    string name;
    int score;
}; 

bool compare(struct Player player1, struct Player player2)
{
	if ( player1.score > player2.score )
	{
		//cout<<"player1.score > player2.score"<<endl;
		return true;
	}
	
	if ( player2.score > player1.score )
	{
		//cout<<"player2.score > player1.score"<<endl;
		return false;
	}
	
	//cout<<min((player1.name).size(), (player2.name).size())<<endl;
	
	for (int i=0; i< min((player1.name).size(), (player2.name).size()); i++)
	{
		if (player1.name[i] < player2.name[i])
		{
			//cout << player1.name[i] << " < " << player2.name[i];
			return true;
		}
		if (player2.name[i] < player1.name[i])
		{
			//cout << player2.name[i] << " < " << player1.name[i];
			return false;
		}
	}
	//cout<<"After the loop "<<endl;
	
	if ( (player1.name).size() < (player2.name).size() )
	{
		//cout<<"(player1.name).size()< (player2.name).size()"<<endl;
		return true;
	}
	
	return false;
}

void Sort( Player players[], int left, int right ) //quicksort on players
{
      
      int i = left, j = right;
      
      Player pivot = players[left + (right-left)/2];
      
      Player temp;
 
      /* partition */
      while (i <= j) 
      {
            while ( compare( players[i] , pivot ) )
            {
                  //cout<<" while 1 and i="<<i<<endl;
                  i++;
            }
            while ( compare( pivot , players[j] ) )
            {
                  //cout<<" while 2"<<endl;
                  j--;
            }
            if (i <= j) 
            {
                  //cout<<" if 1"<<endl;
            	temp = players[j];
            	players[j] = players[i];
            	players[i] = temp;
                  i++;
                  j--;
            }
      }
 
      /* recursion */
      if (left < j)
      {
            //cout<<" if 2"<<endl;
            Sort(players, left, j);
      }
      if (i < right)
      {
            //cout<<" if 3"<<endl;
            Sort(players, i, right);
      }
}


vector<Player> comparator(vector<Player> players) 
{
    
    vector<Player> temp;
    
    struct Player* arr=new Player[players.size()];

    for (int i = 0; i < players.size(); ++i)
    {
    	arr[i]=players[i];
    }
   
    Sort(arr,0,players.size()-1);

    for(int i = 0; i < players.size(); i++)
    {
        temp.push_back(arr[i]);
    }
    
    delete[] arr;
    
    return temp;
}




int main(){
    
    int n, score;
    vector< Player > players;
    string name;

    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    vector<Player > answer = comparator(players);
    
    for(int i = 0; i < answer.size(); i++) 
    {
        cout << answer[i].name << " " << answer[i].score << endl;
    }

    
    return 0;
}
