CPP = g++ -I include
INCLUDE = include
DIR = build

${DIR}/merge_sort.o : merge_sort.cpp ${INCLUDE}/sorting.h;\
$(CPP) merge_sort.cpp -o ${DIR}/merge_sort.o
# Build binary search
${DIR}/binary_search.o : binary_search.cpp ${INCLUDE}/searching.h;\
$(CPP) binary_search.cpp -o ${DIR}/binary_search.o
# Build rectangle overlap
${DIR}/rectangle_overlap.o : rectangle_overlap.cpp;\
${CPP} rectangle_overlap.cpp -o ${DIR}/rectangle_overlap.o

OBJECTS = ${DIR}/merge_sort.o\
          ${DIR}/binary_search.o\
          ${DIR}/rectangle_overlap.o

all: ${OBJECTS}

