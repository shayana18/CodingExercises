# Things to Rememeber for FSM

1. in FSM we have States (ENUM #1) and StateTransitions (Enum #2)
2. Event handling (ie changing states) is best to do in seperate functions, this keeps the code more readable, modular and scaleable. Making it more reusable for the future and easier to test
3. create a new event collection function (use atoi function to get an integer from a string)

# FAQ

1. Why do we not want to use pointers to memory addresses that?

Realistically we should use pointers because DMA is more efficent however with pointers and operating in a multi-core environment its important to implement thread safety which if you are not comfortable may be a reason to avoid writing a FSM with pointers