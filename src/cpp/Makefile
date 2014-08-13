CPP = g++ -I include -Wc++11-extensions
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
${OBJ_DIR}/binary_tree.o : binary_tree.cpp ${INCLUDE}/binary_tree.h;\
${CPP} -c binary_tree.cpp -o ${OBJ_DIR}/binary_tree.o

${BIN_DIR}/binary_tree : ${OBJ_DIR}/binary_tree.o;\
${CPP} -o ${BIN_DIR}/binary_tree ${OBJ_DIR}/binary_tree.o

# Build stack
${OBJ_DIR}/stack.o : stack.cpp;\
${CPP} -c stack.cpp -o ${OBJ_DIR}/stack.o

${BIN_DIR}/stack : ${OBJ_DIR}/stack.o;\
${CPP} -o ${BIN_DIR}/stack ${OBJ_DIR}/stack.o

# Build max_bst
${OBJ_DIR}/max_bst.o : max_bst.cpp ${INCLUDE}/binary_tree.h;\
${CPP} -c max_bst.cpp -o ${OBJ_DIR}/max_bst.o

${BIN_DIR}/max_bst : ${OBJ_DIR}/max_bst.o;\
${CPP} -o ${BIN_DIR}/max_bst ${OBJ_DIR}/max_bst.o


# Build sort w.r.t. other array
${OBJ_DIR}/sort_wrt_another_array.o : sort_wrt_another_array.cpp ${INCLUDE}/searching.h ${INCLUDE}/sorting.h;\
${CPP} -c sort_wrt_another_array.cpp -o ${OBJ_DIR}/sort_wrt_another_array.o

${BIN_DIR}/sort_wrt_another_array : ${OBJ_DIR}/sort_wrt_another_array.o;\
${CPP} -o ${BIN_DIR}/sort_wrt_another_array ${OBJ_DIR}/sort_wrt_another_array.o

OBJECTS = ${BIN_DIR}/merge_sort\
          ${BIN_DIR}/binary_search\
          ${BIN_DIR}/rectangle_overlap\
          ${BIN_DIR}/linked_list_palindrome\
          ${BIN_DIR}/binary_tree\
          ${BIN_DIR}/stack\
          ${BIN_DIR}/max_bst\
          ${BIN_DIR}/sort_wrt_another_array\
          ${OBJ_DIR}/merge_sort.o\
          ${OBJ_DIR}/binary_search.o\
          ${OBJ_DIR}/rectangle_overlap.o\
          ${OBJ_DIR}/linked_list_palindrome.o\
          ${OBJ_DIR}/binary_tree.o\
          ${OBJ_DIR}/stack.o\
          ${OBJ_DIR}/max_bst.o\
          ${OBJ_DIR}/sort_wrt_another_array.o

all: ${OBJECTS}
clean: ${OBJECTS};\
rm ${OBJECTS}

