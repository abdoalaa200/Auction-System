#include<iostream>
#include <string>

using namespace std;

struct st2
{
    string product;
    int n_sell;
}arr2[100];
struct st1
{
    string email;
    string pass;
    int points;
    string address;
    string phone;
};
struct st
{
    string name;
    string type;
    int price;
    int currunt_price;
    int n;
    int month;
    int n_product;
    bool stock;
}arr[100][100];

int user, index = 0, id = 1;

bool login(st1 arr1[])
{
    cout << "\x1B[2J\x1B[H";
    cout << "enter your email" << endl;
    bool flag = 0;
    string inn; cin >> inn;
    for (int i = 0; i < 100; i++)
    {
        if (inn == arr1[i].email)
        {
            cout << "enter your password" << endl;
            cin >> inn;
            if (arr1[i].pass == inn)
            {
                user = i;
                flag = 1;
                break;
            }
        }
    }
    if (flag == 1) { return 1; }
    else { cout << "wrong email or password" << endl; return 0; }
}
void regster(st1 arr1[])
{
    cout << "\x1B[2J\x1B[H";
    while (1)
    {
        cout << "enter your email" << endl;
        string inn; cin >> inn;
        bool flag = 0;
        for (int i = 0; i < 100; i++)
        {
            if (inn == arr1[i].email)
            {
                cout << "taken email" << endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0) { arr1[index].email = inn; break; }
    }
    cout << "enter your password" << endl;
    cin >> arr1[index].pass;
    cout << "enter your address" << endl;
    cin >> arr1[index].address;
    while (1)
    {
        cout << "enter your phone number" << endl;
        cin >> arr1[index].phone;
        if (arr1[index].phone.length() == 11 && arr1[index].phone < "99999999")
        {
            break;
        }
        else
        {
            cout << "wrong number" << endl;
        }
    }
    index++;
}
void start(st1 arr1[])
{
    while (1)
    {
        cout << "\x1B[2J\x1B[H";
        cout << "1-login" << endl;
        cout << "2-register" << endl;
        int n; cin >> n;
        if (n == 1)
        {
            if (login(arr1)) { break; }
        }
        else if (n == 2) { regster(arr1); }
    }
}
void buy(st1 arr1[])
{
    while (1)
    {
        cout << "\x1B[2J\x1B[H";
        cout << "1-search for a certan product" << endl;
        cout << "2-back" << endl;
        int n; cin >> n;
        string pr_type;
        if (n == 1) { cout << "enter the type of the product you are searching for" << endl; cin >> pr_type; }
        else if (n == 2) { break; }
        cout << "\x1B[2J\x1B[H";
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                if (arr[i][j].type == pr_type && i != user)
                {
                    cout << arr[i][j].n << "-(" << arr[i][j].name << ") " << arr[i][j].price << "$ " <<" currunt price "<< arr[i][j].currunt_price << "$ " << "available for " << arr[i][j].month << " monthes" << " / " << arr[i][j].n_product << " in stock" << endl;
                }
            }
        }
        while (1)
        {
            cout << "enter product number or enter -1 to return back" << endl;
            int d; cin >> d;
            if (d == -1) { break; }
            for (int i = 0; i < 100; i++)
            {
                for (int j = 0; j < 100; j++)
                {
                    if (arr[i][j].type == pr_type && arr[i][j].n == d && i!=user && arr[i][j].stock==1)
                    {
                        cout << "enter your price" << endl;
                        long z; cin >> z;
                        if (arr[i][j].currunt_price < z)
                        {
                            arr[i][j].currunt_price = z;
                        }
                        while (1)
                        {
                            cout << "rate the seller from 1/5" << endl;
                            int rate; cin >> rate;
                            if (rate >= 3 && rate < 6)
                            {
                                arr1[i].points++;
                                break;
                            }
                            else if (rate < 3 && rate>0)
                            {
                                if (rate >= 3)
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void sell()
{
    int i = 0, n;
    while (1)
    {
        cout << "\x1B[2J\x1B[H";
        cout << "1-sell a certan type of product" << endl;
        cout << "2-my products" << endl;
        cout << "3-back" << endl;
        cin >> n;
        if (n == 3) { break; }
        else if (n == 2)
        {
            while (1)
            {
                cout << "\x1B[2J\x1B[H";
                for (int i = 0; i < 100; i++)
                {
                    if (arr[user][i].n != 0 && arr[user][i].stock==1)
                    {
                        cout << arr[user][i].n << "-(" << arr[user][i].name << ") " << arr[user][i].currunt_price << "$ " << arr[user][i].n_product << "-in stock"<<endl;
                    }
                }
                cout << "enter the prouduct number that you are agree on it's price" << endl;
                cout << "enter -1 to back" << endl;
                int n; cin >> n;
                if (n == -1) { break; }
                else
                {
                    for (int i = 0; i < 100; i++)
                    {
                        if (arr[user][i].n == n && arr[user][i].stock==1)
                        {
                            bool flag = 0;
                            for (int j = 0; j < 100; j++)
                            {
                                if(arr2[j].product==arr[user][i].type)
                                {
                                    arr2[j].n_sell++;
                                    flag = 1;
                                }
                            }
                            if (flag == 0)
                            {
                                for (int j = 0; j < 100; j++)
                                {
                                    if (arr2[j].product.length() < 1)
                                    {
                                        arr2[j].product = arr[user][i].type;
                                        arr2[j].n_sell++;
                                        break;
                                    }
                                }
                            }
                            arr[user][i].currunt_price = 0;
                            arr[user][i].n_product--;
                            if (arr[user][i].n_product == 0)
                                arr[user][i].stock = 0;
                        }
                    }
                }
            }
        }
        else if(n==1)
        {
            while (arr[user][i].n != 0)
            {
                i++;
            }
            cout << "enter the product type" << endl;
            cin >> arr[user][i].type;
            cout << "enter the product name" << endl;
            cin >> arr[user][i].name;
            cout << "enter the product price" << endl;
            cin >> arr[user][i].price;
            arr[user][i].stock = 1;
            arr[user][i].n = id;
            id++;
            cout << "how long should the product be available in month" << endl;
            cin >> arr[user][i].month;
            cout << "how many items of the product is available" << endl;
            cin >> arr[user][i].n_product;
        }
    }
}
void best_selling()
{
    int max = 1;
    for (int i = 0; i < 100; i++)
    {
        if (arr2[i].n_sell > max)
        {
            max = arr2[i].n_sell;
        }
    }

    while (1)
    {
        cout << "\x1B[2J\x1B[H";
        for (int i = 0; i < 100; i++)
        {
            if (max == arr2[i].n_sell)
            {
                cout << arr2[i].product << " " << arr2[i].n_sell << "sell" << endl;
            }
        }
        cout << "enter -1 to back to the menu" << endl;
        int n; cin >> n;
        if (n == -1) { break; }
    }
}
void best_seller(st1 arr1[])
{
    int max = 1;
    for (int i = 0; i < 100; i++)
    {
        if (arr1[i].points > max)
        {
            max = arr1[i].points;
        }
    }

    while (1)
    {
        cout << "\x1B[2J\x1B[H";
        for (int i = 0; i < 100; i++)
        {
            if (max == arr1[i].points)
            {
                cout << arr1[i].email << " " << arr1[i].points << "points" << endl;
            }
        }
        cout << "enter -1 to back to the menu" << endl;
        int n; cin >> n;
        if (n == -1) { break; }
    }
}
void menu(st1 arr1[])
{
    while (1)
    {
        cout << "\x1B[2J\x1B[H";
        cout << "you are in" << endl;
        cout << "1-buy" << endl;
        cout << "2-sell" << endl;
        cout << "3-best seller" << endl;
        cout << "4-best selling prouduct" << endl;
        cout << "5-logout" << endl;
        cout << "6-exit" << endl;
        int n; cin >> n;
        if (n == 1) { buy(arr1); }
        else if (n == 2) { sell(); }
        else if (n == 3) { best_seller(arr1); }
        else if (n == 4) { best_selling(); }
        else if (n == 5) { start(arr1); }
        else if (n == 6) { break; }
    }
}
int main()
{
    system("color f1");
    st1 arr1[100] = {};
    start(arr1);
    menu(arr1);
    return 0;
}
