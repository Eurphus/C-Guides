/////////////////////////////
// (1) Pointer Basic Intro //
/////////////////////////////
void pointer_practice1(void) {
  int x = 10;
  int *px = &x; // Integer pointer px is the address of x
                // The integer px points to the address of x
                
  (*px)++; // Increment the value of px, aka increase the value where px points to by 1
  // *px++; // Notice that this increases the memory ADDRESS of px by 1, this is invalid
  // *(px)++ // I don't know what this is but it no worky
  
  printf("(1) x: %d\n", x);
  printf("(1) &x: %p\n", &x);
  printf("(1) *px: %d\n", *px);
  printf("(1) px: %p\n", px);
  printf("(1) &px: %p\n", &px); // It has it's own memory address that points to another!
  
  int y = *px; // Integer y is the value of where px points to
  int *z = &*px; // Integer z pointer to the address that px points to
                 // Equivalent to *z = px;
  int **double_pointer = &z;
  
  **double_pointer = 50;
  printf("(1) value of y: %d\n", y);
  printf("(1) address of y: %p\n", &y); // Notice address is different
  printf("(1) value of z: %d\n", *z);
  printf("(1) address of z: %p\n", z);
  printf("(1) **double_pointer: %d\n", **double_pointer);
  printf("(1) *double_pointer: %p\n", *double_pointer);
  printf("(1) double_pointer: %p\n", double_pointer);
  // double_pointer has a memory address which has a value, which when 
  // dereferenced (by *), aka the value of *double_pointer, is itself another
  // memory address. Notice this memory address is the memory address of our 
  // original x. 
  
  // This is why when the value of **double_pointer changed, so did the value
  // of our original x. They all point to the same spot in memory.
}

/////////////////////////////
// (2) Pointer Constants ////
/////////////////////////////
void pointer_practice2(void) {
  // int * --> Pointer to int
  // int const * == const int * --> pointer to const int
  // int * const --> const pointer to int
  // int const * const --> const pointer to const int
  
  // Before continuing, know that constants identifiers affect how things are modified from the address of the variable, not stuff down the pipeline.
  
  int normal_int = 5;
  int normal_int_2 = -67;
  const int const_int = 5;
  printf("(2) normal_int: %d\n", normal_int);
  printf("(2) &normal_int: %p\n", &normal_int);
  printf("(2) normal_int_2: %d\n", normal_int_2);
  printf("(2) &normal_int_2: %p\n", &normal_int_2);
  printf("(2) const_int: %d\n", const_int);
  printf("(2) &const_int: %p\n", &const_int);
  
  // Notice that both can point to a const or non-const variable
  // Const simply states you may not modify the int via *const_pointer
  const int *const_pointer = &normal_int;
  // (*const_pointer)++; // INVALID
  // const_pointer = (some other address) // VALID
  
  const int * const_pointer_2 = &const_int;
  // (*const_pointer)++; // INVALID
  // const_pointer = (some other address) // VALID
  
  normal_int = -9;
  printf("(2) normal_int = -9\n");
  
  // No way to edit the value const_pointer_2 currently points to, as it is 
  // also a const. The address however could be hanged.
  
  printf("(2) *const_pointer: %d\n", *const_pointer);
  printf("(2) const_pointer: %p\n", const_pointer); 
  printf("(2) *const_pointer_2: %d\n", *const_pointer_2);
  printf("(2) const_pointer_2: %p\n", const_pointer_2);
  printf("(2) const_pointer_2 -> address of normal_int_2\n");
  
  // Notice the value of the variable was able to change by editing the address! 
  const_pointer_2 = &normal_int_2;
  printf("(2) *const_pointer_2: %d\n", *const_pointer_2);
  printf("(2) const_pointer_2: %p\n", const_pointer_2);
  
  // But how can I make the address unable to be reassigned?
  int x = 5;
  int * const pointer_const = &x;
  // pointer_const = &normal_int; // INVALID it may not reassign the address
  // pointer_const = const_pointer // INVALID
  // (*pointer_const)++; // VALID
  x++;
  printf("(2) x: %d\n", x);
  printf("(2) &x: %p\n", &x);

  (*pointer_const)++; // We can still modify the value it points to itself!
  printf("(2) pointer_const: %d\n", *pointer_const);
  printf("(2) &pointer_const: %p\n", pointer_const);
  
  // How can I prevent the value and the address from being unable to be changed?
  int y = 1;
  const int z = -69;
  printf("(2) y: %d\n", y);
  printf("(2) &y: %p\n", &y);
  
  const int * const const_pointer_const = &y;
  // (*const_pointer_const)++ // INVALID can't change value
  y++; // The value it points to can still change
  
  // (*const_pointer_const)++; // INVALID
  // const_pointer_const = &z; // INVALID
  
  printf("(2) const_pointer_const: %d\n", *const_pointer_const);
  printf("(2) &const_pointer_const: %p\n", const_pointer_const);

  // int const * const const_pointer_const_2 = &y is also valid
  int const * const const_pointer_const_2 = &z; // const pointer to const integer
  y++;
  printf("(2) const_pointer_const_2: %d\n", *const_pointer_const_2);
  printf("(2) &const_pointer_const_2: %p\n", const_pointer_const_2);
  // Notice the first const position does not matter or change the function!

  
  // Prevent a double pointer from changing at all?
  const int *const *const const_pointer_const_pointer_const = &const_pointer_const;
  printf("(2) &const_pointer_const_pointer_const: %p\n", &const_pointer_const_pointer_const);
  printf("(2) const_pointer_const_pointer_const: %p\n", const_pointer_const_pointer_const);
  printf("(2) *const_pointer_const_pointer_const: %p\n", *const_pointer_const_pointer_const);
  printf("(2) **const_pointer_const_pointer_const: %d\n", **const_pointer_const_pointer_const);
}

////////////////
// (3) Arrays //
////////////////
void pointer_practice3(void) {
  int arr[5] = {10, 2, 30, 4, 50};
  int arr_len = 5;
  
  // Notice that arr itself is literally just a memory address. That memory
  // address is the first element in the arr.
  // How we get to other elements from that memory address is what matters
  printf("(3) arr + arr_len: %p\n", arr + arr_len); // This address has no value associated with it
  printf("(3) arr + arr_len - 1: %p\n", arr + arr_len - 1);
  printf("(3) *(arr + arr_len - 1): %d\n", *(arr + arr_len - 1)); // Last element
  printf("(3) *arr: %d\n", *arr); // First element
  printf("(3) arr: %p\n", arr);
  
  for (int i = 0; i < arr_len; ++i) {
    // Note that (mem address) + 1 is wacky, but it works for arrays to get to the next element
    printf("      arr[%d] = %d = %d\n", i, arr[i], *(arr + i));
    printf("      &arr[%d] = %p = %p\n", i, &arr[i], arr + i);
  }
  
  printf("(3) Repeating arr using 2nd method\n");
  int index;
  // arr + arr_len is useful here, as we are telling it not to be equal to it or go past it
  for (int *element = arr; element < arr + arr_len; ++element) {
    // For some reason %ld was required instead of %d
    // The result of element - arr has a long type, so you cannot print it directly with %d, keep this in mind.
    int index = element - arr;
    printf("      arr[%d] = %d\n", index, *element);
    printf("      &arr[%ld] = %p\n", element - arr, element);
  }
  
  // Want to count backwards?
  /*
  for (int *element = arr + arr_len - 1; element >= arr; --element) {
    int index = element - arr;
    printf("      arr[%d] = %d\n", index, *element);
    printf("      &arr[%ld] = %p\n", element - arr, element);
  }
  */
  
  assert(arr + arr_len); // Notice this still passes! No value exists there though
  // It's a valid memory address, but I don't how to modify anything about it. Is cool.
}

int main(void) {
  int select;
  while (scanf("%d ", &select) == 1) {
    if (select == 1) {
      pointer_practice1();
    } else if (select == 2) {
      pointer_practice2();
    } else if (select == 3) {
      pointer_practice3();
    }
    printf("\n\n\n");
  }
}
