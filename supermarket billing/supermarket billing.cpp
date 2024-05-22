#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

class shopping
{
private:
    int code{};
    float price{},discount{0};
    std::string name{};

public:
    void Administor();
    void menu();
    void buyer();
    void add();
    void edit();
    void rem();
    void liist();
    void receipt();
};

void shopping::menu()
{
    int number{0};
    if(number > 0)
    {
        shopping::liist();
    }
    a:
    int choice{} , Password{123};
    std::string Email{"Robby@gmail.com"};
    std::cout << "\t_________________________________________\n";
    std::cout << "\t           supermarket main menu         \n";
    std::cout << "\t_________________________________________\n";
    std::cout << "\t| 1)Administrator |\n";
    std::cout << "\t|                 |\n";
    std::cout << "\t| 2)Buyer         |\n";
    std::cout << "\t|                 |\n";
    std::cout << "\t| 3)Exit          |\n";
    std::cout << "\n\tenter your choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            {
                m:
                std::string email{};
                int password{};
                std::cout << "\tplease loggin\n";
                std::cout << "\tEnter email: ";
                std::cin >> email;
                std::cout << "\tPassword: ";
                std::cin >> password;
                if ( Email == email && Password == password )
                {
                    Administor();
                }
                else
                {
                    std::cout << "\tplease check your Email and password.\n";
                    goto m;
                    system("cls");
                }
                break;
            }
        case 2:
            {
                buyer();
                break;
            }
        case 3:
            {
                exit(0);
            }
        default:
            {
                std::cout << " please select from the given options.\n";
            }
    }
    goto a;
    ++number;
}

void shopping::Administor()
{
    m:
    int choice{};
    std::cout << "\n\tAdminister menu\n";
    std::cout << "\t|________1) Add the product_________|\n";
    std::cout << "\t|                                   |\n";
    std::cout << "\t|________2) modiy the product_______|\n";
    std::cout << "\t|                                   |\n";
    std::cout << "\t|________3) Delete the product______|\n";
    std::cout << "\t|                                   |\n";
    std::cout << "\t|________4) Back to main menu_______|\n";
    std::cout << "\n\tenter your choice: ";
    std::cin >> choice;
    switch(choice)
    {
        case 1:
            {
                add();
                break;
            }
        case 2:
            {
                edit();
                break;
            }
        case 3:
            {
                rem();
                break;
            }
        case 4:
            {
                menu();
                break;
            }
        default:
            {
                std::cout << " Please select from the given options \n";
            }
    }
    goto m;
}

void shopping::add()
{
    m:
    std::fstream data{};
    int c,token{0};
    float p,d;
    std::string n;
    std::cout << "\t\tAdd new product\n";
    std::cout << "\tProduct code: ";
    std::cin >> code;
    std::cout << "\tName of the product: ";
    std::cin >> name;
    std::cout << "\tPrice of product($): ";
    std::cin >> price;
    std::cout << "\tDiscount: ";
    std::cin >> discount;

    data.open("database.txt" , std::ios::in);
    if(!data)
    {
        data.open("database.txt" , std::ios::app|std::ios::out);
        data << " " << code << " " << name << " " << price << " " << discount << "\n";
        data.close();
    }
    else
    {
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c == code)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

    if (token == 1)
    {
            goto m;
    }
    else
    {
        data.open("database.txt" , std::ios::app|std::ios::out);
        data << " " << code << " " << name << " " << price << " " << discount << "\n";
        data.close();
    }
    }
    std::cout << " record inserted!\n";
}
void shopping::edit()
{
    std::fstream data,data1;
    int key{},token{},c{};
    float p{},d{};
    std::string n{};
    std::cout << "\t\tModify product\n";
    std::cout << "\tProduct code: ";
    std::cin >> key;

    data.open("database.txt" , std::ios::in);
    if (!data)
    {
        std::cout << "\tFile doesn't exist\n";
    }
    else
    {
        data1.open("database1.txt" , std::ios::app|std::ios::out);
        data>>code>>name>>price>>discount;
        while(!data.eof())
        {
            if(key == code)
            {
                 std::cout << "\tProduct new code: ";
                 std::cin >> c;
                 std::cout << "\tProduct name: ";
                 std::cin >> n;
                 std::cout << "\tPrice: ";
                 std::cin >> p;
                 std::cout << "\tDiscount: ";
                 std::cin >> d;
                 data1 << " " << c << " " << n << " " << p << " " << d << '\n';
                 std::cout << "\n\t record edited\n";
                 token++;
            }
            else
            {
                 data1 << " " << code << " " << name << " " << price << " " << discount << '\n';
            }
            data >> code >> name >> price >> discount;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if (token == 0)
        {
            std::cout << "\n\nRecord not found\n";
        }
    }
}

void shopping::rem()
{
    std::fstream data{},data1{};
    int key{},token{};
    std::cout << "\t\tDelete product\n";
    std::cout << "\tProduct code: ";
    std::cin >> key;
    data.open("database.txt" , std::ios::in);
    if (!data)
    {
        std::cout << "\tFile does not exist\n";
    }
    else
    {
        data1.open("database1.txt" , std::ios::app|std::ios::out);
        data >> code >> name >> price >> discount;
        while (!data.eof())
        {
            if (code == key)
            {
                std::cout << "product delete succesfully\n";
                token++;
            }
            else
            {
                data1 << " " << code << " " << name << " " << price << " " << discount << '\n';
            }
            data >> code >> name >> price >> discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt" , "database.txt");
        if (token==0)
        {
            std::cout << "\n\t record not found";
        }
    }
}

void shopping::buyer()
{
    m:
    int choice{};
    std::cout << "\t\tBuyer\n";
    std::cout << "\t_______\n";
    std::cout << "\t1)Buy product\n";
    std::cout << "\t2)Go back\n";
    std::cout << "\tenter your choice: ";
    std::cin >> choice;
    switch(choice)
    {
        case 1:
            {
                receipt();
                break;
            }
        case 2:
                menu();
                break;
        default:
            std::cout << "\tInvalid choice: ";
    }
    goto m;
}

void shopping::liist()
{
    std::fstream data{};
    data.open("database.txt" , std::ios::in);
    std::cout << "\n\n\t______________________________________\n";
    std::cout << "\tProno\t\tname\t\tprice\n";
    std::cout << "\n\t______________________________________\n";
    data>>code>>name>>price>>discount;
    while(!data.eof())
    {
        std::cout << '\t' << code << "\t\t" << name << "\t\t" << price << '\n';
        data>>code>>name>>price>>discount;
    }
    data.close();
}

void shopping::receipt()
{
    std::fstream data{};
    int arrc[100],arrq[100],c=0;
    float amount{0},total{0};
    char choice{};
    std::cout << "\n\n\t\t\tRecipt\n";
    data.open("database.txt" , std::ios::in);
    if (!data)
    {
        std::cout << "\tEmpty database\n";
    }
    else
    {
        data.close();
        liist();
        std::cout << "\t__________________________________\n";
        std::cout << "\t|                                |\n";
        std::cout << "\t|      Please place the order    |\n";
        std::cout << "\t|________________________________|\n";
        do
        {
            m:
            std::cout << "\tProduct code: ";
            std::cin >> arrc[c];
            std::cout << "\tProduct quantity: ";
            std::cin >> arrq[c];
            for(int i=0 ; i<c ; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    std::cout << "\tYou've already entered this code!\n";
                    goto m;
                }
            }
            ++c;
            std::cout << "\tWant to buy another product? press Y for Yes and press N for No: ";
            std::cin >> choice;
        }while(choice == 'y');

        std::cout << "\n\n\t___________________________________Receipt___________________________________\n";
        std::cout << "\tProduct NO\tProduct name\tQauntity\tPrice\tAmount with discount\n";
        for (int i=0 ; i<c ; i++)
        {
            data.open("database.txt" , std::ios::in);
            data>>code>>name>>price>>discount;
            while (!data.eof())
            {
                if (code == arrc[i])
                {
                    amount = price * arrq[i];
                    discount=amount - (amount * discount/100);
                    total = total + discount;
                    std::cout << '\n' << '\t' << code << "\t\t" << name << "\t\t" << arrq[i] << "\t\t" << price << '\t' << amount << "\t\t" << discount << '\n';
                }
            data>>code>>name>>price>>discount;
            }
            data.close();
        }

    }
    std::cout << "\n\n\t__________________________________________\n";
    std::cout << "\n\tTotal amount: " << total << '\n';
}

main()
{
    shopping s;
    s.menu();


    getch();
}
