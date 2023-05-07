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

int main(int argc, char* argv[]) {
#ifndef BOJ
    freopen(argv[1], "r", stdin);
#endif
    int N = readInt();
    int K = readInt();
    int ans = 1;
    for (int i = 2; i <= N; i++)
		ans = (ans + K - 1) % i + 1;
	writeInt(ans, '\n');
    Flusher();
    return 0;
}