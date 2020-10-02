def wildcard(pattern, word):
    len_p, len_w = len(pattern), len(word)
    cache = [[-1 for _ in range(len_w+1)] for _ in range(len_p+1)]

    def match(nth_p, nth_w):
        if cache[nth_p][nth_w] != -1:
            return cache[nth_p][nth_w]

        if nth_p < len_p and nth_w < len_w and (pattern[nth_p] == '?' or pattern[nth_p] ==
                                                word[nth_w]):
            cache[nth_p][nth_w] = match(nth_p+1, nth_w+1)
            return cache[nth_p][nth_w]

        if nth_p == len_p:
            return nth_w == len_w

        if pattern[nth_p] == '*':
            if match(nth_p+1, nth_w) or (nth_w < len_w and match(nth_p, nth_w+1)):
                cache[nth_p][nth_w] = True
                return True

        cache[nth_p][nth_w] = False
        return False

    return match(0, 0)