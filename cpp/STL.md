# STL - Functions

Summary of some important functions from C++ STL frequently used.
The functions are sorted by their header


## <algorithm> 


## <cstdio>

  fgets(char* str, int count, std::FILE* stream)
  		
	Reads at most count-1 characters from file str
	Stops if newline is found (str will contain newline character)

	RETURNS:


  getline(char** lineptr, size_t* n, FILE* stream)

 	reads entire line from stream, storing line in lineptr. lineptr includes newline if found.
	If lineptr is set to NULL and n to 0, then buffer is allocated

	RETURNS: On success, the number of characters read
