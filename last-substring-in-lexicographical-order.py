class Solution:
    def lastSubstring(self, s: str) -> str:
        current = ord(s[0])
        max_idx = 0
        consecutive_length = 1
        max_substring = []
        challenge = 0
        for i in range(1, len(s)):
            print(f"idx: {i}")
            # print(max_substring)
            if ord(s[i]) > current:
                print(i, s[i])
                current, max_idx = ord(s[i]), i
                consecutive_length = 1
            elif ord(s[i]) < current:
                print(s[i])
                if challenge == 0:
                    consecutive_length += 1                    
                    max_substring = s[max_idx : max_idx + consecutive_length + 1]
                    print(f"max_substr: {max_substring}, {consecutive_length}")
                else:
                    print(f"consecutive: {consecutive_length}")
                    challenge = 0
                    for l in range(consecutive_length):
                        # print(f"i: {i}, l:{l}, {consecutive_length} ")
                        if ord(s[i+l-1]) < ord(max_substring[l-1]):
                            consecutive_length += 1
                            max_substring += s[i]
                            break
                        if l == consecutive_length - 1:    
                            max_substring = s[i-1: i+consecutive_length-1]
                            print(max_substring)
        
            else:
                print(f"idx:{i} Decide whether to challenge...")
                if i < len(s) - consecutive_length + 1:
                    print("Challenge")
                    challenge = 1     
                else:
                    print("No need to challenge.")
                    consecutive_length += 1
                    max_substring = s[max_idx: max_idx+consecutive_length+1]

                
            # elif ord(s[i]) == current:
            #     if i != len(s) - 1:
                    
        return max_substring
            
