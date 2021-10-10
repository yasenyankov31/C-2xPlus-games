#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
#include <algorithm> // for std::find
#include <iterator> // for std::begin, std::end

using namespace std;

const  string squares[10][10]={{"  ",""," A "," B "," C "," D "," E "," F "," G "," H "},
                    {"8"," "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "},
                    {"7"," "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "},
                    {"6"," "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "},
                    {"5"," "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "},
                    {"4"," "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "},
                    {"3"," "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "},
                    {"2"," "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "},
                    {"1"," "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "}};
const string black[5]={" ♙ "," ♘ "," ♖ "," ♗ "," ♕ "};
const string white[5]={" ♟︎ "," ♞ "," ♜ "," ♝ "," ♛ "};
const string boxes[2]={" ◼ "," ◻ "};
void RenderBoard(string arr[10][10])
{
  int arr_length =sizeof(arr[0]) / sizeof(string);
  for(int i=0;i<arr_length;i++)
  {
    for(int j=0;j<arr_length;j++)
    { 
        SetConsoleOutputCP(CP_UTF8);
        cout<<arr[i][j];  
    }
    cout<<""<<endl;
  }
}
void WhiteMovement(string arr[10][10],int y,int x,int _x,int _y)
{
    auto figure=arr[y][x];
    arr[_y][_x]=figure;
    arr[y][x]=squares[y][x];   
}


void GetWhiteFigure(string arr[10][10],int y ,int x,int _x,int _y)
{
    auto figure=arr[y][x];
    if(figure==" ♜ ")
    {
        for(int i=x+1;i<10;i++)
        { 
              if(i==_y&&x==_x)
            {
                if((arr[i][x]==" ◻ "||arr[i][x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
<<<<<<< HEAD
                else if(find(begin(black),end(black),arr[y][i]) != end(black)
                    &&find(begin(black),end(black),arr[y][i-1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
=======
                else
                {
                    if(find(begin(black),end(black),arr[y][i]) != end(black)
                    &&find(begin(black),end(black),arr[y][i-1]) == end(black))
                    {
                        WhiteMovement(arr,y,x,_x,_y);        
                    }
                    
>>>>>>> 8c9db727621b7df84e69ae53d460d22a2eb65316
                }
            }      
        }
        for(int i=x-1;i>1;i--)
        {
              if(i==_y&&x==_x)
            {
                if((arr[i][x]==" ◻ "||arr[i][x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
<<<<<<< HEAD
                else if(find(begin(black),end(black),arr[y][i]) != end(black)
                    &&find(begin(black),end(black),arr[y][i+1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);       
=======
                else
                {
                    if(find(begin(black),end(black),arr[y][i]) != end(black)
                    &&find(begin(black),end(black),arr[y][i+1]) == end(black))
                    {
                        WhiteMovement(arr,y,x,_x,_y);       
                    }
                    
>>>>>>> 8c9db727621b7df84e69ae53d460d22a2eb65316
                }
            }      
        }
        for(int i=y+1;i<10;i++)
        {
             if(i==_y&&x==_x)
            {
                if((arr[i][x]==" ◻ "||arr[i][x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
<<<<<<< HEAD
                else if(find(begin(black),end(black),arr[i][x]) != end(black)
                    &&find(begin(black),end(black),arr[i-1][x]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);       
=======
                else
                {
                    if(find(begin(black),end(black),arr[i][x]) != end(black)
                    &&find(begin(black),end(black),arr[i-1][x]) == end(black))
                    {
                        WhiteMovement(arr,y,x,_x,_y);       
                    }
                    
>>>>>>> 8c9db727621b7df84e69ae53d460d22a2eb65316
                }
            }      
        }
        for(int i=y-1;i>0;i--)
        {
            if(i==_y&&x==_x)
            {
                if((arr[i][x]==" ◻ "||arr[i][x]==" ◼ "))
                {
                   WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[i][x]) != end(black)
                    &&find(begin(black),end(black),arr[i+1][x]) == end(black))
                {
<<<<<<< HEAD
                    WhiteMovement(arr,y,x,_x,_y);        
=======
                    cout<<arr[i+1][x]<<endl;
                    cout<<arr[i][x]<<endl;
                    if(find(begin(black),end(black),arr[i][x]) != end(black)
                    &&find(begin(black),end(black),arr[i+1][x]) == end(black))
                    {
                        WhiteMovement(arr,y,x,_x,_y);        
                    }
                    
>>>>>>> 8c9db727621b7df84e69ae53d460d22a2eb65316
                }
            }          
        }
        //arr[y][x-1]=" X ";
        //arr[y-1][x]=" X ";
        //arr[y+1][x]=" X ";    

        cout<<"rook"<<endl;
    }
    else if(figure==" ♞ ")
    {
        cout<<y<<endl;
        cout<<x<<endl;
        if(y-2>=1&&x+1<=10&&x-1>=1)
        {
            if(y-2==_y&&x-1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y-2][x-1]=" X ";
                
            }
            else if(y-2==_y&&x+1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y-2][x+1]=" X ";
            }
                 
        }
        if(y+2<=10&&x+1<=10&&x-1>=1)
        {
            if(y+2==_y&&x+1==_x)
            {
                //arr[y+2][x+1]=" X ";
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
            }
            else if(y+2==_y&&x-1==_x)
            {
                //arr[y+2][x-1]=" X ";
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
            }
            
            
        }
        if(y+1<=10&&x-2>=1)
        {
            if(y+1==_y&&x+2==_x)
            {
                //arr[y+1][x+2]=" X ";
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
            }
            else if(y+1==_y&&x-2==_x)
            {
                //arr[y+1][x-2]=" X ";
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
            }
            
            
        }
        if(x+2<=10&&x-2>=1)
        {
            if(y-1==_y&&x-2==_x)
            {
                //arr[y-1][x-2]=" X ";
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
            }
            else if(y-1==_y&&x+2==_x)
            {
                //arr[y-1][x+2]=" X ";
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
            }            
            
            
        }

        cout<<"knight"<<endl;
    }
    else if(figure==" ♝ ")
    {
        for(int i =1;x+i<=9;i++)
<<<<<<< HEAD
        {  
            //arr[y-i][x+i]=" X ";
            if(y-i==_y&&x+i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y+1][_x-1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            } 
        }
        for(int i =1;x+i<=9;i++)
        {
            //arr[y+i][x+i]=" X ";
            if(y+i==_y&&x+i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y-1][_x-1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            }  
        }
        for(int i =1;i<x-1;i++)
        {
            //arr[y-i][x-i]=" X ";
            if(y-i==_y&&x-i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y+1][_x+1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            }  
        }
        for(int i =1;i<x-1;i++)
        {
            //arr[y+i][x-i]=" X ";
            if(y+i==_y&&x-i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y-1][_x+1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            }  
        }
        
=======
        {
            arr[y-i][x+i]=" X "; 
        }
        for(int i =10;x-i>=2;i--)
        {
            arr[y-i][x-i]=" X "; 
        }
        for(int i =1;x+i<=9;i++)
        {
            arr[y-i][x+i]=" X "; 
        }
        for(int i =1;x+i<=9;i++)
        {
            arr[y-i][x+i]=" X "; 
        }
        cout<<x+4<<endl;
>>>>>>> 8c9db727621b7df84e69ae53d460d22a2eb65316
        cout<<"bishop"<<endl;
    }
    else if(figure==" ♛ ")
    {

        for(int i=x+1;i<10;i++)
        { 
              if(i==_y&&x==_x)
            {
                if((arr[i][x]==" ◻ "||arr[i][x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[y][i]) != end(black)
                    &&find(begin(black),end(black),arr[y][i-1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }
            }      
        }
        for(int i=x-1;i>1;i--)
        {
              if(i==_y&&x==_x)
            {
                if((arr[i][x]==" ◻ "||arr[i][x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[y][i]) != end(black)
                    &&find(begin(black),end(black),arr[y][i+1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);       
                }
            }      
        }
        for(int i=y+1;i<10;i++)
        {
             if(i==_y&&x==_x)
            {
                if((arr[i][x]==" ◻ "||arr[i][x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[i][x]) != end(black)
                    &&find(begin(black),end(black),arr[i-1][x]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);       
                }
            }      
        }
        for(int i=y-1;i>0;i--)

        for(int i =1;x+i<=9;i++)
        {  
            //arr[y-i][x+i]=" X ";
            if(y-i==_y&&x+i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y+1][_x-1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            } 
        }
        for(int i =1;x+i<=9;i++)
        {
            //arr[y+i][x+i]=" X ";
            if(y+i==_y&&x+i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y-1][_x-1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            }  
        }
        for(int i =1;i<x-1;i++)
        {
            //arr[y-i][x-i]=" X ";
            if(y-i==_y&&x-i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y+1][_x+1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            }  
        }
        for(int i =1;i<x-1;i++)
        {
            //arr[y+i][x-i]=" X ";
            if(y+i==_y&&x-i==_x)
            {
                if((arr[_y][_x]==" ◻ "||arr[_y][_x]==" ◼ "))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                else if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                    &&find(begin(black),end(black),arr[_y-1][_x+1]) == end(black))
                {
                    WhiteMovement(arr,y,x,_x,_y);        
                }


            }  
        }
        
        cout<<"queen"<<endl;
    }
    else if(figure==" ♚ ")
    {
        if(y-1>=1&&x+1<10&&x-1>=1)
        {
            if(y-1==_y&&x+1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y-1][x+1]=" X ";
                
            }
            else if(y-1==_y&&x-1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y-1][x-1]=" X ";
            }
                 
        }
        
        if(x-1>=1&&y+1<10&&x-1>=1)
        {
            if(y+1==_y&&x+1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y+1][x+1]=" X ";
                
            }
            else if(y+1==_y&&x-1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y+1][x-1]=" X ";
            }
                 
        }

        if(x-1>=1&&x+1<10)
        {
            if(y==_y&&x+1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y][x+1]=" X ";
                
            }
            else if(y==_y&&x-1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y][x-1]=" X ";
            }
                 
        }

        if(y-1>=1&&y+1<10)
        {
            if(y-1==_y&&x==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y-1][x]=" X ";
                
            }
            else if(y+1==_y&&x==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black)
                ||find(begin(boxes),end(boxes),arr[_y][_x]) != end(boxes))
                {
                    WhiteMovement(arr,y,x,_x,_y);
                }
                //arr[y+1][x]=" X ";
            }
                 
        }

        cout<<"king"<<endl;
    }
    else if(figure==" ♟︎ ")
    {
        if(_y==y-1)
        {
            if(x-1==_x||x+1==_x)
            {
                if(find(begin(black),end(black),arr[_y][_x]) != end(black))
                {   
                    WhiteMovement(arr,y,x,_x,_y);
                }
            }
            if(arr[y-1][x]==" ◻ "|| arr[y-1][x]==" ◼ ")
            {
                WhiteMovement(arr,y,x,_x,_y);
            }
            
        }
        else if (_y==y-2&&y==7)
        {
            WhiteMovement(arr,y,x,_x,_y);
        }
        
        cout<<"pawn"<<endl;
    }

}
void WhiteTurn(string arr[10][10])
{
    int x;
    int y;
    int _x;
    int _y;
    char str[100];   
    cout << " Enter a position of figure: " <<endl;  
    cin.getline(str, 100); 
      
    char *ptr;
    ptr = strtok(str, " ");
    char* words[5];
    int i=0;
    while (ptr != NULL)  //read inputs
    { 
        words[i]=ptr;
        ptr = strtok (NULL, " , ");
        i++; 
    }
    for(int a=0;a<10;a++)
    {
        string str_(words[0]);
        str_=' '+str_+' '; 
        if(arr[0][a]==str_)
        {
            x=a;
        }
        str_="";
    }
    for(int k=0;k<10;k++)
    {   
        string str_(words[1]);
        if(arr[k][0]==str_)
        {
            y=k;
        }
        str_="";
    }
    for(int a=0;a<10;a++)
    {
        string str_(words[2]);
        str_=' '+str_+' '; 
        if(arr[0][a]==str_)
        {
            _x=a;
        }
        str_="";
    }
    for(int k=0;k<10;k++)
    {   
        string string_(words[3]);
        if(arr[k][0]==string_)
        {
            _y=k;
        }
        string_="";
    }
    //cout<<_x<<endl;
    //cout<<_y<<endl;
    //pos=atoi(words[2]);// char to int 
    GetWhiteFigure(arr,y,x,_x,_y);
    //system("cls");
    RenderBoard(arr);

       
}

int main()
{
  string arr[10][10]={{"  ",""," A "," B "," C "," D "," E "," F "," G "," H "},
                    {"8"," "," ♖ "," ♘ "," ♗ "," ♕ "," ♔ "," ♗ "," ♘ "," ♖ "},
                    {"7"," "," ♙ "," ♙ "," ♙ "," ♙ "," ♙ "," ♙ "," ♙ "," ♙ "},
                    {"6"," "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "},
                    {"5"," "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "},
<<<<<<< HEAD
                    {"4"," "," ◼ "," ◻ "," ◼ "," ♚ "," ◼ "," ◻ "," ◼ "," ◻ "},
=======
                    {"4"," "," ◼ "," ◻ "," ◼ "," ♝ "," ◼ "," ◻ "," ◼ "," ◻ "},
>>>>>>> 8c9db727621b7df84e69ae53d460d22a2eb65316
                    {"3"," "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "," ◻ "," ◼ "},
                    {"2"," "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "," ♟︎ "},
                    {"1"," "," ♜ "," ♞ "," ♝ "," ♛ "," ♚ "," ♝ "," ♞ "," ♜ "}};
    RenderBoard(arr);
    while(true)
    {
    WhiteTurn(arr);
    }
    

}