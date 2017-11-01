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
    
    static UserManager getInstance()
    void addUser(User, string)
    void approveAddRequest(AddRequest)
    void rejectAddRequest(AddRequest)
    void userSignedOn(string)
    void userSignedOff(string)
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
