    //backward right
    for(int i =1;i<x-1;i++)
    {  
        if(arr[y-i][x-i]!=" ◻ "&& arr[y-i][x-i]!=" ◼ ")
        {  
            sub_arr[a]=arr[y-i][x-i];
            a++;
        }
    }
    for(int i=0;i<10;i++)
    {
        if(sub_arr[0]==" ♗ "||sub_arr[0]==" ♕ ")
        {
            cout<<"king check"<<endl;
            break;
        }
    }
    fill(begin(sub_arr),end(sub_arr),0);
    a=0;
    //backward left
    for(int i =1;i<x-1;i++)
    {  
        if(arr[y+i][x-i]!=" ◻ "&& arr[y+i][x-i]!=" ◼ ")
        {  
            sub_arr[a]=arr[y+i][x-i];
            a++;
        }
    }
    for(int i=0;i<10;i++)
    {
        if(sub_arr[0]==" ♗ "||sub_arr[0]==" ♕ ")
        {
            cout<<"king check"<<endl;
            break;
        }
    }
    fill(begin(sub_arr),end(sub_arr),0);
    a=0;
