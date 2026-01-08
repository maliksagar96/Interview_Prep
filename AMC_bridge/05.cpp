5. Can you explain the difference between new and new[]? Is it possible to delete memory using delete[] allocated within the new operator?

new keyword is used to allocate memory to single objects. new [] is used to allocate memory to an array of objects. 
The pairing new should go with delete and new[] should go with delete[]. 

Using delete[] with new is undefined behaviour. new doesn't store any array size information. delete[] expects that information. Hence it is undefined behaviour.