# CPP Tutorial

## Run CPP program
- Regular run
  ```
  g++ -o <output_file> <input_file> && ./<output_file>
  ```

- Run with thread
  ```
  g++ -o <output_file> -pthread <input_file> && ./<output_file>
  ```

## C++ Code Snippet
- Detect windows or linux
  ```c++
  // _WIN32 - windows 32-bit or 64-bit
  // _WIN64 - windows 64-bit only
  // linux - gnu/linux
  // __unix__ - unix

  #ifdef _WIN32
    // your code
  #endif
  ```
