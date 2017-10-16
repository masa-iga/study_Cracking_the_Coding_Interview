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

@startuml

class OnlineReaderSystem {
    - Library library
    - UserManager usermanager
    - Display display
    - Book activeBook
    - User activeUser
}

class Library {
    - map<int, Book> books
}

class UserManager {
    - map<int, User> users
}

class Display {
    - Book activeBook
    - User activeUser
    - int pageNumber = 0
}

class Book {
    - int bookId
    - string details
}

class User {
    - int userId
    - string details
    - int accountType
}

@enduml
*/
