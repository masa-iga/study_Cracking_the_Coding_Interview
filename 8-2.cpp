/*
Question

Imagine you have a call center with three levels of employees: respondent, manager, and director. An incoming telephone call must be first allocated to a respondent who is free. If the respondent can't handle the call, he or she must escalate the call to a manager. If the manager is not free or not able to handle it, then the call should be escalated to a director. Design the classes and data structures for this problem. Implement a method dispatchCall() which assigns a call to the first available employee.


How to approach OOD questions

Handle ambiguity
Define the core objects
Analyze relationships
investigate actions


                                      ,--------------------------.                                  
                                      |Call                      |                                  
                                      |--------------------------|                                  
                                      |-Level requiredLevel      |                                  
                                      |-int id                   |                                  
                                      |--------------------------|                                  
                                      |+Call(Level level, int id)|                                  
                                      `--------------------------'                                  
                                                    |                                               
                                                    |                                               
                          ,-------------------------------------------------.                       
                          |CallCenterSystem                                 |                       
                          |-------------------------------------------------|                       
                          |-vector<Respondent>    respondents               |                       
                          |-vector<Manager>       managers                  |                       
                          |-vector<Director>      directors                 |                       
                          |-------------------------------------------------|                       
                          |+CallCenterSystem getInstance()                  |                       
                          |+void inputHandler()                             |                       
                          |+void dispatchCall(Call call, Level level)       |                       
                          |+void assign(Employee employee, Call call)       |                       
                          |-Employee      findAvailableEmployee(Level level)|                       
                          `-------------------------------------------------'                       
                                                    |                                               
,---------------------------------.  ,---------------------------.   ,-----------------------------.
|Respondent                       |  |Manager                    |   |Director                     |
|---------------------------------|  |---------------------------|   |-----------------------------|
|---------------------------------|  |---------------------------|   |-----------------------------|
|+Respondent(RESPONDENT, id, name)|  |+Manager(NANAGER, id, name)|   |+Director(DIRECTOR, id, name)|
`---------------------------------'  `---------------------------'   `-----------------------------'
                                                    |                                               
                                                                                                    
                                    ,-----------------------------.                                 
                                    |Employee                     |                                 
                                    |-----------------------------|                                 
                                    |-Level level                 |                                 
                                    |-int id                      |                                 
                                    |-string name                 |                                 
                                    |-bool available              |                                 
                                    |-Call call                   |                                 
                                    |-----------------------------|                                 
                                    |+Employee(level, id, name)   |                                 
                                    |+void dispatchCall(Call call)|                                 
                                    |+void setCall(Call call)     |                                 
                                    |+void releaseCal()           |                                 
                                    |+bool getAvailable()         |                                 
                                    `-----------------------------'                                 
                                                    |                                               
                                            ,--------------.                                        
                                            |Level         |                                        
                                            |--------------|                                        
                                            |RESPONDENT = 0|                                        
                                            |MANAGER       |                                        
                                            |DIRECTOR      |                                        
                                            |MAX           |                                        
                                            |--------------|                                        
                                            `--------------'     



@startuml

enum Level {
    RESPONDENT = 0
    MANAGER
    DIRECTOR
    MAX
}

Employee o-- Level
class Employee {
    + Employee(level, id, name)
    + void dispatchCall(Call call)
    + void setCall(Call call)
    + void releaseCal()
    + bool getAvailable()
    - Level level
    - int id
    - string name
    - bool available
    - Call call
}

Respondent --|> Employee
class Respondent {
    + Respondent(RESPONDENT, id, name)
}

Manager --|> Employee
class Manager {
    + Manager(NANAGER, id, name)
}

Director --|> Employee
class Director {
    + Director(DIRECTOR, id, name)
}

Call --> CallCenterSystem
class Call {
    + Call(Level level, int id)
    - Level requiredLevel
    - int id
}

CallCenterSystem *-- Respondent
CallCenterSystem *-- Manager
CallCenterSystem *-- Director
class CallCenterSystem {
    + CallCenterSystem getInstance()
    + void inputHandler()
    + void dispatchCall(Call call, Level level)
    + void assign(Employee employee, Call call)
    - Employee      findAvailableEmployee(Level level)
    
    - vector<Respondent>    respondents
    - vector<Manager>       managers
    - vector<Director>      directors
}

@enduml



void Employee::dispatchCall(Call call) {
  CallCenterSystem system = callCenter.getInstance();
  int ret = system->dispatchCall(call, MANAGER);
  if (ret)
    releaseCall();
}

void CallCenterSystem::dispatchCall(Call call, Level level) {
  Employee* assignee = findAvailableEmployee(level);
  if (assignee) {
    assign(assignee, call);
    return ;
  }
  
  if (level < Level::DIRECTOR) {
    int nextLevel = level + 1;
    dispatchCall(call, nextLevel);
    return ;
  }
  
  Director* director = waitForAvailable(DIRECTOR, limit);
  if (director)
    assign(director, call);
  else
    printf("Could not find available director at all¥n");
}




                          ,--------------------------------------.                                                 
                          |CallHandler                           |                                                 
                          |--------------------------------------|                                                 
                          |-static CallHandler* instance         |                                                 
      ,---------------.   |-const int LEVELS = 3                 |                                                 
      |eEmployeeLevels|   |-const int NUM_RESPONDENTS = 10       |   ,-----------.   ,----------.   ,-------------.
      |---------------|   |-const int NUM_MANAGERS = 4           |   |Director   |   |Manager   |   |Respondent   |
      |respondents = 0|   |-const int NUM_DIRECTORS = 2          |   |-----------|   |----------|   |-------------|
      |managers       |---|-Vector<Vector<Call>> callQueues      |   |-----------|   |----------|   |-------------|
      |directors      |   |--------------------------------------|   |+Director()|   |+Manager()|   |+Respondent()|
      |---------------|   |+static CallHandler getInstance()     |   `-----------'   `----------'   `-------------'
      `---------------'   |+Employee getHandlerForCall(Call call)|                         |                       
               |          |+void dispatchCall(Caller caller)     |                         |                       
               |          |+void dispatchCall(Call call)         |                         |                       
               |          |+bool assignCall(Employee emp)        |                         |                       
               |          `--------------------------------------'                         |                       
               |                                                                           |                       
               |                                                                           |                       
,----------------------------.                                                             |                       
|Call                        |                                              ,----------------------------.         
|----------------------------|                                              |Employee                    |         
|-Rank rank                  |                                              |----------------------------|         
|-Caller caller              |                                              |-Call currentCall = NULL    |         
|-Employee handler           |                                              |#Rank rank                  |         
|----------------------------|                                              |----------------------------|         
|+Call(caller c)             |                                              |+void receiveCall(Call call)|         
|+void setHandler(Employee e)|                                              |+void callCompleted()       |         
|+void reply(String message) |                                              |+void escalateAndReassign() |         
|+Rank getRank()             |                                              |+bool assignNewCall()       |         
|+void setRank(Rank r)       |                                              |+bool isFree()              |         
|+Rank incrementRank()       |                                              |+Rank getRank()             |         
|+void disconnect()          |                                              `----------------------------'         
`----------------------------'                                                                                     


@startuml

enum eEmployeeLevels {
    respondents = 0
    managers
    directors
}

class CallHandler {
    + static CallHandler getInstance()
    + Employee getHandlerForCall(Call call)
    + void dispatchCall(Caller caller)
    + void dispatchCall(Call call)
    + bool assignCall(Employee emp)
    - static CallHandler* instance
    - const int LEVELS = 3
    - const int NUM_RESPONDENTS = 10
    - const int NUM_MANAGERS = 4
    - const int NUM_DIRECTORS = 2
    - Vector<Vector<Call>> callQueues
}

class Call {
    + Call(caller c)
    + void setHandler(Employee e)
    + void reply(String message)
    + Rank getRank()
    + void setRank(Rank r)
    + Rank incrementRank()
    + void disconnect()
    - Rank rank
    - Caller caller
    - Employee handler
}

class Employee {
    - Call currentCall = NULL
    # Rank rank
    + void receiveCall(Call call)
    + void callCompleted()
    + void escalateAndReassign()
    + bool assignNewCall()
    + bool isFree()
    + Rank getRank()
}

Director --|> Employee
class Director {
    + Director()
}

Manager --|> Employee
class Manager {
    + Manager()
}

Respondent --|> Employee
class Respondent {
    + Respondent()
}

@enduml


CallHandler* CallHandler::instance = NULL;

static CallHandler getInstance() {
  if (instance == NULL) instance = new CallHanlder();
  return instance;
}

void dispatchCall(Caller caller) {
  Call call = new Call(caller);
  dispatchCall(call);
}

void dispatchCall(Call call) {
  Employee emp = getHanlderForCall(call);
  if (emp != NULL) {
    emp.receiveCall(call);
    call.setHanlder(emp);
  } else {
    call.reply("Please wait for free employee to reply");
    callQueues[call.getRank().getValue()].push_back(call);
  }
}

Call::Call(Caller c) {
  rank = Rank.Responder;
  caller = c;
}



*/