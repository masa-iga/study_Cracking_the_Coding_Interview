/*
  Question: Design the data structures for an online book reader system

  How to approcah:
    1. Handle ambiguity
    2. Define core objects
    3. Analyze relationships
    4. Investigate actions
*/

/*
  Assumptions:
    - Assume kidle online reader
    - A user which has an account can access his personal ebook
    - Generally, two users (accounts) access the ebook simultaneously
    - The service is available for several OSs. e.g. Windows, Mac, Android and iOS
    - User accesses the ebook via client software
*/

/*
  Core objects:
    - ClientModel
    - ClientViewer
    - ClientInterface
    - Server
*/

/*
  Actions:
    - Login
    - Show a ebook list
    - Select a book to read
    - Proceed to the next page
    - Back to the previous page
    - Close a book
    - Logout
*/

/*
@startuml

class ClientController {
}

ClientController -->ClientViewer : update
class ClientViewer {
}

ClientController --> Model : manipulate
class Model {
}

Model --> ClientViewer : update

@enduml
*/

/*
Answer:

@@startuml

class OnlineReaderSystem {
    - Library library
    - UserManager usermanager
    - Display display
    - Book activeBook
    - User activeUser
    
    + Library getLibrary()
    + UserManager getUserManager()
    + Display getDisplay()
    + Book getActiveBook()
    + void setActiveBook(Book book)
    + User getActiveUser()
    + void setActiveUser()
}

class Library {
    - map<int, Book> books
    + Book addBook(int id, string details)
    + bool remove(Book b)
    + bool remove(int id)
    + Book find(int id)
}

class UserManager {
    - map<int, User> users
    
    + User addUser(int id, string details, int accountType)
    + bool remove(User u)
    + bool remove(int id)
    + User find(int id)
}

class Display {
    - Book activeBook
    - User activeUser
    - int pageNumber = 0
    
    + void displayUser(User user)
    + void displayBook(Book book)
    + void turnPageForward()
    + void turnPageBackward()
    + void refreshUsername()
    + void refreshTitle()
    + void refreshDetails()
    + void refreshPage()
}

class Book {
    - int bookId
    - string details
    
    + int getId()
    + void setID(int id)
    + string getDetails()
    + void setDetails(string d)
}

class User {
    - int userId
    - string details
    - int accountType
    
    + int userId
    + string details
    + int accountType
    + void renewMembership()
    + int getID()
    + void setID(int id)
    + string getDetails()
    + void setDetails(string details)
    + int getAccountType()
    + void setAccountType(int t)
}

OnlineReaderSystem o-- Library
OnlineReaderSystem o-- UserManager
OnlineReaderSystem o-- Display

@enduml

*/

/*
  Assumptions:
    - User memberships creation and extension
    - Searching the database of books
    - Reading a book
    - Only one active user at a time
    - Only one active book by this user
*/
