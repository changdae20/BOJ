#include <iostream>
template <unsigned long long N>
struct Fibo {
    static const unsigned long long result = Fibo<N - 1>::result + Fibo<N - 2>::result;
};

template <>
struct Fibo<1uLL> {
  static const unsigned long long result = 1uLL;
};

template <>
struct Fibo<0uLL> {
  static const unsigned long long result = 0uLL;
};

int main() {
    unsigned long long arr[91] = {
		Fibo<0uLL>::result,
		Fibo<1uLL>::result,
		Fibo<2uLL>::result,
		Fibo<3uLL>::result,
		Fibo<4uLL>::result,
		Fibo<5uLL>::result,
		Fibo<6uLL>::result,
		Fibo<7uLL>::result,
		Fibo<8uLL>::result,
		Fibo<9uLL>::result,
		Fibo<10uLL>::result,
		Fibo<11uLL>::result,
		Fibo<12uLL>::result,
		Fibo<13uLL>::result,
		Fibo<14uLL>::result,
		Fibo<15uLL>::result,
		Fibo<16uLL>::result,
		Fibo<17uLL>::result,
		Fibo<18uLL>::result,
		Fibo<19uLL>::result,
		Fibo<20uLL>::result,
		Fibo<21uLL>::result,
		Fibo<22uLL>::result,
		Fibo<23uLL>::result,
		Fibo<24uLL>::result,
		Fibo<25uLL>::result,
		Fibo<26uLL>::result,
		Fibo<27uLL>::result,
		Fibo<28uLL>::result,
		Fibo<29uLL>::result,
		Fibo<30uLL>::result,
		Fibo<31uLL>::result,
		Fibo<32uLL>::result,
		Fibo<33uLL>::result,
		Fibo<34uLL>::result,
		Fibo<35uLL>::result,
		Fibo<36uLL>::result,
		Fibo<37uLL>::result,
		Fibo<38uLL>::result,
		Fibo<39uLL>::result,
		Fibo<40uLL>::result,
		Fibo<41uLL>::result,
		Fibo<42uLL>::result,
		Fibo<43uLL>::result,
		Fibo<44uLL>::result,
		Fibo<45uLL>::result,
		Fibo<46uLL>::result,
		Fibo<47uLL>::result,
		Fibo<48uLL>::result,
		Fibo<49uLL>::result,
		Fibo<50uLL>::result,
		Fibo<51uLL>::result,
		Fibo<52uLL>::result,
		Fibo<53uLL>::result,
		Fibo<54uLL>::result,
		Fibo<55uLL>::result,
		Fibo<56uLL>::result,
		Fibo<57uLL>::result,
		Fibo<58uLL>::result,
		Fibo<59uLL>::result,
		Fibo<60uLL>::result,
		Fibo<61uLL>::result,
		Fibo<62uLL>::result,
		Fibo<63uLL>::result,
		Fibo<64uLL>::result,
		Fibo<65uLL>::result,
		Fibo<66uLL>::result,
		Fibo<67uLL>::result,
		Fibo<68uLL>::result,
		Fibo<69uLL>::result,
		Fibo<70uLL>::result,
		Fibo<71uLL>::result,
		Fibo<72uLL>::result,
		Fibo<73uLL>::result,
		Fibo<74uLL>::result,
		Fibo<75uLL>::result,
		Fibo<76uLL>::result,
		Fibo<77uLL>::result,
		Fibo<78uLL>::result,
		Fibo<79uLL>::result,
		Fibo<80uLL>::result,
		Fibo<81uLL>::result,
		Fibo<82uLL>::result,
		Fibo<83uLL>::result,
		Fibo<84uLL>::result,
		Fibo<85uLL>::result,
		Fibo<86uLL>::result,
		Fibo<87uLL>::result,
		Fibo<88uLL>::result,
		Fibo<89uLL>::result,
		Fibo<90uLL>::result
    };
    std::size_t N;
    std::cin >> N;
    std::cout << arr[N] << std::endl;
    return 0;
}