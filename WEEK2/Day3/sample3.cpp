/*
    week 2:
        Function pointers
        Function wrapper 
            - A way to capture any callable in a type-earsed way

            - It can be used for the following
                - Pass as callable as a parameter 
                - Return a callable value 
                - Save functions as "values" in container/ variables
        
        Reference wrapper 
            - It is an object that internally stores reference to "something"
            - It uses pointer to reference conversion internally 
            - It can be replacement for raw reference everywhere in the code.
            - rvalues cannot be converted to reference wrapper.

        std::bind
            - used to create a partial function 
                - a function some parameters are already fixed 
            - redesign or tweek the sequence of parameters by swapping or repositing them as per requirment
*/
