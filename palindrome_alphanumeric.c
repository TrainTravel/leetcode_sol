/*
Runtime: 0 ms, faster than 100.00% of C online submissions for Valid Palindrome.
Memory Usage: 6 MB, less than 100.00% of C online submissions for Valid Palindrome.
*/
bool isPalindrome(char * s){
    int length = strlen(s);
    int new_length = 0;
    char *new_s, *track;
    track = s;
    new_s = (char *)malloc(length * sizeof(char));
    char *track_new = new_s;

    int position = 0;
    if(*s == '\0')
        return true;
    while(*track != '\0')
    {
        // printf("%d\n", position);
        // to lower case
        if(*track > 64 && *track < 91)
        {
            *track += 32;
            new_length++;
            *new_s = *track;
            // printf("track: %c\n", *new_s);
            new_s++;
        }
        else if(*track > 96 && *track < 123)
        {
            new_length++;
            *new_s = *track;
            // printf("track: %c\n", *new_s);
            new_s++;
        }
        else if(*track >= '0' && *track <= '9')
        {
            new_length++;
            *new_s = *track;
            // printf("track: %c\n", *new_s);
            new_s++;
        }
        track++;
    }
    // printf("End of tracking original string.\nNew string length is %d.\n", new_length);    

    char *front_ptr, *end_ptr;
    if(new_length > 0)
    {
        front_ptr = &track_new[0];
        end_ptr = &track_new[new_length-1];
    }
    else
        return true;

    while(*front_ptr == *end_ptr)
    {   
        // printf("%c is the same.\n", *front_ptr);
        if(new_length == 1)
            return true;
        else
        {
            front_ptr++;
            end_ptr--;
            if(front_ptr >= end_ptr) return true;
        }
    }
    return false;
}

