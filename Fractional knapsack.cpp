#include<bits/stdc++.h>
using namespace std;

typedef struct 
{
    char name[100];
    double weight, price, ppw;
    double c=0.0;
} item;

void showVec(vector<item>AllItem, double totalprice)
{
    printf("Total Price Achieved: %.3lf\n",totalprice); 
    printf("List of selected items\n");
    for(int i=0; i< (int)AllItem.size(); i++)
    {
        if (AllItem[i].c==1) 
        {
            printf("%s taken with a fraction of 1 \n",AllItem[i].name);
        }
        else 
        {
            printf("%s taken with a fraction of %lf \n",AllItem[i].name, AllItem[i].c);
        }
    }
    cout<<"\n";
}

bool cmp(item cA, item cB) 
{
    return cA.ppw > cB.ppw;
}

void fractionKnapsack(vector<item> itemLt, double remSpace)
{

    sort(itemLt.begin(), itemLt.end(), cmp); 

    double totPriceAchieved = 0.0; 

    for(int i=0; i<(int)itemLt.size(); i++)
    {
        if( itemLt[i].weight<=remSpace)
        {
            totPriceAchieved += itemLt[i].price;  
            remSpace -= itemLt[i].weight;    
            itemLt[i].c=1;  
        }
        else  
        {
            itemLt[i].c=remSpace/itemLt[i].weight; 
            totPriceAchieved += (remSpace * itemLt[i].ppw); 
            remSpace = 0.0; 
            break;  
        }
    }
    showVec(itemLt,totPriceAchieved); 
}

/* Name : Shahadat Hossain
   ID : 191-115-098
   Batch : CSE47
   section : C
*/
int main()
{
    int totItem;
    double totSpace;
    item tpItem;

    while(scanf("%d %lf", &totItem, &totSpace)!=EOF) 
    {
        vector<item>itemList;
        for(int i=0; i<totItem; i++) 
        {
            scanf("%s %lf %lf",tpItem.name, &tpItem.price, &tpItem.weight);   
            tpItem.ppw = tpItem.price / tpItem.weight;   
            itemList.push_back(tpItem);  
        }
        cout<<"\n";
        fractionKnapsack(itemList,totSpace); 
    }
    return 0;
}
