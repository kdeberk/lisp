
Making sure that memory is freed at the correct moment is a complicated business. As an attempt to 
solve this, we keep track of wnership for each function call. In the .c and .h files, the function 
parameters and return values are annotated with either `takes`, `copies` or `returns`:
- `takes`: ownership of the passed value is given, the value may no longer be used.
- `copies`: caller remains owner of the value.
- `returns`: caller gains ownership of the returned value.

If a certain scope is owner of a value, it's responsible for clearing it once it's no longer needed.
