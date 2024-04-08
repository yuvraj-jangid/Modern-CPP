/*
    Threads
        1) std::thread : they can be used for parallel/ concurrent tasks.
        They need to be joined or detached. 
        They do not catch the return values.

        2) std::condition_variables : In situations where one thread has to wait for an event to happen because
        of some other thread before completing his own activity Due to other operations, suchh threads may do some work before the event,
        hence are launched simultenously

        3) Container of std::thread : To manage multiple instances 
            std::thread efficiently. (map to functions, join, etc.)

        4) std::mutex v/s std::lock_guard v/s std::unique_lock
            - std::mutex mutex can be locked and unlocked manually only!
            - std::lock_gurad : scope-based / RAII principle following mutex. NO MANUAL LOCK/UNLOCK
            - std::unique_lock : Scope-based as well as manual lock/unlock.

        // synchronization primitives! (search on google)

        5) Real life :

            - Mercedes : NAVIGATION / MUSIC

            step 1 ---> unlock ----> start the accessories / electronics

                      ---> MAP ---> Load surronding/favourites/ emergeny alert then [Destination by user]
            step 2 --->
                      --> MUSIC

            ===> Situation 
                I want to launch that perfoms task A and B
                Task A does not depend on input parameter. But task B needs an input
                WE NEED TO LAUNCH THREAD THAT WANTS A PARAMETER EVEN WITHOUT A PARAMETER

                In these type of situations we use Async thread

            // std::future and std::async and std::promise
*/
