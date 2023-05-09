#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse")
#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

unsigned int lazy1[808080];
unsigned int lazy2[808080];

inline int readChar();
template <class T = int>
inline T readInt();
template <class T>
inline void writeInt(T x, char end = 0);
inline void writeChar(int x);
inline void writeWord(const char *s);
constexpr static int BUF_SIZE = 1 << 17;
inline int getChar(){
    static char buf[BUF_SIZE];
    static int len = 0, pos = 0;
    if (pos == len) {
        pos = 0, len = fread(buf, 1, BUF_SIZE, stdin);
    }
    if (pos == len) {
        return -1;
    }
    return buf[pos++];
}

inline int readChar(){
    int c = getChar();
    while (c <= 32) {
        c = getChar();
    }
    return c;
}

template <class T>
inline T readInt(){
    int s = 1, c = readChar();
    T x = 0;
    if (c == '-') {
        s = -1;
        c = getChar();
    }

    while ('0' <= c && c <= '9') {
        x = x * 10 + c - '0';
        c = getChar();
    }

    return s == 1 ? x : -x;
}

static int writePos = 0;
static char writeBuf[BUF_SIZE];
inline void writeChar(int x){
    if (writePos == BUF_SIZE) {
        fwrite(writeBuf, 1, BUF_SIZE, stdout);
        writePos = 0;
    }
    writeBuf[writePos++] = x;
}

template <class T>
inline void writeInt(T x, char end){
    if (x < 0) {
        writeChar('-');
        x = -x;
    }
    char s[24];
    int n = 0;
    while (x || !n) {
        s[n++] = '0' + x % 10;
        x /= 10;
    }

    while (n--) {
        writeChar(s[n]);
    }

    if (end) {
        writeChar(end);
    }
}

inline void writeWord(const char *s){
    while (*s) {
        writeChar(*s++);
    }
}

struct Flusher{
    ~Flusher() {
        if (writePos) {
            fwrite(writeBuf, 1, writePos, stdout);
            writePos = 0;
        }
    }
} flusher;

struct Node {
    unsigned int max;
    unsigned int _and;
    unsigned int _or;
};

Node operator + (Node& a, Node& b) {
    Node ans;
    ans.max = std::max<>(a.max, b.max);
    ans._and = a._and & b._and;
    ans._or = a._or | b._or;
 
    return ans;
}

void propagate(std::vector<Node>& tree, int idx, int s, int e) {
    if(lazy1[idx]==0 && lazy2[idx]==0) return;
    if (s != e) {
        for(auto& c : {idx << 1, (idx << 1)|1}){
            auto _and = lazy1[idx];
            auto _or = lazy2[idx];
            auto orig_first = lazy1[c];
            auto orig_second = lazy2[c];
            lazy1[c] = (lazy1[c] ^ _or) & lazy1[c];
            lazy2[c] = (lazy2[c] ^ _and) & lazy2[c];
            _or ^= (orig_first ^ lazy1[c]);
            _and ^= (orig_second ^ lazy2[c]);
            lazy1[c] |= _and;
            lazy2[c] |= _or;
        }
    }
    return;
}

Node get(std::vector<Node>& tree, int start_idx, int end_idx, int current_idx, int query_start, int query_end) {
    if (lazy1[current_idx] || lazy2[current_idx]) {
        tree[current_idx].max -= lazy1[current_idx];
        tree[current_idx].max += lazy2[current_idx];
        tree[current_idx]._and |= lazy2[current_idx];
        tree[current_idx]._or |= lazy2[current_idx];
        tree[current_idx]._and = (tree[current_idx]._and ^ lazy1[current_idx]) & tree[current_idx]._and;
        tree[current_idx]._or = (tree[current_idx]._or ^ lazy1[current_idx]) & tree[current_idx]._or;
        
        propagate(tree, current_idx, start_idx, end_idx);
        lazy1[current_idx] = 0u;
        lazy2[current_idx] = 0u;
    }

    if (start_idx == query_start && end_idx == query_end) {
        return tree[current_idx];
    }

    int mid = (start_idx + end_idx) >> 1;
    if (query_end <= mid) {
        return get(tree, start_idx, mid, current_idx << 1, query_start, query_end);
    }
    else if (mid + 1 <= query_start) {
        return get(tree, mid + 1, end_idx, (current_idx << 1) | 1, query_start, query_end);
    }
    else {
        auto left = get(tree, start_idx, mid, current_idx << 1, query_start, mid);
        auto right = get(tree, mid + 1, end_idx, (current_idx << 1) | 1, mid + 1, query_end);
        return left + right;
    }
}

void init_node(std::vector<Node>& tree, std::vector<unsigned int>& arr, int current_idx, int start_idx, int end_idx) {
    if (start_idx == end_idx) {
        tree[current_idx] = Node{ arr[start_idx], arr[start_idx], arr[start_idx] };
        return;
    }

    int mid = (start_idx + end_idx) >> 1;
    init_node(tree, arr, current_idx << 1, start_idx, mid);
    init_node(tree, arr, (current_idx << 1) | 1, mid+1, end_idx);
    tree[current_idx] = tree[current_idx << 1] + tree[(current_idx << 1) | 1];
    return;
}

// offset bit를 0으로 만든다
void query_and(std::vector<Node>& tree, int start_idx, int end_idx, int current_idx, int query_start, int query_end, unsigned int offset) {
    if (lazy1[current_idx] || lazy2[current_idx]) {
        tree[current_idx].max -= lazy1[current_idx];
        tree[current_idx].max += lazy2[current_idx];
        tree[current_idx]._and |= lazy2[current_idx];
        tree[current_idx]._or |= lazy2[current_idx];
        tree[current_idx]._and = (tree[current_idx]._and ^ lazy1[current_idx]) & tree[current_idx]._and;
        tree[current_idx]._or = (tree[current_idx]._or ^ lazy1[current_idx]) & tree[current_idx]._or;
        
        propagate(tree, current_idx, start_idx, end_idx);
        lazy1[current_idx]= 0u;
        lazy2[current_idx] = 0u;
    }
    
    if (start_idx == query_start && end_idx == query_end) {
        // 해당 구간의 offset bit가 모두 이미 0이었다면 그냥 return
        if(!(tree[current_idx]._or & (1<<offset))) return;
        // 해당 구간이 모두 1이었다면 0으로 만든다. -> 해당 구간의 _and의 offset이 1인지 체크
        if(tree[current_idx]._and & (1<<offset)){
            lazy1[current_idx] |= (1 << offset);
            return;
        }
    }
    int mid = (start_idx + end_idx) / 2;
    if (query_end <= mid) {
        query_and(tree, start_idx, mid, current_idx << 1, query_start, query_end, offset);
    }
    else if (mid + 1 <= query_start) {
        query_and(tree, mid + 1, end_idx, (current_idx << 1) | 1, query_start, query_end, offset);
    }
    else {
        query_and(tree, start_idx, mid, current_idx << 1, query_start, mid, offset);
        query_and(tree, mid + 1, end_idx, (current_idx << 1) | 1, mid + 1, query_end, offset);
    }
    auto left = get(tree, start_idx, mid, current_idx << 1, start_idx, mid);
    auto right = get(tree, mid + 1, end_idx, (current_idx << 1) | 1, mid + 1, end_idx);

    tree[current_idx] = left + right;
    return;
}

// offset비트를 전부 1로 만든다.
void query_or(std::vector<Node>& tree, int start_idx, int end_idx, int current_idx, int query_start, int query_end, unsigned int offset) {
    if (lazy1[current_idx] || lazy2[current_idx]) {
        tree[current_idx].max -= lazy1[current_idx];
        tree[current_idx].max += lazy2[current_idx];
        tree[current_idx]._and |= lazy2[current_idx];
        tree[current_idx]._or |= lazy2[current_idx];
        tree[current_idx]._and = (tree[current_idx]._and ^ lazy1[current_idx]) & tree[current_idx]._and;
        tree[current_idx]._or = (tree[current_idx]._or ^ lazy1[current_idx]) & tree[current_idx]._or;
        
        propagate(tree, current_idx, start_idx, end_idx);
        lazy1[current_idx] = 0u;
        lazy2[current_idx] = 0u;
    }
    
    if (start_idx == query_start && end_idx == query_end) {
        // 해당 구간의 offset bit가 모두 이미 1이었다면 그냥 return
        if(tree[current_idx]._and & (1 << offset)) return;
        // 해당 구간이 모두 0이었다면 1로 만든다. -> 해당 구간의 _or의 offset이 0인지 체크
        if(!(tree[current_idx]._or & (1 << offset))){
            lazy2[current_idx] |= (1 << offset);
            return;
        }
    }
    int mid = (start_idx + end_idx) >> 1;
    if (query_end <= mid) {
        query_or(tree, start_idx, mid, current_idx << 1, query_start, query_end, offset);
    }
    else if (mid + 1 <= query_start) {
        query_or(tree, mid + 1, end_idx, (current_idx << 1) | 1, query_start, query_end, offset);
    }
    else {
        query_or(tree, start_idx, mid, current_idx << 1, query_start, mid, offset);
        query_or(tree, mid + 1, end_idx, (current_idx << 1) | 1, mid + 1, query_end, offset);
    }
    auto left = get(tree, start_idx, mid, current_idx << 1, start_idx, mid);
    auto right = get(tree, mid + 1, end_idx, (current_idx << 1) | 1, mid + 1, end_idx);

    tree[current_idx] = left + right;
    return;
}

int main(int argc, char* argv[]) {
#ifndef BOJ
    freopen(argv[1], "r", stdin);
#endif
    fastio;

    int N = readInt();
    std::vector<Node> tree(4 * N, Node());
    std::vector<unsigned int> arr(N+1);
    memset(lazy1, 0, sizeof(lazy1));
    memset(lazy2, 0, sizeof(lazy2));
    for (int i = 1; i <= N; ++i) {
        arr[i] = readInt();
    }

    init_node(tree,arr,1,1,N);

    int Q = readInt();
    int q;
    unsigned int l, r, v;
    while (Q--) {
        q = readInt();
        l = readInt();
        r = readInt();
        if(q==1){
            v = readInt();
            for(int i=0; i<20; ++i){
                if(!(v & (1 << i))){
                    query_and(tree, 1, N, 1, l, r, i);
                }
            }
        } else if(q == 2){
            v = readInt();
            unsigned int i=0;
            while(v){
                if(v&1){
                    query_or(tree,1,N,1,l,r,i);
                }
                v >>= 1;
                ++i;
            }
        } else{
            writeInt(get(tree,1,N,1,l,r).max, '\n');
        }
    }
    Flusher();
    return 0;
}