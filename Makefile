filesort:filesort.o InsertionSort.o
	g++ -o filesort filesort.o InsertionSort.o

filesort.o:filesort.cpp
	g++ -c filesort.cpp

InsertionSort.o:InsertionSort.cpp
	g++ -c InsertionSort.cpp
