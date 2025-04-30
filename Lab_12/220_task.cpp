#include <bits/stdc++.h>
using namespace std;

class Book
{
private:
    string title;
    string author;
    string ISBN;

public:
    Book(string ti, string au, string isbn) : title(ti), author(au), ISBN(isbn) {}

    string get_title() {
        return title;
    }
    string get_author() {
        return author;
    }
    string get_ISBN() {
        return ISBN;
    }
    void display() {
        cout << "Title : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "ISBN : " << ISBN << endl;
    }

};

class Library {
private:
    vector<Book> inventory;
    deque<Book> borrowedBooks;
    list<Book> archivedBooks;
public:
    void addBook(){
        string name , author , ISBN ;

        cout << "Enter The Book name : " ; 
        cin >> name ; 
        cout << "Enter the Author name : " ; 
        cin >> author ;
        cout << "Enter the ISBN number : " ; 
        cin >> ISBN ;

        Book b(name,author,ISBN) ;
        inventory.push_back(b) ;
    }
    void borrowBook( string ISBN) {
        for (auto itr=inventory.begin();itr!=inventory.end();itr++){

            if (itr->get_ISBN()==ISBN){
                borrowedBooks.push_back(*itr) ;
                inventory.erase(itr) ;
                break ;
            }
        }

    }
    void returnBook( string ISBN) {
        for (auto it=borrowedBooks.begin();it!=borrowedBooks.end();it++){
            if (it->get_ISBN()==ISBN){
                inventory.push_back(*it) ;
                borrowedBooks.erase(it) ;
                break ;
            }
        }
    }
    void archiveBook( string ISBN) {
        for (auto it=inventory.begin();it!=inventory.end();it++){
            if (it->get_ISBN()==ISBN){
                archivedBooks.push_back(*it) ;
                inventory.erase(it) ;
                break ;
            }
        }
    }

    void saveData(){

        ofstream invent("inventory.txt") ;
        if (!invent){
            cout << "inventory.txt not present " << endl ;
        }
        else {
            for(auto &book:inventory){
                invent <<  book.get_title() << "," 
                << book.get_author() <<"," 
                << book.get_ISBN() << endl ;
            }
            //cout<<"entered in inventory.txt"<<endl;
        }
        invent.close() ;


        ofstream borrowed("borrowed.txt") ; 
        if (!borrowed){
            cout << "borrowed.txt not present " << endl ;
        }
        else {
            for(auto &book:borrowedBooks){
                borrowed <<  book.get_title() << "," 
                << book.get_author() <<"," 
                << book.get_ISBN() << endl ;
            }            
        }
        borrowed.close() ;


        ofstream archive("archived.txt") ;
        if (!archive){
            cout << "archived.txt not present " << endl ;
        }
        else {
            for(auto &book:archivedBooks){
                archive <<  book.get_title() << "," 
                << book.get_author() <<"," 
                << book.get_ISBN() << endl ;
            }             
        }
        archive.close() ;
    }

    void loadData() {
        ifstream invent("inventory.txt") ;
        if (!invent){
            cout << "inventory.txt not found ! " << endl ;
        }
        else {
            string str ;
            while(getline(invent,str)){
                string name , author , ISBN ; 
                istringstream ss(str) ; 

                getline(ss,name,',') ; 
                getline(ss,author,',') ;
                getline(ss,ISBN) ;

                Book b(name,author,ISBN) ;
                inventory.push_back(b) ;
            }
        }
        invent.close() ;


        ifstream borrowed("borrowed.txt") ; 
        if (!borrowed){
            cout << "borrowed.txt not found ! " << endl ;
        }
        else {
            string str ;
            while(getline(borrowed,str)){
                string name , author , ISBN ; 
                istringstream ss(str) ; 

                getline(ss,name,',') ; 
                getline(ss,author,',') ;
                getline(ss,ISBN) ;

                Book b(name,author,ISBN) ;
                borrowedBooks.push_back(b) ;
            }
        }
        borrowed.close() ;


        ifstream archive("archived.txt") ;
        if (!archive){
            cout << "archived.txt not found ! " << endl ;
        }
        else {
            string str ;
            while(getline(archive,str)){
                string name , author , ISBN ; 
                istringstream ss(str) ; 

                getline(ss,name,',') ; 
                getline(ss,author,',') ;
                getline(ss,ISBN) ;

                Book b(name,author,ISBN) ;
                archivedBooks.push_back(b) ;
            }
        }
        archive.close() ;
    }


    void displayInventoryBooks() {
        cout << "Inventory:" << endl;
        for (auto &book : inventory) {
            cout << book.get_ISBN() << " ";
        }
        cout << endl;
    }

    void displayBorrowedBooks() {
        cout << "Borrowed Books:" << endl;
        for ( auto &book : borrowedBooks) {
            cout << book.get_ISBN() << " ";
        }
        cout << endl;
    }

    void displayArchivedBooks() {
        cout << "Archived Books:" << endl;
        for ( auto &book : archivedBooks) {
            cout << book.get_ISBN() << " ";
        }
        cout << endl;
    }

    
};

int
main(){
    // Book b1("a","aa","aaa");
    // b1.display();

    Library l;
    // l.addBook();
    // l.addBook();
    // l.addBook();


    // l.borrowBook("bbb");
    // l.archiveBook("ccc");
    
    // l.saveData();
    l.loadData();
    
    l.displayInventoryBooks();
    l.displayArchivedBooks();
    l.displayBorrowedBooks();

}