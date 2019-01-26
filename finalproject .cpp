#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include<unistd.h>
#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>
using namespace std;
 HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
int gdriver=DETECT,gmode;

template <typename T>

T get_input(const string &strQuery);
string get_username();
string get_password();
void save_user(const string &username, const string &password);
void login();
void register_user();
void main_menu();

template <typename T>
T get_input(const string &strQuery)
{
    cout << strQuery << "\n> ";
    T out = T();

    while (!(cin >> out)) {
        cin.clear();
        cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        cout << "\t\t\t\t\tError!" "\n";

    }

    return out;
}

string get_password()
{
    string password1 = get_input <string> ("\t\t\tPlease enter your password.");
    string password2 = get_input <string> ("\t\t\tPlease re-enter your password.");

    while (password1 != password2) {
        cout << "\t\t\t\t\tError! Passwords do not match." "\n";
        password1 = get_input <string>("\t\t\tPlease enter your password.");
        password2 = get_input <string>("\t\t\tPlease re-enter your password.");
    }

    return password1;
}

string get_username()
{
    string username = get_input <string>("\t\t\tPlease enter a Username.");
    cout << "\t\t\tUsername: \t" << username <<endl;

    while (get_input <int>("\nConfirm your Username? [0|1]") != 1) {
        username = get_input <string>("\t\t\tPlease enter a Username.");
        cout << "\t\t\tUsername: \"" << username << "\t\t";
    }

    return username;
}

void login()
{
    string lines = " ";
    ifstream readFile("userandpassword.txt");
    string UserName;
    string Password;
    string _UserName;
    string _Password;
    char ch;
    cout << "\t\t\tEnter UserName: ";
    cin >> UserName;

    cout << "\t\t\tEnter Password: ";

    ch = _getch();
    while(ch != 13){
      Password.push_back(ch);
      cout << '*';
      ch = _getch();
   }

bool found = false;
    while (getline(readFile,lines)) {

        stringstream iss(lines);
        iss >> _UserName >> _Password;

        if (UserName == _UserName && Password == _Password) {
            cout<<"\t";

int plot=170,cord;
initgraph(&gdriver,&gmode,"C:\TC\BGI");
setcolor(11);
settextstyle(6,0,3);
outtextxy(130,140,"LOADING,PLEASE WAIT");

for(cord=0;cord<300;++cord)
{
delay(2);
line(plot,200,plot,220);
plot++;
}

closegraph();

SetConsoleTextAttribute(color, 12);
        cout<<endl;
        cout<<endl;
        cout<<endl;
            cout << "\t\tLogin Successful!"<< endl;
            delay(1500);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\tInvalid Username And Password"<< endl;
        cout<<"\tTo Register press 1 and for trying Logging again press 2"<<endl;
        int choice;
        cout<<"\t";
        cin>>choice;
        switch(choice)
        {
        case 1:
            register_user();
            break;
        case 2:
            login();
            break;
        }
    }

}

void main_menu()
{

    int choice = get_input <int>("\n\n"
        "\t\t\tHello, Would you like to Log in or Register?" "\n"
        "\t\t\t[1] Login" "\n"
        "\t\t\t[2] Register" "\n"
        "\t\t\t[3] Exit");

switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        register_user();
            cout<<"\t";

cout<<endl;
cout<<endl;
cout<<endl;

            break;
    case 3:exit(0);

}
}

void register_user()
{
    string username = get_username();
    string password = get_password();
    save_user(username, password);
}

void save_user(const string &username, const string &password)
{
    ofstream myfile;
  myfile.open("userandpassword.txt",ios::app);
  myfile << username<< " "<< password;
  myfile<<'\n';
  myfile.close();
}

void Welcome_window()
{

SetConsoleTextAttribute(color, 14);
    cout<<"\t\t\tWelcome to our Travel Agency\n\n\n";

    cout<<"\t\t\tThe Agency is managed by: \n\n\n";

cout<<"\t\t\tSACHIN KUMAR\n\n";
  
}

class Pair
{
public:
    string destination;
    float dist;
    int condition;
    Pair(string dest, float weight,int cond=1)

{
       destination=dest;
       dist=weight;
       condition=cond;
    }
};

class myComparator
{
public:
    int operator() (Pair p1, Pair p2)
    {
        return p1.dist > p2.dist;
    }
};

class Graph
{
    int V;
    map<string, list< Pair > > adjList;
public:
    Graph(int v)
    {
        V=v;
    }

void addEdge(string src, string dest,float wt,int condition)
    {
        Pair p (dest,wt,condition);
        Pair k (src,wt,condition);
        adjList[src].push_back(p);
        adjList[dest].push_back(k);
    }

void print()

    {

for(auto it=adjList.begin();it!=adjList.end();it++)
        {
            cout<<"\t"<<(it)->first<<" -->\t";
            for(auto lit=((it)->second).begin();lit!=((it)->second).end();lit++)
            {
               cout<<(lit)->destination<<",";
            }
            cout<<endl;
        }
        cout<<endl;

    }

void printAllPathsUtil(string u, string d, map<string,bool> &visited, string path[], int &path_index,int cond,float wt,int rate)
        {
            visited[u] = true;
            path[path_index] = u;
            path_index++;

            if (u.compare(d)==0)
            {
                cout<<"\t";
                for (int i = 0; i<path_index; i++)
                    cout << path[i] << "-->";
                cout << endl;
                cout << endl;
                if(cond<=-1)
                        cout<<"\tThe travel conditions are Bad "<<endl;
                    else if(cond==0)
                    cout<<"\tThe travel conditions are Normal "<<endl;
                    else cout<<"\tThe travel conditions are Good "<<endl;
                    cout << endl;

                cout<< "\tThe distance for the route being "<< wt<<" KM"<<endl;
                cout << endl;
                cout<<"\tThe cost of Travel Inclusive of Taxes : Rs "<<wt*rate<<endl;
                cout << endl;cout << endl;cout << endl;
            }

            else
            {
                for (auto i = adjList[u].begin(); i != adjList[u].end(); ++i)
                    if (!visited[i->destination])
                        printAllPathsUtil(i->destination,d, visited, path, path_index,cond+i->condition,wt+i->dist,rate);
            }

            path_index--;
            visited[u] = false;
        }

void Validate_input(string &src,string &des)
        {
            if(( adjList.find(src) == adjList.end() )) {
                cout<<"\tSource Could Not be Found, Renter\n";
                string src1;
                cin>>src1;
                src=src1;
           }
           if(( adjList.find(des) == adjList.end() )) {
                cout<<"\tDestination Could Not be Found, Renter\n";
                string des1;
                cin>>des1;
                des=des1;

           }


        }

void printAllPaths(string s, string d,int rate)
        {
            map<string,bool> visited;
            for(auto it=adjList.begin();it!=adjList.end();it++)
                {
                    visited[it->first]=false;
                }
            string *path = new string[V];
            int path_index = 0;
            printAllPathsUtil(s, d, visited, path, path_index,0,0,rate);
        }


void Dijkstras(string src,string des,int rate)
    {

map<string ,float > distance;
        map<string, int> conditions;
        map<string,string> parent;

for(auto it=adjList.begin();it!=adjList.end();it++){
            distance[it->first]=INT_MAX;
        }
distance[src]=0;
conditions[src]=0;

        priority_queue<Pair,vector<Pair>, myComparator> Q;
        Pair P(src,distance[src],conditions[src]);
        Q.push(P);
        string last;

while(!Q.empty())
        {
            Pair Temp=Q.top();
            Q.pop();
            string u=Temp.destination;last=Temp.destination;

    for(auto it=adjList[u].begin();it!=adjList[u].end();it++)
            {
                Pair f = *it;
                string v = f.destination;
                float w = f.dist;
                int cond=f.condition;
                if(distance[u]+w<distance[v])
                {
                    parent[v]=u;
                    distance[v]=distance[u]+w;
                    conditions[v]=conditions[u]+cond;
                    Pair L(v,distance[v],conditions[v]);
                    Q.push(L);
                }

    }

}
                if(distance[des]==INT_MAX){
                        cout<<"\n\n";
                    cout<<"\tNo Path between the source and the destination Exists, Sorry for the Inconvenience";
            exit(0);

            }

cout<<"-----SHORTEST ROUTE BETWEEN THE SORCE AND DESTINATION-------"<<endl;
cout<<endl;
cout<<endl;
cout<< "\tThe shortest distance between "<<src<<" and "<<des<< " is : "<<distance[des]<<" KM"<<endl;
cout<<endl;
cout<<endl;
cout<<"\tThe cost of Travel Inclusive of Taxes : Rs "<<distance[des]*rate<<endl;
cout<<endl;
cout<<endl;
cout<<"\tThe path Of the Shortest Route is: "<<endl;
cout<<endl;
cout<<endl;
cout<<"\t";
string k=des;
cout<<k<<"<--";

while(parent[k].compare(src)!=0)
                {
                   cout<<parent[k]<<" <--";
                   k=parent[k];
                }
cout<<src;
cout<<endl;
cout<<endl;
            if(conditions[des]<=-1)
                cout<<"\tThe travel conditions are Bad\n"<<endl;
            else if(conditions[des]==0)
            cout<<"\tThe travel conditions are Normal\n"<<endl;
            else cout<<"\tThe travel conditions are Good\n"<<endl;
}

void fn()
{
    SetConsoleTextAttribute(color, 10);
    cout<<"\tEnter the City from the list above:\t";
    string src;
    cin>>src;

    cin.ignore();
    cout<<"\tEnter Your Destination:\t";
    string dest;
    cin>>dest;
    Validate_input(src,dest);

     cout<<"\n";

int plotc=170,cordc;

initgraph(&gdriver,&gmode,"C:\TC\BGI");
setcolor(11);
settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
outtextxy(130,140,"READING DATABASE,PLEASE WAIT");

for(cordc=0;cordc<300;++cordc)
{
delay(2);
line(plotc,200,plotc,220);
plotc++;
}
closegraph();

SetConsoleTextAttribute(color, 03);

cout<<endl;
cout<<endl;


cout<<"\tSelect The Mode of Transport You Want to Travel By: "<<endl;
cout<<"------------------------------------------------------------------------------------------------"<<endl;
cout<<"\t[1] Aeroplane \n \t[2] Train \n \t[3] Bus \n\t[4] Taxi"<<endl;

int choice;

cout<<"\t";
    cin>>choice;
    cout<<"\n\n\t";

   cout<<endl;
   cout<<endl;

switch(choice)
    {
        case 1:

        {
            Dijkstras(src, dest, 10);
            cout<<"-----ALL ROUTES FROM SOURCE TO DESTINATION------"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            printAllPaths(src,dest,10);
        break;

        }

        case 2:

        {
            Dijkstras(src, dest, 5);
            cout<<"----ALL ROUTES FROM SOURCE TO DESTINATION------"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            printAllPaths(src,dest,5);
            break;

        }

        case 3:

        {
            Dijkstras(src, dest, 7);
            cout<<"---ALL ROUTES FROM SOURCE TO DESTINATION-----"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            printAllPaths(src,dest,7);
            break;

        }


        case 4:

        {
            Dijkstras(src, dest, 8);
            cout<<"-----ALL ROUTES FROM SOURCE TO DESTINATION----"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<endl;
            printAllPaths(src,dest,8);
            break;

        }

}
}
};


int main()
{
    Welcome_window();
    usleep(500000);

    Graph g(60);
    main_menu();
    usleep(200000);

    system("cls");

string lines = " ";
ifstream readFile("Distance-From-City (4).txt");
string source;
string destination;
string distance;
string condition;
    while (getline(readFile,lines))
{

stringstream iss(lines);
    iss >> source >> destination >> distance >> condition;
float D= strtof((distance).c_str(),0);
int C= atoi((condition).c_str());
g.addEdge(source,destination,D,C);

}
        cout<<"\n\n";


cout<<"-----THE LIST OF CITIES THAT THE AGENCY MANAGES ARE------";
    usleep(1000);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    g.print();
    g.fn();
    return 0;
}
