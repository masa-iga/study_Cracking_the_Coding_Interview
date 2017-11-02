/*
  Question:
    Explain how you would design a chat server. In particular, provide detail about the various backend components,
    classes, and methods. What would be the hardest problem to solve?

  How to approach:
    1. Handle ambiguity
    2. Define core classes
    3. Analyize relashinships
    4. Investigate actions
*/

/*
  Let's make assumption like these:
    - Imagine Skype
    -- Need a client software
    -- Login via account
    -- Friend/contact list
    -- Suppots not only one-on-one chat (private), but also group chats

  Core classes
    - Server
    - View
    - Controller
*/

/*
  [Answer]
  What specific actions does it need to support?
    - Signing online and offline
    - Add requests (sending, accepting, and rejecting)
    - Updating a status message
    - Creating private and group chats
    - Adding new messages to private and group chats
  
  What can we learn about these requirements?
    We must have a concept of users, add request status, online status, and messages.
    
  What are the core components of the system?
    a database, a set of clients, and a set of servers,
    but we won't include these parts in our OOD here.
    
  What are the key objects and methods?
    a concept of users, conversations, and status messages.
*/

/*

class UserManager {
    {static}  UserManager : instance
    HashMap<int, User> : usersById
    HashMap<string, User> : usersByAccountName
    HashMap<int, User> : onlineUsers
    
    {static} UserManager : getInstance()
    void  : addUser(User, string toAccountName)
    void  : approveAddRequest(AddRequest)
    void  : rejectAddRequest(AddRequest)
    void  : userSignedOn(string accountName)
    void  : userSignedOff(string accountName)
}

class User {
    int : id
    UserStatus : status
    HashMap<int, PrivateChat> : privateChats
    ArrayList<GroupChat> : groupChats
    HashMap<int, AddRequest> : receiveAddRequests
    HashMap<int, AddRequest> : sentAddRequests
    HashMap<int, User> : contacts
    string : accountName
    string : fullName
    
    bool sendMessageToUser(User, string)
    bool sendMessageToGroupChat(int id, string)
    void setStatus(UserStatus)
    UserStatus getStatus()
    bool addContact(User)
    void receiveAddRequest(AddRequest)
    void sentAddRequesst(AddRequest)
    void removeAddRequest(AddRequest)
    void addConversation(PrivateChat)
    void addConversation(GropuChat)
    int getId()
    string getAccountName()
    string getFullName()
}

abstract class Conversation {
    # ArrayList<User> : participants
    # int : id
    # ArrayList<Message> : messages
    
    ArrayList<Message> : getMessages()
    bool : addMessage(Message)
    int : getId()
}

class GroupChat {
    void : removeParticipant(User)
    void : addParticipant()
}

class PrivateChat {
    PrivateChat(User user1, User user2)
    User : getOtherParticipant(User)
}

class Message {
    string : content
    Date : date
    
    Message(string content, Date date)
    string : getContent()
    Date : getDate()
}

class AddRequest {
    User : fromUser
    User : toUser
    Date : date
    RequestStatus : status
    
    AddRequest(User from, User to, Date date)
    RequestStatus : getStatus()
    User : getFromUser()
    User : getToUser()
    Date : getDate()
}

class UserStatus {
    string : message
    UserStatusType : type
    
    UserStatus(UserStatusType, string)
    UserStatusType : getStatusType()
    string : getMessage()
}
enum UserStatusType {
    offline
    Away
    Idle
    Available
    Busy
}
enum RequestsStatus {
    Unread
    Read
    Accepted
    Rejected
}
UserManager o-- User
Conversation <|-- GroupChat
Conversation <|-- PrivateChat
Conversation *-- Message
User *-- UserStatus
User *-- GroupChat
User *-- PrivateChat
UserStatus o-- UserStatusType
AddRequest o-- RequestsStatus 

*/

/*
  What problems would be the hardest to solve (or the most interesting)?
    Q1: How do we know if someone is online?
      While we would like users tell us when they sign off, we can't know for sure.
      A user's connection might have died, for example. To make sure that we know when a user has signed off,
      we might try regulary pinging the client to make sure it's still there.
    
    Q2: How do we deal with conflicting information?
      We have some information stored in the computer's memory and some in the database.
      What happens if they get out of sync? Which one is "right"?
    
    Q3: How do we make our server scale?
      While we designed our chat server without worrying - too much - about scalability, in
      real life this would be a concern. We'd need to split our data across many servers, which
      would increase our concern about out-of-sync data.
    
    Q4: How do we prevent denial of service attacks?
      Clients can push data to us - what if they try to DOS (denial of service) us? How do we
      prevent that?
*/
