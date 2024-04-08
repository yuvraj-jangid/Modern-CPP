#include <iostream>

/*
    represent "state" of "something"!
*/

class TrainingSession {
/*
    _duration (in hours) : int
    _studentCount : unsigned int 
    _trainerName : string
    _sessionTopic : string
    _date : date
*/
}; // represent state 


class ID {
/*
    _country : COUNTRY
    _year : 24
    _month : 01
    _track_level : LEVEL
    _batch_number : 01
    _location : optional
    _track_name : Track
    _talents : Container<Talent>

*/
};


class TrainingBatch {
/*
    _id : ID
    _strength : unsigned int
    _trainer : Trainer------------------PERSON
    _pmt_coordinator : Coordinator------PERSON
    _schedule : Schedule
*/
};

/*
    Pointer ka state representation
        ---> Smart Pointers
    Reference ka state representation
        ---> referance_wrapper
    Thread (set of instructions)
        - std::async
    Semaphore ka state
        --- lock_guard
        ---> unique_lock
    Union ka state represent
        ---> std::variant

*/
