#include<bits/stdc++.h>

using namespace std;


int main(){

    fstream file("program.txt");
    vector<string> inp;
    string s;
    vector<pair<pair<int,int>,pair<int,int> > > bracket;
    vector<bool> error;
    stack<pair<int,char> > brac;
    pair<int,int> Pointer{0,0};

 //Storing the files contents into the vector
    while(!file.eof()){
        getline(file,s);
        inp.push_back(s);
    }



//Going through the file to check for brackets
    for(int x=0;x<inp.size();x++){
        for(int y=0;y<inp[x].size();y++){
            if(inp[x][y]=='[' || inp[x][y]=='(' || inp[x][y]=='{' || (inp[x][y]=='<' && (inp[x][y-1]!='<' && inp[x][y+1]!='<')) ){
                brac.push({bracket.size(),inp[x][y]});
                bracket.push_back({{x,y},{-1,-1}});
                error.push_back(0);
                //cout<<brac.top().second<<" ";
                continue;

            }
            else if(inp[x][y]==']'){
                int x1= brac.top().first;
                bracket[x1].second=make_pair(x,y);
                if(brac.top().second=='['){
                   error[x1]=1;
                }
                brac.pop();
                continue;
            }
            else if(inp[x][y]==')'){
                int x1= brac.top().first;
                bracket[x1].second=make_pair(x,y);
                if(brac.top().second=='('){
                   error[x1]=1;
                }

             brac.pop();
             continue;
            }

            else if(inp[x][y]=='>' && (inp[x][y-1]!='>' && inp[x][y+1]!='>')){
                int x1= brac.top().first;
                bracket[x1].second=make_pair(x,y);
                if(brac.top().second=='<'){
                   error[x1]=1;
                }

             brac.pop();
             continue;
            }
            else if(inp[x][y]=='}'){
                int x1= brac.top().first;
                bracket[x1].second=make_pair(x,y);
                if(brac.top().second=='{'){
                   error[x1]=1;
                }

             brac.pop();
             continue;
            }

        }
       // cout<<bracket.size();
    }


//for Testing if all brackets are intialized
/*
        for(auto x:bracket){
         cout<<"=========";
         cout<<x.first.first<<" "<<x.first.second<<" \n";
         cout<<x.second.first<<" "<<x.second.second;
        cout<<endl;
*/

//For showing the file with current item indicated by underline
// and symbols with green font!!!!

  char m;
  pair<int,int> temp;
  do{
    system("clear");
    for(int x=0;x<inp.size();x++){
        for(int y=0;y<inp[x].size();y++){

         if(Pointer==make_pair(x,y)){

            if(inp[x][y]=='[' || inp[x][y]=='(' || inp[x][y]=='{' || inp[x][y]=='<' ){
                cout << "\033[32m" << inp[x][y] << "\033[m";
                for(int i=0;i<bracket.size();i++){

                 if(bracket[i].first==make_pair(x,y)){
                    temp=bracket[i].second;
                 }

                }
            }

            else{
                cout << "\033[4m" << inp[x][y] << "\033[0m";
            }
         }

         else{
            if(temp==make_pair(x,y))
                cout << "\033[32m" << inp[x][y] << "\033[m";
            else
                cout<<inp[x][y];
         }
        }
        cout<<endl;
    }

 // cout<<temp.first<<" "<<temp.second<<endl;
    cout<<"Use WASD (case sensitive) to navigate through\n";
    cin>>m;


    if(m=='W'){
        if(Pointer.first==0)
          ;
        else
           Pointer.first--;
    }
    if(m=='S'){
        if(Pointer.first==inp.size()-1)
          ;
        else
           Pointer.first++;
    }
    if(m=='A' ){
        if(Pointer.second==0)
          ;
        else
           Pointer.second--;
    }
    if(m=='D'){
        if(Pointer.second==inp[Pointer.first].size()-1)
          ;
        else
           Pointer.second++;
    }

    temp={-1,-1};
  }while(m!='0');

}

