#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

int Get_dozen(int num){
// for (int i = 1; i < 10; i++) {
//     if (num < 10*i)
//         return i - 1;
// }

    if (num < 10){
        return 0;
    }    

    if (num - 10 < 10){
        return 1;
    }

    if (num - 20 < 10){
        return 2;
    }

    if (num - 30 < 10){
        return 3;
    }
    if (num - 40 < 10){
        return 4;
    }
    if (num - 50 < 10){
        return 5;
    }
    if (num - 60 < 10){
        return 6;
    }
    if (num - 70 < 10){
        return 7;
    }
    if (num - 80 < 10){
        return 8;
    }
    return 9;
}

std::vector<std::vector<int>> GetResults(std::vector<std::vector<int>>& nearly_results){
    //int dozen = 0;
    int index = 0;
    for (std::vector<int>& result : nearly_results){

        int dozen = 0;
        for (int& num : result){
            num += dozen;
            dozen = Get_dozen(num);
            num = num - (dozen * 10);
        }

        result.push_back(dozen);
        for (int i=0; i != index; i++){
            result.insert(result.begin(), 0);
        }
        index++;
    }
    return nearly_results;
}


std::vector<int> Input(){
    std::vector<int> num1;
    std::string str_num;

    std::cin >> str_num;

    for (char c : str_num){
        int num = c - 48;
        num1.push_back(num);
    }    

    return num1;
}

std::vector<int> Addition(std::vector<std::vector<int>>& numbers){
    auto longest_num = std::max_element(std::begin(numbers), std::end(numbers), [](const auto& a, const auto& b){return a.size() < b.size();});
    int longest_num_length = (*longest_num).size();
    
    std::vector<int> answer;
    int i = 0;
    unsigned long int long_i = 0;
    int result;
    int dozens = 0;
    int units;
    while (i < longest_num_length)
    {
        result = 0;
        for (std::vector<int>& num : numbers){
            if (num.size() > long_i){
                result += num[i];
            }
        }
        result += dozens;
        dozens = Get_dozen(result);
        units = result - (dozens * 10);
        answer.push_back(units);
        i++;
        long_i++;
    }

    return answer;
}



std::vector<int> Calc(std::vector<int>& num1, std::vector<int>& num2){
    std::vector<std::vector<int>> nearly_results;

    std::reverse(num1.begin(), num1.end());
    std::reverse(num2.begin(), num2.end());

    int dozens = 0;
    int units = 0;
    int result = 0;
    int i = 0;
    for (int n1 : num1){
        nearly_results.push_back(std::vector<int>());
        for (int n2 : num2){
            result = n1 * n2;
            nearly_results[nearly_results.size()-1].push_back(result);
            
        }
        nearly_results[i].push_back(dozens);
        i ++;
    }
    std::vector<std::vector<int>> answer = GetResults(nearly_results);
    return Addition(answer);

}


int main(){

    std::vector<int> num1 = Input();
    std::vector<int> num2 = Input();


    std::vector<int> result = Calc(num1, num2);

    std::reverse(result.begin(), result.end());
    std::string s;
    for (int num : result){
        printf("%d", num);
    }
    printf("\n");



}
