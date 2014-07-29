CPP = g++ -I include
INCLUDE = include
build/merge_sort.o : merge_sort.cpp ${INCLUDE}/sorting.h;\
$(CPP) merge_sort.cpp -o build/merge_sort.o
# Build binary search
build/binary_search.o : binary_search.cpp ${INCLUDE}/searching.h;\
$(CPP) binary_search.cpp -o build/binary_search.o

DIR = build
OBJECTS = ${DIR}/merge_sort.o\
          ${DIR}/binary_search.o

all: ${OBJECTS}

