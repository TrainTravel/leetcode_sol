class Solution:
    def shortestWay(self, source: str, target: str) -> int:
        ti, si = 0, 0
        char_found = False
        subseq_cnt = 0

        while ti < len(target):
            # check the source string to see if it contains the next character in target
            # for si in range(len(source)):

            char_found = False
            # go through the source string to see:
            #    1. if target[ti] exists in source
            #    2. or even better, what subsequence it gives
            for si in range(len(source)):

                # when target string is longer than source string
                if ti >= len(target):
                    return subseq_cnt + 1

                # print(f"si = {si}, ti = {ti}")
                if target[ti] == source[si]:
                    # print(f"found: {source[si]} = {target[ti]}\n")
                    char_found = True
                    ti += 1
                si += 1

            # source string doesn't contain the next character in target, return early
            if not char_found:
                return -1
            subseq_cnt += 1
        return subseq_cnt
