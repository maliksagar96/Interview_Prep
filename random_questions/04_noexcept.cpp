/*

What does `noexcept` do, and why is it important for containers like `std::vector`?

Well noexcept makes our code work only if we know everything will go right. 
Suppose we are moving glasses from one shelf to the other. Suppose during the transfer we broke 1 glass. We are in a mess now. We don;t know what to do. 
noexcept will only proceed if we guarantee in the beginning that there won't be a breaking of glass at all. 

Now one simple example would be if suppose we are moving 3 vectors A, B and C. 
A and B moved correctly but C didn't. C didn't move properly because the move constructor or the move operator associated with C object was not written correctly. 
Then noexcept will terminate the program. This will happen during the runtime not during the compile time. 

*/



