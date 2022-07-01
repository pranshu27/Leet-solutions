    /*
    two possible cases
    
stack is not empty - If stack is not empty, then this may be our longest valid parentheses. We update the MAX_len as max(MAX_len, current index - stack.top()). Do notice, that our bottom of stack will always hold index preceding to a potential valid parentheses.
    
stack becomes empty - This will only happen when we have an extra ')' bracket. There may have been valid parentheses previously which have been updated and stored in MAX_len. But, since we now have an extra closing bracket any further extensions of previous valid parentheses is not possible. So, push the current index into stack, again which will denote that bottom of stack will hold the index preceding to a potential valid parentheses.
    
    */
