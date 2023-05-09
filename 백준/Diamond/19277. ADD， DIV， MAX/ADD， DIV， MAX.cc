#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse")
#include <bits/stdc++.h>
#define fastio std::ios_base::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

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

long long lazy1[800000];
long long lazy2[800000];
struct Node {
    long long max;
    long long min;
};

Node operator + (const Node& a, const Node& b) {
    Node ans;
    ans.max = std::max(a.max, b.max);
    ans.min = std::min(a.min, b.min);

    return ans;
}

inline long long myquotient(long long n, long long d){ return std::floor(n / static_cast<double>(d));}

inline void propagate(std::vector<Node>& tree, int idx, int s, int e) {
    if(lazy1[idx]== INT_MIN && lazy2[idx]==0) return;

    if(lazy1[idx] == INT_MIN){
        tree[idx].max += lazy2[idx];
        tree[idx].min += lazy2[idx];

        if(s != e){
            lazy2[idx << 1] += lazy2[idx];
            lazy2[(idx << 1) | 1] += lazy2[idx];
        }
    }else{
        tree[idx].max = (lazy1[idx] + lazy2[idx]);
        tree[idx].min = (lazy1[idx] + lazy2[idx]);

        if (s != e) {
            lazy1[idx << 1] = lazy1[idx];
            lazy1[(idx << 1) | 1] = lazy1[idx];
            lazy2[idx << 1] = lazy2[idx];
            lazy2[(idx << 1) | 1] = lazy2[idx];
        }
    }

    lazy1[idx] = INT_MIN;
    lazy2[idx] = 0;
    return;
}

long long get(std::vector<Node>& tree, int start_idx, int end_idx, int current_idx, int query_start, int query_end) {
    propagate(tree, current_idx, start_idx, end_idx);

    if(end_idx < query_start || query_end < start_idx) return 0;

    if (query_start <= start_idx && end_idx <= query_end) {
        return tree[current_idx].max;
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
        return std::max(left, right);
    }
}

Node init_node(std::vector<Node>& tree, std::vector<long long>& values, int start_idx, int end_idx, int current_idx) {
    if (start_idx == end_idx) {
        tree[current_idx].min = tree[current_idx].max = values[start_idx];
        return tree[current_idx];
    }

    int mid = (start_idx + end_idx) >> 1;
    auto left = init_node(tree, values, start_idx, mid, (current_idx << 1));
    auto right = init_node(tree, values, mid+1, end_idx, (current_idx << 1) | 1);
    tree[current_idx].max = std::max(left.max,right.max);
    tree[current_idx].min = std::min(left.min,right.min);
    return tree[current_idx];
}

void query_division(std::vector<Node>& tree, int start_idx, int end_idx, int current_idx, int query_start, int query_end, long long d) {
    propagate(tree, current_idx, start_idx, end_idx);

    if(end_idx < query_start || query_end < start_idx) return;
    
    if (query_start <= start_idx && end_idx <= query_end) {
        // 최소와 최대의 몫이 같으면 전부 같은값으로 변함
        if (myquotient(tree[current_idx].min, d) == myquotient(tree[current_idx].max, d)) {
            lazy1[current_idx] = myquotient(tree[current_idx].min, d);
            propagate(tree, current_idx, start_idx, end_idx);
            return;
        } else if(tree[current_idx].min + 1 == tree[current_idx].max){
        // 최소 + 1 == 최대인 경우 같은값만큼 빼주는거처럼 작용한다.
            lazy2[current_idx] = (myquotient(tree[current_idx].min, d) - tree[current_idx].min);
            propagate(tree, current_idx, start_idx, end_idx);
            return;
        }
    }
    int mid = (start_idx + end_idx) >> 1;
    query_division(tree, start_idx, mid, (current_idx << 1), query_start, query_end, d);
    query_division(tree, mid + 1, end_idx, (current_idx << 1) | 1, query_start, query_end, d);
    auto left = tree[current_idx << 1];
    auto right = tree[(current_idx << 1) | 1];

    tree[current_idx].max = std::max(left.max,right.max);
    tree[current_idx].min = std::min(left.min,right.min);

    return;
}

void query_offset(std::vector<Node>& tree, int start_idx, int end_idx, int current_idx, int query_start, int query_end, long long value) {
    propagate(tree, current_idx, start_idx, end_idx);
    
    if(end_idx < query_start || query_end < start_idx) return;

    if (query_start <= start_idx && end_idx <= query_end) {
        lazy2[current_idx] = value;
        propagate(tree, current_idx, start_idx, end_idx);
        return;
    }

    int mid = (start_idx + end_idx) >> 1;
    query_offset(tree, start_idx, mid, (current_idx << 1), query_start, query_end, value);
    query_offset(tree, mid + 1, end_idx, (current_idx << 1) | 1, query_start, query_end, value);
    auto left = tree[current_idx << 1];
    auto right = tree[(current_idx << 1) | 1];

    tree[current_idx].max = std::max(left.max,right.max);
    tree[current_idx].min = std::min(left.min,right.min);

    return;
}

int main(int argc, char* argv[]) {
#ifndef BOJ
    freopen(argv[1], "r", stdin);
#endif

    std::vector<Node> tree(800000, Node());
    std::vector<long long> values(200001);
    int i, N, Q, q, l, r, v;

    N = readInt();
    Q = readInt();
    std::fill(tree.begin(), tree.end(), Node());
    std::fill(lazy1, lazy1+800000, INT_MIN);
    memset( lazy2, 0, sizeof(lazy2));
    for(i = 1; i<=N; ++i){
        values[i] = readInt();
    }
    init_node(tree, values, 1, N, 1);
    
    while (Q--) {
        q = readInt();
        l = readInt() + 1;
        r = readInt() + 1;
        v = readInt();
        if(q==0){
            query_offset(tree, 1, N, 1, l, r, v);
        } else if(q==1){
            query_division(tree, 1, N, 1, l, r, v);
        } else if(q==2){
            writeInt(get(tree, 1, N, 1, l, r), '\n');
        }
    }
    Flusher();
    return 0;
}