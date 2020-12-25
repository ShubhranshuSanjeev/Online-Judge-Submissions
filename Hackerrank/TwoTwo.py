#!/bin/python3

import os
import sys

class Vertex:
    def __init__(self):
        self.is_leaf = False
        self.link = -1
        self.match_fail = 0
        self.match_count = 0
        self.next = {}


def construct_trie():
    curr_val = 0
    trie = [Vertex(), Vertex()]
    print(trie, curr_val)
    for i in range(0, 801):
        if i == 0:
            curr_val = 1
        else:
            curr_val *= 2

        str_val = str(curr_val)
        node = 1
        for c in str_val:
            if trie[node].next.get(c, -1) == -1:
                trie[node].next[c] = len(trie)
                trie.append(Vertex())
            node = trie[node].next[c]

        trie[node].match_count+=1
        trie[node].is_leaf = True

    return trie

def construct_fail_links(trie):
    trie[1].link = 0
    q = [1]

    while len(q):
        curr = q[0]
        q.pop(0)

        for k, v in trie[curr].next.items():
            ch = k
            nxt = v
            suff = trie[curr].link
            while suff and trie[suff].next.get(ch, -1) == -1:
                suff = trie[suff].link
            suff = trie[suff].next[ch] if suff else 1

            trie[nxt].link = suff
            trie[nxt].match_fail = suff if trie[suff].is_leaf else trie[suff].match_fail

            q.append(nxt)

def search(s, trie):
    node = 1
    length = len(s);
    occ_count = 0;

    for i in range(length):
        while node and trie[node].next.get(s[i], -1) == -1:
            node = trie[node].link;
        node = trie[node].next[s[i]] if node else 1;
        v = node
        while v:
            print(v)
            if trie[v].is_leaf:
                occ_count += trie[v].match_count
            v = trie[v].match_fail

    return occ_count

# fptr = open(os.environ['OUTPUT_PATH'], 'w')
T = int(input().strip())
trie = construct_trie()
construct_fail_links(trie)
for _ in range(T):
    string = input().strip()
    
    result = search(string, trie)
    print(result)
    # fptr.write(str(result) + '\n')

#fptr.close()
