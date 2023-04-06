#include <iostream>
#include <vector>
#include <algorithm>
#include <regex>
#include <string>
#include <numeric>

class Matrix{ // class for square matrix
    public:
        int size;
        std::vector<std::vector<unsigned long long>> matrix;

        Matrix(){
            matrix = std::vector<std::vector<unsigned long long>>();
            size = 0;
        }
        Matrix(int size){
            matrix = std::vector<std::vector<unsigned long long>>(size, std::vector<unsigned long long>(size, 0));
            this->size = size;
        }
        Matrix(std::vector<std::vector<unsigned long long>> matrix){
            this->matrix = matrix;
            this->size = matrix.size();
        }

        Matrix operator*(Matrix& other){
            std::vector<std::vector<unsigned long long>> result;
            for(int i = 0; i < matrix.size(); i++){
                std::vector<unsigned long long> row;
                for(int j = 0; j < other.matrix[0].size(); j++){
                    unsigned long long sum = 0;
                    for(int k = 0; k < matrix[0].size(); k++){
                        sum += (matrix[i][k] * other.matrix[k][j])%1000;
                        sum %= 1000;
                    }
                    row.push_back(sum);
                }
                result.push_back(row);
            }
            return Matrix(result);
        }

        Matrix operator+(const Matrix& other) const{
            std::vector<std::vector<unsigned long long>> result;
            for(int i = 0; i < matrix.size(); i++){
                std::vector<unsigned long long> row;
                for(int j = 0; j < matrix[0].size(); j++){
                    row.push_back( (matrix[i][j] + other.matrix[i][j]) % 1000);
                }
                result.push_back(row);
            }
            return Matrix(result);
        }

        // ++operator overloading : add unit matrix
        Matrix& operator++(int){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][i] += 1;
            }
            return *this;
        }

        std::vector<unsigned long long>& operator[](int index){
            return matrix[index];
        }

        friend std::istream &operator>>(std::istream &is, Matrix &matrix){
            matrix.matrix = std::vector<std::vector<unsigned long long>>(0, std::vector<unsigned long long>(0, 0));
            unsigned long long a;
            for(int i = 0; i < matrix.size; i++){
                std::vector<unsigned long long> row;
                for(int j = 0; j < matrix.size; j++){
                    is >> a;
                    row.push_back(a%1000);
                }
                matrix.matrix.push_back(row);
            }
            return is;
        }

        friend std::ostream &operator<<(std::ostream &os, Matrix &matrix){
            for( auto &row : matrix.matrix){
                for(auto it = row.begin(); it!=row.end(); ++it){
                    if(it!=row.begin()) std::cout << " ";
                    std::cout << *it;
                } 
                std::cout << std::endl;
            }
            return os;
        }

        Matrix& operator=(const Matrix& other){
            if(this != &other){
                matrix = other.matrix;
                size = other.size;
            }
            return *this;
        }
};

Matrix power(Matrix& matrix, unsigned long long n){
    if(n == 1){
        return matrix;
    }
    Matrix result = power(matrix, n / 2);
    result = result * result;
    if(n % 2 == 1){
        result = result * matrix;
    }
    return result;
}

Matrix ans(Matrix& matrix, unsigned long long n){ // sum of power of matrix
    if(n == 1){
        return matrix;
    }
    if(n % 2 == 1){
        return ans(matrix, n-1) + power(matrix, n);
    }else{
        Matrix result = ans(matrix, n/2);
        Matrix temp = power(matrix, n/2);
        temp++;
        return result * temp ;
    }
}

int main(){
    unsigned long long n,m;
    std::cin >> n >> m;
    Matrix matrix(n);
    std::cin >> matrix;

    auto ans_ = ans(matrix, m);
    std::cout << ans_;
    return 0;
}