CPP = g++ -I include
INCLUDE = include
OBJ_DIR = obj
BIN_DIR = bin

${OBJ_DIR}/merge_sort.o : merge_sort.cpp ${INCLUDE}/sorting.h;\
$(CPP) -c merge_sort.cpp -o ${OBJ_DIR}/merge_sort.o

${BIN_DIR}/merge_sort : ${OBJ_DIR}/merge_sort.o;\
${CPP} -o ${BIN_DIR}/merge_sort ${OBJ_DIR}/merge_sort.o

# Build binary search
${OBJ_DIR}/binary_search.o : binary_search.cpp ${INCLUDE}/searching.h;\
$(CPP) -c binary_search.cpp -o ${OBJ_DIR}/binary_search.o

${BIN_DIR}/binary_search : ${OBJ_DIR}/binary_search.o;\
${CPP} -o ${BIN_DIR}/binary_search ${OBJ_DIR}/binary_search.o

# Build rectangle overlap
${OBJ_DIR}/rectangle_overlap.o : rectangle_overlap.cpp;\
${CPP} -c rectangle_overlap.cpp -o ${OBJ_DIR}/rectangle_overlap.o

${BIN_DIR}/rectangle_overlap : ${OBJ_DIR}/rectangle_overlap.o;\
${CPP} -o ${BIN_DIR}/rectangle_overlap ${OBJ_DIR}/rectangle_overlap.o

# Build linked list palindrome checker
${OBJ_DIR}/linked_list_palindrome.o : linked_list_palindrome.cpp;\
${CPP} -c linked_list_palindrome.cpp -o ${OBJ_DIR}/linked_list_palindrome.o

${BIN_DIR}/linked_list_palindrome : ${OBJ_DIR}/linked_list_palindrome.o;\
${CPP} -o ${BIN_DIR}/linked_list_palindrome ${OBJ_DIR}/linked_list_palindrome.o

# Build binary tree
${OBJ_DIR}/binary_tree.o : binary_tree.cpp;\
${CPP} -c binary_tree.cpp -o ${OBJ_DIR}/binary_tree.o

${BIN_DIR}/binary_tree : ${OBJ_DIR}/binary_tree.o;\
${CPP} -o ${BIN_DIR}/binary_tree ${OBJ_DIR}/binary_tree.o

OBJECTS = ${BIN_DIR}/merge_sort\
          ${BIN_DIR}/binary_search\
          ${BIN_DIR}/rectangle_overlap\
          ${BIN_DIR}/linked_list_palindrome\
          ${BIN_DIR}/binary_tree\
          ${OBJ_DIR}/merge_sort.o\
          ${OBJ_DIR}/binary_search.o\
          ${OBJ_DIR}/rectangle_overlap.o\
          ${OBJ_DIR}/linked_list_palindrome.o\
          ${OBJ_DIR}/binary_tree.o

all: ${OBJECTS}
clean: ${OBJECTS};\
rm ${OBJECTS}

