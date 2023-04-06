#include <bits/stdc++.h>

int main() {
    std::string s;
    std::cin >> s;
	int count = 0;

    for ( char a = 'A'; a < 'Z'; ++a ){
		for( char b = a+1; b <= 'Z'; ++b ){
			int a_first = s.find_first_of(a);
			int a_last = s.find_last_of(a);
			int b_first = s.find_first_of(b);
			int b_last = s.find_last_of(b);

			if (a_first<b_first && b_first<a_last && a_last<b_last ) ++count;
			if (b_first<a_first && a_first<b_last && b_last<a_last ) ++count;
		}
	}

	std::cout << count << std::endl;
	
	return 0;
}