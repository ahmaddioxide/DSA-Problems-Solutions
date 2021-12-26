// Coded by ahmaddioxide
// for more visit https://github.com/ahmaddioxide/
#include <iostream>
#include <string>
#include<fstream>

using namespace std;

class node
{
private:
    /* data */
public:
    string name;//! name  of the movie or actor(depends)
    node* next;//! pointing to next Movie
    node* below;//! pointing to the actors node below movie node
    //!* FUNCTION *//
    node(/* args */);
    ~node();
};

node::node(/* args */)
{
    name = "";
    next = NULL;
    below = NULL;
}

node::~node()
{
}

class Directory
{
private:
    /* data */
public:
    node* head;//! Head node of a directory which is basically the movie node (1st movie)
    //* Functions *//
    Directory(/* args */);
    ~Directory();
    node* insertNext(string MovieName);//!FUNCTION to insert new Movie in the directory
    node* insertBelow(string ActorName, node* currentMovienode);//!function to insert the actors under a node->(Movie node) which is passed in this function 
    void Search(string MovieName);//!function to search the Movie from directory
    void DisplayActors(node* currentMovienode);//!function to display the actors of specific Movie which passes in function (helping function of search movie)
};

Directory::Directory(/* args */)
{
    head = NULL;
}

Directory::~Directory()
{
}

node* Directory::insertNext(string MovieName)
{
    node* newMovie = new node;
    newMovie->name = MovieName;
    node* temp = new node;
    temp = head;
    if (head == NULL)
    {
        head = newMovie;
        //cout << "\n| MovieName added to head";
        return head;
    }
    else
    {

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newMovie;
       // cout << "\n| MovieName added!";
    }
    return temp->next;
}

node* Directory::insertBelow(string ActorName, node* currentMovienode)
{
    node* newActor = new node;
    newActor->name = ActorName;
    node* temp = new node;
    temp = currentMovienode;
    if (currentMovienode->below == NULL)
    {
        currentMovienode->below = newActor;
        //cout << "\n| Actor added to " << currentMovienode->name << "'s 1st below|";
        return currentMovienode->below;
    }
    else
    {
        node* temp = new node;
        temp = currentMovienode;
        while (temp->below != NULL)
        {
            temp = temp->below;
        }
        temp->below = newActor;
        //cout << "\n| ActorName added! to " << currentMovienode->name << "'s below|";
    }
    return temp->below;

}

void Directory::Search(string MovieName)
{
    node * temp= new node;
    bool found = false;
    temp=head;
    while (temp->next != NULL)
    {
        if (temp->name==MovieName)
        {
            found = true;
            cout<<"\n\n\n| Movie : "<<temp->name;
            DisplayActors(temp);

            
        }
        temp=temp->next;
    }
    if(found==false)
    {
        cout<<"\n| Movie is not present in Directory :( ";
    }
}

void Directory::DisplayActors(node * currentMovienode)
{
    node* temp = new node;
    temp= currentMovienode->below;
    cout<<"\n| Actors are : \n";
    while (temp!=NULL)
    {
        cout<<"  "<<temp->name;
        cout<<"\n";
        temp=temp->below;
        
    }

    cout<< "\n\n";
    
}


int main()
{
    Directory D;//! Making object of Directory
    string line;//!string temp to store read data from file
    node* temp = new node;//!temp node to store Movie node finded from file
    
    //!Reading Data From file and storing  in directory//
    fstream obj;
    obj.open("moviefile.txt", ios::in);
    if (!obj)
    {
        cout << "\n| Error: Cannot open file";
    }
    else
    {
    newmoviefound:
        getline(obj, line);
        temp = D.insertNext(line);
        while (!obj.eof())
        {
            getline(obj, line);
            if (line[0] == '#')
            {
                goto newmoviefound;
            }
            D.insertBelow(line, temp);


        }

    }

    D.Search("CarnEvil (1998)");//! Test for search function 

    

}