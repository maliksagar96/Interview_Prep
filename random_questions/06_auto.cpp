/*
  8. When to use the keyword auto?

  a) We can use it with iterators. 
  like auto it = v.begin();

  b) With smart pointers
    auto p = make_unique<Point>(1,2);

*/

/*

 Que 8a) -When to use Array of structures?
 Ans - a) When we somehow want to loop over strcutures. 
        b) When we want the structures to be contiguous in memory. 
*/


/*
  10. **What are structured bindings? Show how they improve readability with `std::map` iteration.**  
*/


for (const auto& [name, score] : my_map) {
    std::cout << name << ": " << score << '\n';
}

/*
  Here the keyword auto is used and it binds name and score with the first and second of myMap objects. 
  previously if would be something like

  for(const auto& kv:myMap) {
    auto key = kv.first;
    auto value = kv.second;
  }

  .first and .second is less intuitive and
  name and score makes more sense. 

  This is one of the ways C++ is standardizing different containers. 

  This was addition in C++ 17 by the way.
*/